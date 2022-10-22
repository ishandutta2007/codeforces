#include <bits/stdc++.h>
#define u64 unsigned long long
#define i64 long long
using namespace std;
const int N = 4000 + 10;
int n, m, a[N], stk[N], top = 0;
int ls[N], rs[N], siz[N];
i64 dp[N][N];

void chkmax(i64 &x, i64 y) {
	if(x < y) x = y;
}

void dfs(int u, int d) {
	if(!u) return;
	dfs(ls[u], a[ls[u]] - a[u]), dfs(rs[u], a[rs[u]] - a[u]);
	siz[u] = siz[ls[u]] + siz[rs[u]] + 1;
	for(int i = 0; i <= siz[ls[u]]; i++) {
		for(int j = 0; j <= siz[rs[u]]; j++) {
			chkmax(dp[u][i + j], dp[ls[u]][i] + dp[rs[u]][j]);
			chkmax(dp[u][i + j + 1], dp[ls[u]][i] + dp[rs[u]][j]);
		}
	}
	for(int i = 0; i <= siz[u]; i++) {
		dp[u][i] += 1ll * i * (m - i) * d;
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		while(top && a[stk[top]] > a[i]) {
			ls[i] = stk[top--];
		}
		rs[stk[top]] = i;
		stk[++top] = i;
	}
	dfs(stk[1], 0);
	cout << dp[stk[1]][m] << endl;
	return 0;
}