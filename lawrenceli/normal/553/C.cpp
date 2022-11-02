#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 100100;
const int MOD = 1e9 + 7;

int n, m;
vector<pii> adj[MAXN];
int ans, par[MAXN], root[MAXN];
bool vis[MAXN];

void dfs(int cur) {
    vis[cur] = 1;
    vector<pii> v;
    for (pii p : adj[cur])
        if (vis[p.fi]) v.push_back(p);

    for (int i=0; i+1<v.size(); i++) {
        if ((v[i].se+v[i+1].se+par[v[i].fi]+par[v[i+1].fi])%2 == 1) {
            cout << 0;
            exit(0);
        }
    }

    if (v.empty()) root[cur] = cur, par[cur] = 1;
    else root[cur] = root[v[0].fi], par[cur] = (v[0].se+par[v[0].fi]+1)%2;

    for (pii p : adj[cur])
        if (!vis[p.fi]) dfs(p.fi);
}

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(pii(b, c));
        adj[b].push_back(pii(a, c));
    }

    for (int i=1; i<=n; i++)
        if (!vis[i]) {
            if (ans == 0) ans = 1;
            else ans = (ans*2)%MOD;
            dfs(i);
        }

    cout << ans;
}