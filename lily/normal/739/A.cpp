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

#define MAXN 100005

int n, m;

int main() {
	read(n); read(m); int mi = n;
	for (int i = 1, l, r; i <= m; i++) read(l), read(r), mi = min(mi, r - l + 1);
	printf("%d\n", mi);
	for (int i = 1; i <= n; i++) {
		printf("%d ", i % mi);
	}
	return 0;
}