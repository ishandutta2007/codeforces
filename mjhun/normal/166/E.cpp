#include <iostream>
#define M 1000000007

int main() {
	unsigned int a, i, n, r, p;
	std::cin >> n;
	r = 0;
	p = 1;
	for(i=2; i<=n; ++i) {
		p = (p*3)%M;
		r = (M+p-r)%M;
	}
	std::cout << r << std::endl;
	return 0;
}