/* Never Say Die. */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>
using namespace std;
int _c = 0;
template <class _T> inline void read(_T &_a) {
	_a = 0; bool _f = 0;
	while (_c < '0' || _c > '9') _f |= _c == '-', _c = getchar();
	while (_c >= '0' && _c <= '9') _a = _a * 10 + _c - '0', _c = getchar();
	if (_f) _a = -_a;
}
typedef long long LL;
typedef long double LD;

LL n, k, cnt = 0;

void solve() {
	LL x = (LL)sqrt(n);
	for (LL i = 1; i <= x; i++) {
		if (n % i == 0) {
			cnt++;
			if (n / i != i) cnt++;
		}
	}
	if (cnt < k) puts("-1");
	else {
		bool flag = 0;
		LL f = (cnt + 1) / 2;
		if (k > f) flag = 1, k = cnt - k + 1;
		LL hh = 0;
		for (LL i = 1; i <= x; i++) {
			if (n % i == 0) {
				hh++;
				if (hh == k) {
					if (flag) cout << n / i << endl;
					else cout << i << endl;
					break;
				}
			}
		}
	}
}

int main() {
	read(n); read(k);
	solve();
	return 0;
}