/* Never say die. */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <bitset>
using namespace std;
int _c = 0;
template <class T> inline void read(T &_a) {
	bool f = 0;
	while (_c < '0' || _c>'9') {if (_c == '-') f = 1; _c=getchar();}
	_a = 0;
	while (_c >= '0' && _c <= '9') {_a = _a * 10 + _c - '0'; _c = getchar();}
	if (f) _a = -_a;
}

#define MAXN 2017

inline int gcd(int a, int b) {
	while (b) {
		int c = a;
		a = b;
		b = c % b;
	}
	return a;
}

int T, p[MAXN], pcnt = 0, mu[MAXN];
bool vis[MAXN], gg[MAXN][MAXN];

void init() {
	mu[1] = 1;
	for (int i = 2; i < MAXN; i++) {
		if (!vis[i]) p[++pcnt] = i, mu[i] = -1;
		for (int j = 1; j <= pcnt && i * p[j] < MAXN; j++) {
			vis[i * p[j]] = 1;
			if (i % p[j] == 0) {mu[i * p[j]] = 0; break;}
			else mu[i * p[j]] = -mu[i];
		}
	}
	for (int i = 1; i < MAXN; i++)
		for (int j = i; j < MAXN; j++) {
			gg[i][j] = gg[j][i] = (gcd(i, j) == 1);
		}
}

int a, b, c;
unsigned ans = 0;

unsigned work(int n, int k) {
	unsigned ret = 0;
	for (int i = 1; i <= n; i++) {
		if (gg[k][i]) ret += n / i;
	}
	return ret;
}

int main() {
	init();
	read(a); read(b); read(c);
	int lim = min(b, c);
	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= lim; j++) {
			if (gg[i][j]) ans = ans + (a / i) * mu[j] * work(b / j, i) * work(c / j, i);
		}
	}
	printf("%d\n", ans % (1 << 30));
	return 0;
}