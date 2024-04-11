#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, ans[100005];
vector<int> T[100005];
void dfs(int v, int p, int cur)
{
	ans[v] = cur;
	rep(i, T[v].size()) {
		int u = T[v][i];
		if(u == p) continue;
		dfs(u, v, -cur);
	}
}
void solve()
{
	scanf("%d", &n);
	rep1(i, n) T[i].clear();
	rep(i, n - 1) {
		int u, v;
		scanf("%d%d", &u, &v);
		T[u].push_back(v);
		T[v].push_back(u);
	}
	dfs(1, 0, 1);
	rep1(i, n) ans[i] *= T[i].size();
	rep1(i, n) printf("%d%c", ans[i], " \n"[i == n]);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}