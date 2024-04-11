#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int n, u, v, md = 0;
ll x[35], y[35];
vi adj[35];
int mx[] = {1, -1, 0, 0};
int my[] = {0, 0, 1, -1};
int esp[] = {1, 0, 3, 2};

void dfs (int u, int ant, int p, ll i, ll j, ll pot) {
    int l = 0;
    x[u] = i;
    y[u] = j;

    for (int v : adj[u]) {
        if (v == p)
            continue;
        if (l == ant)
            l++;
        dfs(v, esp[l], u, i + mx[l] * pot, j + my[l] * pot, pot / 2);
        l++;
    }
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
    
        adj[u].push_back(v);
        adj[v].push_back(u);
        
        md = max(md, (int)adj[u].size());
        md = max(md, (int)adj[v].size());
    }

    if (md > 4) {
        cout << "NO" << endl;
        return 0;
    }

    for (int i = 1; i <= n; i++)
        if (adj[i].size() == md) {
            dfs(i, -1, i, 0, 0, (1 << 30));
            break;
        }

    cout << "YES" << endl;
    for (int i = 1; i <= n; i++) {
        assert(-1e18 <= x[i] && x[i] <= 1e18);
        assert(-1e18 <= y[i] && y[i] <= 1e18);
        cout << x[i] << " " << y[i] << endl;
    }

    return 0;
}