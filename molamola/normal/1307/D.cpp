#include <bits/stdc++.h>
using namespace std;

#define Fi first
#define Se second
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)
typedef tuple<int, int, int> t3;

int n, m, k;
vector <int> E[200020], V;
int dis[2][200020];

void solve() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i=1;i<=k;i++) {
		int x; scanf("%d", &x);
		V.pb(x);
	}
	rep(i, m) {
		int x, y;
		scanf("%d%d", &x, &y);
		E[x].pb(y);
		E[y].pb(x);
	}
	rep(v, 2) {
		int st = (v == 0 ? 1 : n);
		vector <int> q;
		auto D = dis[v];
		for(int i=1;i<=n;i++) D[i] = -1;
		D[st] = 0; q.pb(st);
		rep(i, szz(q)) {
			int t = q[i];
			for(int e : E[t]) if(D[e] == -1) {
				D[e] = D[t] + 1;
				q.pb(e);
			}
		}
	}
	sort(all(V), [&](int x, int y) {
		return dis[0][x] > dis[0][y];
	});
	int mx = -1e9, ans = 0;
	for(int i=0;i+1<szz(V);i++) {
		if(dis[0][V[i]] == dis[0][V[i+1]]) {
			printf("%d\n", dis[0][n]);
			return;
		}
	}
	rep(i, szz(V)) {
		int u = V[i];
		int val = min({dis[0][n], dis[0][u] + dis[1][u], dis[0][u] + 1 + mx});
		ans = max(ans, val);
		mx = max(mx, dis[1][u]);
	}
	printf("%d\n", ans);
}

int main() {
	int T = 1; //scanf("%d", &T);
	for(int t=1;t<=T;t++) {
		solve();
	}
	return 0;
}