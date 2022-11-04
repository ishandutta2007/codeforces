// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 300005;
int n, q, vis[MX], par[MX];
ll dp[MX];
string s;
vi adj[MX], acu[MX];

stack<int> st[MX], p;

void dfs (int u) {
	vis[u] = 1;
	
	for (int v : adj[u]) {
		dfs(v);
		dp[u] += dp[v];
	}
	
	dp[u] += (ll)adj[u].size() * ((ll)adj[u].size() - 1) / 2;
}

void main_() {
	cin >> n >> q >> s; 
	
	memset(par, -1, sizeof(par));
	
	int lvl = 0;
	forn (i, n) {
		if (s[i] == '(') {
			p.push(i);
			lvl++;
		} else if (p.size()) {
			while (st[lvl].size()) {
				par[st[lvl].top()] = p.top();
				st[lvl].pop();
			}
			
			lvl--;
			st[lvl].push(p.top());
			dp[p.top()] = 1;
			p.pop();	
		} else {
			while (st[0].size())
				st[0].pop();
		}
	}
	
	forn (i, n) {
		if (!dp[i]) continue;
		
		if (par[i] == -1)
			par[i] = n;
		adj[par[i]].pb(i);
	}
	
	forn (i, n + 1)
		if (dp[i] && !vis[i])
			dfs(i);
	
	forn (i, n) {
		ll x = dp[i];
		if (acu[par[i]].size())
			x += acu[par[i]].back();
		acu[par[i]].pb(x);
	}
	
	while (q--) {
		int t, l, r;
		cin >> t >> l >> r;
		l--, r--;
		
		auto i = lower_bound(all(adj[par[l]]), l) - adj[par[l]].begin();
		auto j = upper_bound(all(adj[par[l]]), r) - adj[par[l]].begin() - 1;
		
		ll res = acu[par[l]][j] + 1ll * (j - i + 1) * (j - i) / 2;
		if (i)
			res -= acu[par[l]][i - 1];
		
		cout << res << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}