#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;

// char buf[1<<23], *p1=buf, *p2=buf, obuf[1<<23], *O=obuf;
// #define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<21, stdin), p1 == p2) ? EOF : *p1++)

void inline read(int &x) {
    x = 0; char s = getchar();
    while (s < '0' || s > '9') s = getchar();
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
}

const int N = 405;

int n, P, f[N][N], g[N], fact[N], infact[N];

int inline power(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = 1ll * res * a % P;
		a = 1ll * a * a % P;
		b >>= 1;
	}
	return res;
}

void inline add(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}

int main() {
	read(n); read(P);
	g[1] = 1;
	fact[0] = infact[0] = 1;
	for (int i = 1; i <= n; i++) {
		fact[i] = 1ll * fact[i - 1] * i % P;
		infact[i] = power(fact[i], P - 2) % P;
	}
	for (int i = 2; i <= n; i++) g[i] = 1ll * g[i - 1] * 2 % P;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == i) {
				add(f[i][j], (LL)g[i] * infact[i] % P);
			}
			for (int k = 0; k < i - 1; k++) {
				int t = i - k - 1;
				if (j >= t) add(f[i][j], (LL)f[k][j - t] * g[t] % P * infact[t] % P); 
			}
			// ncout << i << " " << j << " .>>> " << f[i][j] << endl;
		}
	}
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		add(ans, (LL)f[n][i] * fact[i] % P);
	}
	printf("%d\n", ans);
	return 0;
}