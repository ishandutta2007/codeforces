#include <bits/stdc++.h>
#define u64 unsigned long long
#define i64 long long
#define pb push_back
using namespace std;
const int N = 2e5 + 10;
int n, c[N], deg[N], sum[N];
vector<int> g[N], cnt[3];

int relieve(int i, int &tot) {
	int res = 0;
	for(; !cnt[i].empty() || !cnt[0].empty(); ) {
		int u = !cnt[i].empty() ? cnt[i].back() : cnt[0].back();
		if(!cnt[i].empty()) cnt[i].pop_back(), res = 1;
		else cnt[0].pop_back();
		tot++;
		for(int &v : g[u]) {
			if(deg[v] > 0) {
				deg[v]--;
				if(deg[v] == 1) {
					cnt[c[v]].pb(v);
				}
			}
		}
		deg[u] = 0;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	for(cin >> T; T--; ) {
		cin >> n;
		int all0 = 1;
		for(int i = 1; i <= n; i++) cin >> c[i], g[i].clear(), all0 &= !c[i], sum[i] = 0;
		for(int i = 1, u, v; i < n; i++) {
			cin >> u >> v;
			g[u].pb(v), g[v].pb(u);
			sum[u]++, sum[v]++;
		}
		for(int i = 1; i <= n; i++) deg[i] = sum[i];
		int tot = 0, res = 0, ans = 0;
		for(int i = 1; i <= n; i++) if(deg[i] <= 1) cnt[c[i]].pb(i);
		while(tot < n) {
			for(int i = 1; i <= 2; i++) {
				res += relieve(i, tot);
			}
		}
		ans = res;
		tot = 0, res = 0;
		for(int i = 1; i <= n; i++) deg[i] = sum[i];
		for(int i = 1; i <= n; i++) if(deg[i] <= 1) cnt[c[i]].pb(i);
		while(tot < n) {
			for(int i = 2; i >= 1; i--) {
				res += relieve(i, tot);
			}
		}
		ans = min(ans, res);
		cout << ans + all0 << endl;
	} 
	return 0;
}