// homework-3-1-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <variant>

std::variant<int, std::string, std::vector<int>> get_variant() {
	std::srand(std::time(nullptr));
	int random_variable = std::rand() % 3;

	std::variant<int, std::string, std::vector<int>> result;
	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = std::vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}
	return result;
}

int main()
{
	setlocale(LC_ALL, "Rus");

	std::variant<int, std::string, std::vector<int>> result = get_variant();

	if ((std::holds_alternative<std::string>(result)) ) {
		std::cout << "Строка: " << std::get<std::string>(result) << std::endl;
	}
	if ((std::holds_alternative<int>(result)) ) {
		std::cout << "Целое число: " << (std::get<int>(result)) * 2 << std::endl;
	}
	if ((std::holds_alternative<std::vector<int>>(result)) ) {
		std::vector<int> v = std::get<std::vector<int>>(result);
		std::cout << "Вектор: ";
		std::for_each(v.begin(), v.end(), [](const int v) { std::cout << v << ' '; });
	}

	return 0;
}
