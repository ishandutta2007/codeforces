
#include <iostream>
#include <cmath>

using namespace std;

long long n;

int main() {
	cin >> n;
	double d = sqrt(n);
	long long x = floor(d);
	long long y = ceil(d);
	cout << (x == y ? 2 * x : x * y >= n ? x + y : x + y + 1);
}