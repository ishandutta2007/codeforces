#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define mp(a, b) make_pair
#define x first
#define y second
#define read(x) scanf("%d", &x)
#define readl(x) scanf("%lld", &x)
#define readd(x) scanf("%lf", &x)


#define N 202025
#define MOD 998244353

int n;

vector <int> E[N];
LL fac[N], ans = 1;

void dfs(int x, int fa = -1) {
	int cnt = 0;
	for (auto v : E[x]) {
		if (v != fa) {
			dfs(v, x);
			cnt++;
		}
	}
	ans = ans * fac[cnt + (x != 1)] % MOD;
}


int main() {
	read(n);
	fac[0]  =1;
	for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % MOD;
	for (int i = 1; i < n; i++) {
		int u, v;
		read(u); read(v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	dfs(1);
	printf("%lld\n", (ans * n) % MOD);
}