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

int n, m;
vector<int> adj[MAXN], back[MAXN], chd[MAXN];
int vis[MAXN], node[MAXN], par[MAXN], cnt, num;

struct data {
    int a, b, c;
    data() {}
    data(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {}
};
vector<data> ans;

bool dfs(int cur, int p=-1) {
    par[cur] = p;
    vis[cur] = cnt, node[cnt] = cur, cnt++;
    rep(i, adj[cur].size()) {
        num++;
        int nxt = adj[cur][i];
        if (vis[nxt] != -1) {
            if (vis[nxt] < vis[cur] && nxt != p) back[cur].push_back(nxt);
        } else {
            if (dfs(nxt, cur)) chd[cur].push_back(nxt);
        }
    }
    for (int i=0; i+1<back[cur].size(); i+=2) ans.push_back(data(back[cur][i], cur, back[cur][i+1]));
    for (int i=0; i+1<chd[cur].size(); i+=2) ans.push_back(data(chd[cur][i], cur, chd[cur][i+1]));
    if ((chd[cur].size()&1) && (back[cur].size()&1)) {
        ans.push_back(data(chd[cur].back(), cur, back[cur].back()));
        return 1;
    } else if (chd[cur].size()&1) ans.push_back(data(chd[cur].back(), cur, p));
    else if (back[cur].size()&1) ans.push_back(data(back[cur].back(), cur, p));
    else return 1;
    return 0;
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

    memset(vis, -1, sizeof(vis));
    for (int i=0; i<n; i++)
        if (vis[i] == -1) {
            cnt = num = 0;
            if (!dfs(i)) {
                cout << "No solution\n";
                return 0;
            }
        }

    rep(i, ans.size())
        cout << ans[i].a+1 << ' ' << ans[i].b+1 << ' ' << ans[i].c+1 << '\n';
    return 0;
}