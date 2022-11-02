#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define px real()
#define py imag()
#define rep(i, n) for (int i=0, _##i=(n); i<_##i; ++i)
#define repi(i, n) for (__typeof((n).begin()) i=(n).begin(), _##i=n.end(); i != _##i; ++i)
#define sz(x) int((x).size())
#define print(x) cerr << #x << ": " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> pnt;

const int MAXN = 100100;

int n, m, x[MAXN], y[MAXN];
vector<int> adj[MAXN], chd[MAXN];
bool vis[MAXN];
int numc, curc, st;
vector<int> ans;

void dfs(int cur) {
    if (vis[cur]) return;
    vis[cur] = 1;
    curc += x[cur];
    rep(i, adj[cur].size())
        dfs(adj[cur][i]);
}

void dfs2(int cur) {
    vis[cur] = 1;
    rep(i, adj[cur].size()) {
        int nxt = adj[cur][i];
        if (!vis[nxt]) {
            chd[cur].push_back(nxt);
            dfs2(nxt);
        }
    }
}

void dfs3(int cur, int p=-1) {
    ans.push_back(cur);
    y[cur] = 1^((chd[cur].size())&1);
    rep(i, chd[cur].size()) {
        dfs3(chd[cur][i], cur);
        ans.push_back(cur);
    }
    if (x[cur] != y[cur]) {
        if (cur != st) ans.push_back(p), ans.push_back(cur), y[cur] ^= 1, y[p] ^= 1;
        else ans.pop_back();
    }
}

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    rep(i, n) cin >> x[i];

    rep(i, n)
        if (!vis[i]) {
            curc = 0;
            dfs(i);
            if (curc) numc++, st = i;
        }

    if (numc > 1) {
        cout << "-1\n";
        return 0;
    }

    memset(vis, 0, sizeof(vis));
    dfs2(st);
    dfs3(st);

    cout << ans.size() << '\n';
    rep(i, ans.size()) cout << ans[i]+1 << ' ';
    return 0;
}