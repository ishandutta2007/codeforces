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
typedef pair<pii, int> piii;

const int MAXN = 300100;

int n, m, dp[MAXN];
piii edges[MAXN];

bool cmp(piii p1, piii p2) { return p1.se < p2.se; }

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    rep(i, m) cin >> edges[i].fi.fi >> edges[i].fi.se >> edges[i].se;
    sort(edges, edges+m, cmp);
    for (int i=0, j; i<m; i=j) {
        vector<pii> v;
        for (j=i; j<m && edges[j].se == edges[i].se; j++)
            v.push_back(pii(edges[j].fi.se, dp[edges[j].fi.fi]+1));
        rep(k, v.size())
            dp[v[k].fi] = max(dp[v[k].fi], v[k].se);
    }

    cout << *max_element(dp, dp+n+1) << '\n';
    return 0;
}