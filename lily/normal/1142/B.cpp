#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef long double LD;
#define x first
#define y second
#define mp(a, b) make_pair(a, b)
#define read(a) scanf("%d", &a)


#define N 200005
#define LOG 20

int n, m, Q;
int a[N], b[N], c[N], l[N], ans[N];

int t[N][LOG];

int main() {
	read(n); read(m); read(Q);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++) c[a[i]] = i - 1;
	for (int i = 1; i <= m; i++) read(b[i]);
	for (int i = 1; i <= m; i++) b[i] = c[b[i]];
	memset(l, -1, sizeof l);
	for (int i = m; i; i--) {
		l[b[i]] = i;
		if (l[(b[i] + 1) % n] != -1) {
			t[i][0] = l[(b[i] + 1) % n];
		}
		else t[i][0] = 0;
	}
	for (int k = 1; k < LOG; k++) {
		for (int i = 1; i <= m; i++) {
			t[i][k] = t[t[i][k - 1]][k - 1]; 
		}
	}
	for (int i = 1; i <= m; i++) {
		int x = i;
		for (int j = 0; j < LOG; j++) if (((n - 1) >> j) & 1) x = t[x][j];
		if (x) ans[i] = x;
		else ans[i] = 0x3f3f3f3f;
	}
	for (int i = m - 1; i; i--) ans[i] = min(ans[i], ans[i + 1]);
	for (int i = 1; i <= Q; i++) {
		int l, r;
		read(l); read(r);
		putchar('0' + (ans[l] <= r));
	}
	return 0;
}