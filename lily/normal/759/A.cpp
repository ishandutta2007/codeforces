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
#define MAXN 200005
int n;
int p[MAXN], b[MAXN], f[MAXN];

int getf(int x) {
	if (f[x] < 0) return x;
	else return f[x] = getf(f[x]);
}


void merge(int u, int v) {
	int fu = getf(u), fv = getf(v);
	if (fu != fv) {
		if (f[fu] > f[fv]) swap(fu, fv);
		f[fu] += f[fv];
		f[fv] = fu;
	}
}
int main() {
	read(n);
	for (int i = 1; i <= n; i++) read(p[i]);
	b[0] = 1;
	for (int i = 1; i <= n; i++) read(b[i]), b[0] ^= b[i];
	memset(f, -1, sizeof(f));
	for (int i = 1; i <= n; i++) merge(i, p[i]);
	int cnt = 0;
	for (int i = 1; i <= n; i++) if (f[i] < 0) cnt++;
	if (cnt > 1) printf("%d\n", cnt + b[0]);
	else printf("%d\n", b[0]);
	return 0;
}