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

const int MAXN = 505;
const int INF = 1e9;

int n, m, dist[MAXN][MAXN], num[MAXN][MAXN], ans[MAXN][MAXN];
vector<pii> adj[MAXN];

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    rep(i, n)
        rep(j, n)
            if (i != j)
                dist[i][j] = INF;
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        dist[a][b] = dist[b][a] = c;
        adj[a].push_back(pii(b, c));
        adj[b].push_back(pii(a, c));
    }

    rep(k, n)
        rep(i, n)
            rep(j, n)
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);

    rep(i, n) {
        rep(j, n)
            rep(k, adj[j].size())
                if (dist[i][adj[j][k].fi]+adj[j][k].se == dist[i][j])
                    num[i][j]++;
        rep(j, n)
            rep(k, n)
                if (dist[i][k]+dist[k][j] == dist[i][j])
                    ans[i][j] += num[i][k];
    }

    rep(i, n)
        for (int j=i+1; j<n; j++)
            cout << ans[i][j] << ' ';
    return 0;
}