#include <bits/stdc++.h>
#define x first
#define y second
#define sz(a) int((a).size())
using namespace std;
typedef long long ll;
typedef double db;
const int N = 1e6 + 10, M = 3e6 + 10;
int n, m;
int u[M], v[M], w[M], k[M], deg[N][2], nxt[M << 1], used[M << 1];
vector<int> g[N][2];
void con(int x, int y) {
	nxt[x] = y, nxt[y] = x;
}
void solve() {
    cin >> n >> m;
    int ans = 0;
	for(int i = 1; i <= m; i++) {
		cin >> u[i] >> v[i] >> w[i], w[i]--;
		deg[u[i]][w[i]]++, deg[v[i]][w[i]]++;
	}
	for(int u = 1; u <= n; u++) {
		for(int w = 0; w <= 1; w++) {
			g[u][w].reserve(deg[u][w]);
		}
	}
	for(int i = 1; i <= m; i++) {
		g[u[i]][w[i]].push_back(i * 2), g[v[i]][w[i]].push_back(i * 2 + 1);
	}
	for(int u = 1; u <= n; u++) {
        if(~deg[u][0] & 1) continue;
        ans++;
		for(int w = 0; w <= 1; w++) {
			for(int i = 1; i < sz(g[u][w]); i += 2) {
				con(g[u][w][i - 1], g[u][w][i]);
			}
		}
		if(sz(g[u][1]) & 1) {
			con(g[u][1].back(), g[u][0].back());
		}
	}
	for(int e = 2; e <= m * 2 + 1; e++) {
		if(nxt[e] || used[e]) continue;
		for(int now = e; now && !used[now]; now = nxt[now ^ 1]) {
			used[now] = used[now ^ 1] = 1;
			k[now / 2] = now & 1;
		}
	}
	for(int e = 2; e <= m * 2 + 1; e++) {
		if(used[e]) continue;
		for(int now = e; !used[now]; now = nxt[now ^ 1]) {
			used[now] = used[now ^ 1] = 1;
			k[now / 2] = now & 1;
		}
	}
    cout << ans << endl;
	for(int i = 1; i <= m; i++) cout << k[i] + 1;
	cout << endl; 
    return;
}

int main() {
    solve();
    // int t;
    // for(cin >> t; t--; solve());
    return 0;
}