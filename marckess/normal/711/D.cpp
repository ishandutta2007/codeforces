#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

ll pot (ll b, int p, int m) {
	ll res = 1;
	b %= m;

	while (p) {
		if (p & 1) {
			res *= b;
			res %= m;
		}

		b *= b;
		b %= m;
		p /= 2;
	}

	return res;
} 

int n, a, m = 1e9+7;
vvii adj(2e5+5);
vii dp(2e5+5);

ll res = 1;
vi vis(2e5+5);
ii act;

int dfs (int u, ii acu, int p, int k) {
	if (vis[u] == 1) {
		act = acu;
		act.fi -= dp[u].fi;
		act.se -= dp[u].se;
		return 0;
	}

	int cn = 1;
	vis[u] = 1;
	dp[u] = acu;

	for (ii &v : adj[u]) {
		if ((v.fi == p && k == 1 - v.se) || vis[v.fi] == 2)
			continue;

		if (v.se) {
			acu.se++;
			cn += dfs(v.fi, acu, u, 1);
			acu.se--;
		} else {
			acu.fi++;
			cn += dfs(v.fi, acu, u, 0);
			acu.se--;
		}
	}

	vis[u] = 2;
	return cn;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
    	cin >> a;
    	adj[a].emplace_back(i, 0);
    	adj[i].emplace_back(a, 1);
    }

    for (int i = 1; i <= n; i++) {
    	if (!vis[i]) {
    		act = {0, 0};
    		int n = dfs(i, {0, 0}, -1, -1);
			int d = act.fi + act.se;

			res *= pot(2, n, m) - 2 * pot(2, n-d, m);
			res %= m;
    	}
    }

    cout << MOD(res, m) << endl;

    return 0;
}