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

const int MX = 100005;
int n, k, u, v, m, vis[MX], pr[MX];
vi adj[MX], res;

bool dfs (int u) {
    vis[u] = 1;

    for (int v : adj[u]) {
        if (vis[v] == 1)
            return 1;
        if (vis[v] == 0)
            if (dfs(v))
                return 1;
    }

    vis[u] = 2;
    res.push_back(u);
    return 0;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> k;
    for (int i = 0; i < k; i++)
        cin >> pr[i];

    for (int i = 1; i <= n; i++) {
        cin >> m;
        while (m--) {
            cin >> v;
            adj[i].push_back(v);
        }
    }

    for (int i = 0; i < k; i++)
        if (!vis[pr[i]])
            if (dfs(pr[i])) {
                cout << -1 << endl;
                return 0;
            }

    cout << res.size() << endl;
    for (int x : res)
        cout << x << " ";
    cout << endl;

    return 0;
}