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
int n, p;
int a[MAXN], b[MAXN];
LL tot = 0;

bool check(double mid) {
	double need = 0;
	for (int i = 1; i <= n; i++) {
		need += max((double)0, a[i] * mid - b[i]) / p;
	}
	return need <= mid;
}


int main() {
	cin >> n >> p;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
		tot += a[i];
	}
	if (p >= tot) puts("-1");
	else {
		double l = 0, r = n * 1e5 / (tot - p);
		for (int i = 0; i < 80; i++) {
		    double mid = (l + r) / 2;
			if (l == mid || r == mid) break;
			if (check(mid)) l = mid;
			else r = mid;
			
		}
		printf("%.5lf\n", l);
	}
	return 0;
}