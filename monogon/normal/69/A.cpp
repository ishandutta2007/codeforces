#include <iostream>

int x, y, z;
int a, b, c;
int N;

int main() {
	std::cin >> N;
	for(int i = 0; i < N; i++) {
		std::cin >> a >> b >> c;
		x += a;
		y += b;
		z += c;
	}
	if(x == 0 && y == 0 && z == 0)
		std::cout << "YES\n";
	else
		std::cout << "NO\n";
}