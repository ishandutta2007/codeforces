#include <bits/stdc++.h>
using namespace std;

#define Fi first
#define Se second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)
typedef tuple<int, int, int> t3;

int n, k;
int par[110], dep[110], vis[110];
vector <int> E[110];
vector <int> ans;

void dfs(int x) {
	for(int c : {1, 2}) {
		for(int e : E[x]) {
			if(vis[e] == c) {
				ans.pb(e); dfs(e);
				if(vis[e] == 1) ans.pb(x);
			}
		}
	}
}

void solve() {
	scanf("%d%d", &n, &k);
	for(int i=2;i<=n;i++) {
		scanf("%d", par + i);
		E[par[i]].pb(i);
		dep[i] = dep[par[i]] + 1;
	}
	int v = (int)(max_element(dep + 1, dep + 1 + n) - dep);
	while(dep[v] >= k) v = par[v];
	for(int x=v;x;x=par[x]) vis[x] = 2;
	int rst = k - dep[v] - 1;
	while(rst > 0) {
		for(int i=1;i<=n;i++) if(!vis[i] && vis[par[i]]) {
			vis[i] = 1;
			--rst;
			break;
		}
	}
	ans = {1};
	dfs(1);
	printf("%d\n", szz(ans) - 1);
	for(int e : ans) printf("%d ", e); puts("");
	memset(vis, 0, sizeof vis);
	for(int i=1;i<=n;i++) E[i].clear();
}

int main() {
	int T; scanf("%d", &T);
	rep(t, T) {
		solve();
	}
	return 0;
}