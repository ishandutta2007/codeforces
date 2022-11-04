#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1000005, LMX = 22;
int k, n, p[MX][LMX];
int dp[MX], up[MX], lvl[MX], lvs[MX];
vi adj[MX];

int kpar (int u, int k) {
    for (int j = LMX-1; j >= 0; j--)
        if (k & (1 << j))
            u = p[u][j];
    return u;
}

int pre1 (int u, int l) {
	lvl[u] = l;
	if (adj[u].empty()) return lvs[u] = l;

	lvs[u] = 1e9;
	for (int v : adj[u])
		lvs[u] = min(lvs[u], pre1(v, l+1));
	return lvs[u];
}

void pre2 (int u) {
	if (adj[u].empty()) {
		dp[up[kpar(u, k)]]++;
		return;
	}

	if (lvs[u] - lvl[u] >= k) up[u] = u;
	else up[u] = up[kpar(u, k - (lvs[u] - lvl[u]))];

	for (int v : adj[u])
		pre2(v);
}

int dfs (int u) {
    int mx = 0;
    for (int v : adj[u])
        mx = max(mx, dfs(v));
    return dp[u] += mx;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> k;

    if (n == 1) {
    	cout << 0 << endl;
    	return 0;
    }

    p[1][0] = 1;
    for (int i = 2; i <= n; i++) {
        cin >> p[i][0];
        adj[p[i][0]].pb(i);
    }

    for (int j = 1; j < LMX; j++)
        for (int i = 1; i <= n; i++)
            p[i][j] = p[p[i][j-1]][j-1];

    pre1(1, 0);
    up[1] = 1;
    pre2(1);
    cout << dfs(1) << endl;

    return 0;
}