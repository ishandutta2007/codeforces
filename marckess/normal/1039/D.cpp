#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define FORR(i,a,b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 100005, SQ = 1000;
int n, da[MX], db[MX], res[MX], o[MX], p[MX], u, v, cn = 0;
vi adj[MX];

void dfs (int u, int par) {
    p[u] = par;
    for (int v : adj[u])
        if (v != par)
            dfs(v, u);
    o[cn++] = u;
}

int obtRes (int m) {
    for (int i = 0; i < n; i++) {
        int u = o[i], a = 0, b = 0;
        da[u] = 0;
        
        for (int v : adj[u])
            if (v != p[u]) {
                da[u] += da[v];
                if (db[v] > b) b = db[v];
                if (b > a) swap(a, b);
            }
        
        if (a + b + 1 >= m) da[u]++, db[u] = 0;
        else db[u] = a + 1; 
    }
    
    return da[1];
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	FOR(i,n-1) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

    dfs(1, 1);

	for (int i = 1; i <= min(SQ, n); i++)
		res[i] = obtRes(i);

    for (int i = SQ+1; i <= n;) {
        int act = obtRes(i), sig;
        int l = i, r = n+1;
        if (!act) break;
        
        while (l + 1 < r) {
            int m = (l+r)/2;
            if (obtRes(m) == act) l = m;
            else r = m-1;
        }
        
        if (obtRes(r) == act) sig = r;
        else sig = l;
        
        while (i <= sig) res[i++] = act;
    }

	for (int i = 1; i <= n; i++)
		cout << res[i] << endl;
	
	return 0;
}