/* Heroes Never Die. */
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

template <class T> inline void read(T &_a) {
	bool _f = 0; int _c = 0; _a = 0;
	while (_c < '0' || _c > '9') _f |= _c == '-', _c = getchar();
	while (_c >= '0' && _c <= '9') _a = _a * 10 + _c - '0', _c = getchar();
	if (_f) _a = -_a;
}

int n;
int f(int x) {
	int ret = 1;
	while (x) {
		int y = x % 10;
		if (y) ret *= y;
		x /=10;
	}
	return ret;
}

int g[1000005];
vector <int> a[10];

int main() {
	for (int i = 1; i < 10; i++) g[i] = i;
	for (int i = 10; i <= 1000000; i++) g[i] = g[f(i)];
	for (int i = 1; i <= 1000000; i++) {
		a[g[i]].push_back(i);
	}
	read(n);
	for (int i = 1; i <= n; i++) {
		int l, r, k;	
		read(l); read(r); read(k);
		printf("%d\n", upper_bound(a[k].begin(), a[k].end(), r) - upper_bound(a[k].begin(), a[k].end(), l - 1));
	}
	return 0;
}