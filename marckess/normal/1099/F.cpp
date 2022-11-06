#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n;
ll T, x[MX], t[MX], l[MX], p[MX], mx[MX], res, dp[MX];
vi adj[MX];

map<int, int> mp;

void clear (stack<ii> &op) {
	while (op.size()) {
		ii it = op.top();
		op.pop();

		if (it.fi > 0) {
			int c = (mp[it.fi] -= it.se);
			if (!c) mp.erase(it.fi);
		}
		else {
			mp[-it.fi] -= it.se;
		}
	}
}

void pre (int u, ll s, ll cn) {
	stack<ii> op;

	mp[t[u]] += x[u];
	op.emplace(t[u], x[u]);
	s += t[u] * x[u] + 2 * l[u];
	cn += x[u];

	while (s > T && mp.size()) {
		ii it = *mp.rbegin();
		mp.erase(it.fi);
		op.emplace(-it.fi, -it.se);

		ll d = min(1ll * it.se, (s - T + it.fi - 1) / it.fi);
		s -= d * it.fi;
		cn -= d;

		if (d < it.se) {
			mp[it.fi] += it.se - d;
			op.emplace(it.fi, it.se - d);
		}
	}

	if (s > T) {
		clear(op);
		mx[u] = -1;
		return;
	}

	mx[u] = cn;

	for (int v : adj[u])
		pre(v, s, cn);

	clear(op);
}

void dfs (int u) {
	if (mx[u] == -1) return;

	ll x = 0, y = 0;
	for (int v : adj[u]) {
		dfs(v);

		if (dp[v] > x) {
			y = x;
			x = dp[v];
		} else if (dp[v] > y) {
			y = dp[v];
		}
	}

	if (u == 1) dp[u] = max(mx[u], x);
	else dp[u] = max(mx[u], y);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> T;
	for (int i = 1; i <= n; i++) cin >> x[i];
	for (int i = 1; i <= n; i++) cin >> t[i];

	for (int i = 2; i <= n; i++) {
		cin >> p[i] >> l[i];
		adj[p[i]].pb(i);
	}

	pre(1, 0, 0);
	dfs(1);

	cout << dp[1] << endl;

	return 0;
}