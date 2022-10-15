#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)
#define x first
#define y second

#define N 505555

mt19937_64 rnd(1231231312);
int n, m;
long long c[N];
ULL hh[N], a[N];

unordered_map <ULL, LL> G;

void work() {
	G.clear();
	read(n); read(m);
	for (int i = 1; i <= n; i++) hh[i] = rnd();
	for (int i = 1; i <= n; i++) scanf("%lld", c + i), a[i] = 0;
	for (int i = 1; i <= m; i++) {
		int u, v;	
		read(u); read(v);
		a[v] ^= hh[u];
	}
	for (int i = 1; i <= n; i++) G[a[i]] += c[i];
	LL ans = 0;
	for (int i = 1; i <= n; i++) if (a[i] != 0) ans = __gcd(ans, G[a[i]]);
	printf("%lld\n", ans);
}

int main() {
	int T;
	read(T);
	while (T--) work();
}