#include <iostream>
#include <cstdlib>
const long long limit = 1000000007;

using namespace std;

int main() {
	long long a, b;
	cin >> a >> b;

	long long sum1, sum2, res;
	sum1 = a * (a + 1) / 2;
	sum2 = b * (b - 1) / 2;
	sum1 %= limit;
	sum2 %= limit;
	res = sum1 * b;
	res %= limit;
	res += a;
	res %= limit;
	res *= sum2;
	res %= limit;
	cout << res;

	return 0;
}