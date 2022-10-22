#include<bits/stdc++.h>
#define sz(a) int((a).size())
#define x first
#define y second
#define pi pair<int, int> 
#define vi vector<int>
#define db double
#define i64 long long
#define u64 unsigned long long
using namespace std;
const int N = 2e3 + 10, oo = 0x3f3f3f3f;
int T, n, m, a[N], b[N], vis[N], cnt = 0, used[N];
int pre[N];
i64 dis[N];
vector<int> g[N];
queue<int> q;

int bfs(i64 &d) {
	for(; !q.empty(); ) {
		int u = q.front();
		q.pop();
		for(int &v : g[u]) {
			if(used[v]) continue;
			if(dis[u] > a[v]) {
				dis[v] = dis[u] + b[v];
				used[v] = 1;
				pre[v] = u;
				q.push(v);
			}
		}
	}
	int flag = 0;
	for(int u = 1; u <= n; u++) {
		for(int &v : g[u]) {
			if(dis[u] <= a[v] || pre[v] == u || pre[u] == v) continue;
			if(!used[u] || !used[v]) continue;
			if(vis[u] && vis[v]) continue;
			for(int x = u; !vis[x]; x = pre[x]) d += b[x], cnt++, vis[x] = 1;
			for(int x = v; !vis[x]; x = pre[x]) d += b[x], cnt++, vis[x] = 1;
			flag = 1;
			break;
		}
		if(flag) break;
	}
	return flag;
}

int check(i64 x) {
	memset(vis, 0, sizeof(vis));
	vis[0] = 1;
	vis[1] = cnt = 1;
	for(; cnt < n; ) {
		memcpy(used, vis, sizeof(vis));
		memset(pre, 0, sizeof(pre));
		for(int i = 1; i <= n; i++) {
			if(vis[i]) {
				dis[i] = x;
				q.push(i);
			}
		}
		if(!bfs(x)) return 0;
	}
	return 1;
}

void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) g[i].clear();
	for(int i = 2; i <= n; i++) cin >> a[i];
	for(int i = 2; i <= n; i++) cin >> b[i];
	for(int i = 1, u, v; i <= m; i++) {
		cin >> u >> v;
		g[u].push_back(v), g[v].push_back(u);
	}
	int L = 2, R = oo, ans = -1;
	while(L <= R) {
		int mid = (L + R) / 2;
		if(check(mid)) ans = mid, R = mid - 1;
		else L = mid + 1;
	}
	cout << ans << endl;
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	for(cin >> T; T--; ) solve();
	return 0;
}