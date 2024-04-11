#include <iostream>
#include <cstdlib>
using namespace std;
typedef long long lint;
const double epsilon = 1e-6;

int main() {
	lint n;
	cin >> n;
	lint limit = (lint)((sqrt(24 * (double)n + 1) - 1) / 6 + epsilon);
	lint mod = n % 3;
	cout << (limit + n % 3) / 3 << '\n';
	return 0;
}