#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < int(n); ++i)

const int N = 500 * 1000 + 13;

int n, k;
vector<pair<int, int>> g[N];
long long dp[N][2];

void calc(int v, int p = -1) {
	long long cur = 0;
	vector<long long> adds;
	
	for (auto it : g[v]) {
		int to = it.x;
		int w = it.y;
		if (to == p)
			continue;
		calc(to, v);
		
		cur += dp[to][0];
		adds.pb(dp[to][1] + w - dp[to][0]);
	}
	
	sort(all(adds), greater<long long>());
	forn(i, min(sz(adds), k)) if (adds[i] > 0)
		cur += adds[i];
	
	dp[v][0] = dp[v][1] = cur;
	if (k <= sz(adds) && adds[k - 1] > 0)
		dp[v][1] -= adds[k - 1];
}

long long solve() {
    scanf("%d%d", &n, &k);
    forn(i, n) g[i].clear();
	forn(i, n - 1) {
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		--x; --y;
		g[x].pb(mp(y, w));
		g[y].pb(mp(x, w));
	}
	
	calc(0);
	
	return dp[0][0];
}

int main() {
	int q;
	scanf("%d", &q);
	forn(i, q) printf("%lld\n", solve());
}