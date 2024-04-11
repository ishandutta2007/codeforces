#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <ios>

using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<ll, ll> pll;

const int MAXN = 100100;

int n;
ll v[MAXN];
vector<int> adj[MAXN];

pll dfs(int cur, int p) {
    pll ret = pll(0, 0);

    for (int i=0; i<adj[cur].size(); i++) {
        int nxt = adj[cur][i];
        if (nxt == p) continue;
        pll res = dfs(nxt, cur);
        ret.fi = max(ret.fi, res.fi);
        ret.se = max(ret.se, res.se);
    }

    v[cur] += ret.fi, v[cur] -= ret.se;
    if (v[cur] < 0) ret.fi += abs(v[cur]);
    else ret.se += abs(v[cur]);

    return ret;
}

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i=0; i<n; i++) cin >> v[i];

    pll ans = dfs(0, -1);

    cout << ans.fi + ans.se << '\n';
    return 0;
}