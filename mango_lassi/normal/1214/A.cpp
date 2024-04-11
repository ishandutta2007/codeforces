#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, d, e;
	cin >> n >> d >> e;
	e *= 5;

	int res = n;
	int j = n/e;
	for (; n >= 0; n -= d) {
		while(j*e > n) --j;
		res = min(res, n - j*e);
	}
	cout << res << '\n';
}