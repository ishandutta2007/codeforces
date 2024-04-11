#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	long long r, g, b;
	cin >> r >> g >> b;
	if (r > 2 * (g + b))
		r = 2 * (g + b);
	if (g > 2 * (r + b))
		g = 2 * (r + b);
	if (b > 2 * (r + g))
		b = 2 * (r + g);
	cout << (r + g + b) / 3;
}