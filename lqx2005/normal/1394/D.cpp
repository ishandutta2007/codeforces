#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 10;
const ll oo = 0x3f3f3f3f3f3f3f3f;
int n, a[N], b[N];
ll dp[N][2];
vector<int> g[N];
void dfs(int u, int fa) {
	ll sum = 0, up = 0, cnt = 0;
	vector<int> son;
	for(int &v : g[u]) {
		if(v == fa) continue;
		dfs(v, u);
		if(dp[v][0] < oo / 2) {
			sum += dp[v][0];
			up++;
			son.push_back(v);
		} else {
			sum += dp[v][1];
		}
		cnt++;
	}
	sort(son.begin(), son.end(), [&](int x, int y) {
		return dp[x][1] - dp[x][0] < dp[y][1] - dp[y][0];
	});
	if(!fa) {
		dp[u][0] = sum - min(up, cnt - up) * a[u];
	} else {
		sum += a[u] + a[fa];
		ll now = sum - min(up, cnt - up) * a[u];
		dp[u][0] = dp[u][1] = oo;
		if(b[fa] >= b[u]) dp[u][0] = now - (up > cnt - up) * a[u];
		if(b[fa] <= b[u]) dp[u][1] = now - (up < cnt - up) * a[u];
	}
	for(int &v : son) {
		if(v == fa) continue;
		if(dp[v][1] - dp[v][0] >= oo / 2) break;
		up--;
		sum += dp[v][1] - dp[v][0];
		ll now = sum - min(up, cnt - up) * a[u];
		if(!fa) {
			dp[u][0] = min(dp[u][0], now);
		} else {
			if(b[fa] >= b[u]) dp[u][0] = min(dp[u][0], now - (up > cnt - up) * a[u]);
			if(b[fa] <= b[u]) dp[u][1] = min(dp[u][1], now - (up < cnt - up) * a[u]);
		}
	}
//	cout << dp[u][0] <<" " << dp[u][1] << endl;
 	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v), g[v].push_back(u);
	}
	dfs(1, 0);
	cout << dp[1][0] << endl;
	return 0;
}