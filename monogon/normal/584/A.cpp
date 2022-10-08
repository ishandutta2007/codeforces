#include <iostream>

int n, t;

int main() {
	std::cin >> n >> t;
	if(n == 1)
		std::cout << (t == 10 ? -1 : t);
	else if(t != 10){
		std::cout << t;
		for(int i = 0; i < n - 1; i++)
			std::cout << 0;
	}else {
		std::cout << 1;
		for(int i = 0; i < n - 1; i++)
			std::cout << 0;
	}
}