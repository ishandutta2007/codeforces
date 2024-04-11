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

const int MX = 200005;
int n, u, v, h = 0;
vi adj[MX];

int dfs1 (int u, int l) {
    if (!adj[u].size())
        return h;

    int res;
    if (l) {
        res = 0;
        for (int v : adj[u])
            res = max(res, dfs1(v, 1 - l));
    } else {
        res = h+1;
        for (int v : adj[u])
            res -= h - dfs1(v, 1 - l) + 1;
    }

    return res;
}

int dfs2 (int u, int l) {
    if (!adj[u].size())
        return 1;

    int res;
    if (l) {
        res = 0;
        for (int v : adj[u])
            res += dfs2(v, 1-l);
    } else {
        res = h;
        for (int v : adj[u])
            res = min(res, dfs2(v, 1-l));
    }

    return res;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int i = 1; i <= n; i++)
        h += adj[i].empty();

    cout << dfs1(1, 1) << " " << dfs2(1, 1) << endl;

    return 0;
}