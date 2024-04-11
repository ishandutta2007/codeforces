#include <iostream>
#include <set>

std::set<int> shoes;
int a;

int main() {
	for(int i = 0; i < 4; i++) {
		std::cin >> a;
		shoes.insert(a);
	}
	std::cout << 4 - shoes.size();
}