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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;

int n, a, b, k;
vi adj[MX];
set<int> x, y;

int query (char c, int x) {
    cout << c << " " << x << endl;
    int r;
    cin >> r;
    fflush(stdout);
    return r;
}

void answer (int x) {
    cout << "C " << x << endl;
    fflush(stdout);
}

int dfs (int u, int p) {
    if (x.count(u)) return u;
    for (int v : adj[u])
        if (v != p) {
            int d = dfs(v, u);
            if (d != -1) return d;
        }
    return -1;
}

void solve () {
    cin >> n;
    forn(i,n) adj[i+1].clear();
    
    forn(i,n-1) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    x.clear(), y.clear();
    cin >> a;
    while (a--) {
        cin >> k;
        x.insert(k);
    }
    
    cin >> b;
    while (b--) {
        cin >> k;
        y.insert(k);
    }
    
    int root = query('B', *y.begin());
    
    if (x.count(root)) {
        answer(root);
        return;
    }
    
    int f = dfs(root, root);
    int g = query('A', f);
    
    if (y.count(g)) {
        answer(f);
        return;
    }
    
    answer(-1);
}

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
        cin >> t;
        while (t--) {
            solve();
        }

	return 0;
}