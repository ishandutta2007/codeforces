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

const int MX = 1000005, LMX = 21;
int n, k, u, v, p[LMX][MX], lvl[MX];
vi adj[MX];
bitset<MX> res;

void dfs (int u) {
	for (int v : adj[u])
		if (v != p[0][u]) {
			p[0][v] = u;
			lvl[v] = lvl[u] + 1;
			dfs(v);
		}
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    k = n - k - 1;

    lvl[n] = 0;
    p[0][n] = n;
    dfs(n);
    res[n] = 1;

    for (int j = 1; j < LMX; j++)
		for (int i = 1; i <= n; i++)
			p[j][i] = p[j-1][p[j-1][i]];

    for (int i = n - 1; i; i--) {
    	if (res[i])
    		continue;

    	int u = i;
    	for (int j = LMX - 1; j >= 0; j--)
    		if (!res[p[j][u]])
    			u = p[j][u];

    	u = p[0][u];

    	if (lvl[i] - lvl[u] > k)
    		continue;
    	k -= lvl[i] - lvl[u];

    	u = i;
    	res[u] = 1;
    	u = p[0][u];
    	while (!res[u]) {
    		res[u] = 1;
    		u = p[0][u];
    	}
    }

    for (int i = 1; i <= n; i++)
    	if (!res[i])
    		cout << i << " ";
    cout << endl;

    return 0;
}