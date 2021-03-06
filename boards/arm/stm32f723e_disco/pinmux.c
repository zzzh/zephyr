/*
 * Copyright (c) 2018 Aurelien Jarno
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <kernel.h>
#include <device.h>
#include <init.h>
#include <pinmux.h>
#include <sys_io.h>

#include <pinmux/stm32/pinmux_stm32.h>

/* pin assignments for STM32F723E-DISCO board */
static const struct pin_config pinconf[] = {
#ifdef CONFIG_UART_STM32_PORT_2
	{STM32_PIN_PA2, STM32F7_PINMUX_FUNC_PA2_USART2_TX},
	{STM32_PIN_PA3, STM32F7_PINMUX_FUNC_PA3_USART2_RX},
#endif	/* CONFIG_UART_STM32_PORT_2 */
#ifdef CONFIG_UART_STM32_PORT_6
	{STM32_PIN_PC6, STM32F7_PINMUX_FUNC_PC6_USART6_TX},
	{STM32_PIN_PC7, STM32F7_PINMUX_FUNC_PC7_USART6_RX},
#endif	/* CONFIG_UART_STM32_PORT_6 */
};

static int pinmux_stm32_init(struct device *port)
{
	ARG_UNUSED(port);

	stm32_setup_pins(pinconf, ARRAY_SIZE(pinconf));

	return 0;
}

SYS_INIT(pinmux_stm32_init, PRE_KERNEL_1,
		CONFIG_PINMUX_STM32_DEVICE_INITIALIZATION_PRIORITY);
