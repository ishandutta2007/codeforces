#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int maxn = 3e5 + 10;
int n,q,mod,a[maxn],b[maxn],c[maxn],d[maxn],fib[maxn],res;
#define fix(x) (((x) % mod + mod) % mod)
void inc(int pos, int val) {
	if (pos > n) return;
	d[pos] ? res-- : 0;
	d[pos] = fix(d[pos] + val);
	d[pos] ? res++ : 0;
}

int main() {
	scanf("%d%d%d", &n, &q, &mod);
	fib[1] = 1;
	for (int i = 2; i <= n + 2; ++i) fib[i] = fix(fib[i - 1] + fib[i - 2]);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), a[i] = fix(a[i]);
	for (int i = 1; i <= n; ++i) scanf("%d", &b[i]), b[i] = fix(b[i]);
	for (int i = 1; i <= n; ++i) c[i] = fix(a[i] - b[i]);
	d[1] = c[1];
	for (int i = 2; i <= n; ++i) d[i] = fix(fix(c[i] - c[i - 1]) - c[i - 2]);
	for (int i = 1; i <= n; ++i) d[i] ? res++ : 0;
	while (q--) {
		char op[2]; int l, r;
		scanf("%s%d%d", op, &l, &r);
		if (op[0] == 'A') inc(l, 1), inc(r + 1, -fib[r - l + 2]), inc(r + 2, -fib[r - l + 1]);
		else inc(l, -1), inc(r + 1, fib[r - l + 2]), inc(r + 2, fib[r - l + 1]);
		printf(res ? "NO\n" : "YES\n");
	}
	return 0;
}