#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <list>
#include <deque>
using namespace std;


const int MAX_N = 1000333;

const long long INF = 1e18;

int phi (int n) {
	double ans = n;
	int d = 2;
	while (d * d <= n) {
		if (n % d == 0) {
			ans *= (1.0 - 1.0 / double(d));
			while (n % d == 0) {
				n /= d;
			}
		}
	}
	if (n > 1) {
		ans *= (1.0 - 1.0 / double(d));
	}
	return int(ans + 0.5);
}

long long binpow(long long a, long long b, long long md) {
	long long res = 1 % md;
	while (b) {
		if (b & 1) {
			res = (res * a) % md;
		}
		a = (a * a) % md;
		b >>= 1;
	}
	return res;
}

void solve() {
	long long x, y, a, b, xx, yy;
	cin >> x >> y >> a >> b;
	if (a == 0) {
		if (x == 0) {
			cout << "0\n";
			return;
		}
		cout << "-1\n";
		return;
	}
	if (b == a) {
		if (x == y) {
			cout << "0\n";
			return;
		}
		cout << "-1\n";
		return;
	}
	long long l = 0, r = 2e9;
	while (l + 1 < r) {
		long long c = (l + r) / 2;
		long long q = b * c;
		long long p = a * c;
		if (q >= y && q - y >= p - x && p >= x) {
			r = c;
		}
		else {
			l = c;
		}
	}
	cout << r * b - y << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}
#ifdef _DEBUG
	system("pause"); //453246046 / 359738130
#endif 
	return 0;
}

/*

*/