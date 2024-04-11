#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i = (a); i != (b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const ll INF = 1e18;
const int maxn = 3e5;

ll W[maxn];
vii E[maxn];

ll ans = 0;

ll bgu[maxn], at[maxn], bgu2[maxn];

void dfs(ll u, ll v) {
	bgu[v] = W[v];
	at[v] = -1;
	bgu2[v] = W[v];
	for (ii e : E[v]) {
		if (e.x == u) continue;
		dfs(v, e.x);

		ll alt = bgu[e.x] - e.y + W[v];
		if (alt > bgu[v]) {
			bgu[v] = alt;
			at[v] = e.x;
		} else if (alt > bgu2[v]) {
			bgu2[v] = alt;
		}
	}
}

void dfs2(ll u, ll v, ll bgd) {
	bgd = max(bgd + W[v], W[v]);
	ans = max(ans, bgd);
	ans = max(ans, bgu[v]);
	for (ii e : E[v]) {
		if (e.x == u) continue;

		if (e.x == at[v]) {
			dfs2(v, e.x, max(bgd - e.y, bgu2[v] - e.y));
		} else {
			dfs2(v, e.x, max(bgd - e.y, bgu[v] - e.y));
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	REP(i, n) cin >> W[i];
	REP(i, n -1) {
		int a, b, c;
		cin >> a >> b >> c;
		a--;b--;
		E[a].eb(b, c);
		E[b].eb(a, c);
	}

	dfs(-1, 0);
	dfs2(-1, 0, 0);
	cout << ans << endl;
	return 0;
}