/* Never Say Die */
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
typedef long long LL;
typedef double D;
typedef pair<int, int> pii;
#define mp(a, b) make_pair(a, b)
#define fir first
#define sec second
inline int min(int a, int b) {return a < b ? a : b;}
inline int max(int a, int b) {return a > b ? a : b;}
int ch = 0;
template <class T> inline void read(T &a) {
	bool f = 0; a = 0;
	while (ch < '0' || ch > '9') {if (ch == '-') f = 1; ch = getchar();}
	while (ch >= '0' && ch <= '9') {a = a * 10 + ch - '0'; ch = getchar();}
	if (f) a = -a;
}

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define N 1048576

struct cp {
	double r, i;
	cp () {}
	cp (double x, double y) : r(x), i(y) {}
	cp operator + (const cp a) {return cp(r + a.r, i + a.i);}
	cp operator - (const cp a) {return cp(r - a.r, i - a.i);}
	cp operator * (const cp a) {return cp(r * a.r - i * a.i, i * a.r + r * a.i);}
};

int n, m, R[N], ret[N], ans[N];

void gr() {
	int b = 0;
	for (int i = 2; i < n; i <<= 1, b++);
	for (int i = 0; i < n; i++) R[i] = (R[i >> 1] >> 1) | ((i & 1) << b);
}

void fft(cp a[], int rev) {
	for (int i = 0; i < n; i++) if (R[i] < i) swap(a[R[i]], a[i]);
	for (int i = 1; i < n; i <<= 1) {
		cp stp(cos(M_PI / i), rev * sin(M_PI / i));
		for (int j = 0; j < n; j += i << 1) {
			cp cur(1, 0);
			for (int k = 0; k < i; k++, cur = cur * stp) {
				cp x = a[j + k], y = cur * a[j + k + i];
				a[j + k] = x + y, a[j + k + i] = x - y;
			}
		}
	}
	if (rev < 0) for (int i = 0; i < n; i++) {
		ret[i] = int(a[i].r / n + 0.5);
	}
}

cp a[N], b[N];
char s[N / 2];

void solve() {
	read(m);
	scanf("%s", s);
	for (int i = m; i < n; i++) a[i] = b[i] = cp(0, 0);
	for (n = 2; n < m; n <<= 1); n <<= 1;
	gr();
	for (int i = 0; i < m; i++) a[i] = cp(s[i] == 'V', 0), b[i] = cp(s[m - i - 1] == 'K', 0);
	fft(a, 1); fft(b, 1);
	for (int i = 0; i < n; i++) a[i] = a[i] * b[i];
	fft(a, -1);
	for (int i = 1; i <= m; i++) ans[i] = 0;
	for (int i = 0; i < n; i++) ans[abs(i - m + 1)] |= ret[i];
	int cnt = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = i; j <= m; j += i) ans[i] |= ans[j];
		cnt += !ans[i];
	}
	printf("%d\n", cnt);
	for (int i = 1; i <= m; i++) if (!ans[i]) printf("%d ", i);
	putchar('\n');
}

int main() {
	int T;
	read(T);
	while (T--) solve();
	return 0;
}