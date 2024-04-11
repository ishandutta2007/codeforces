#include <iostream>

int a[2], n;

int gcd(int x, int y) {
	return y == 0 ? x : gcd(y, x % y);
}

int main() {
	std::cin >> a[0] >> a[1] >> n;
	bool i;
	for(i = 0; true; i = !i) {
		int toRemove = gcd(n, a[i]);
		if(toRemove > n)
			break;
		else
			n -= toRemove;
	}
	std::cout << !i << std::endl;
}