#include <iostream>

int N;
int round = 1;
int count = 0;

int main() {
	std::cin >> N;
	N--;
	for(int i = 0; i < N; i += round) {
		count++;
		if(count == 5) {
			count = 0;
			round *= 2;
		}
	}
	switch(count) {
	case 0:
		std::cout << "Sheldon\n";
		break;
	case 1:
		std::cout << "Leonard\n";
		break;
	case 2:
		std::cout << "Penny\n";
		break;
	case 3:
		std::cout << "Rajesh\n";
		break;
	case 4:
		std::cout << "Howard\n";
		break;
	}
}