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
const int MAXL = 305;

int n, m, s, e, l, a[MAXN], b[MAXN], dp[MAXN][MAXL], dp2[MAXN][MAXL], ans;
vector<int> vf[MAXN];

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m >> s >> e;
    l = s/e;
    rep(i, n) cin >> a[i];
    rep(i, m) {
        cin >> b[i];
        vf[b[i]].push_back(i);
    }
    rep(i, MAXN) vf[i].push_back(m);

    rep(i, MAXN)
        rep(j, MAXL)
            dp[i][j] = dp2[i][j] = m;
    rep(i, n)
        dp[i][0] = dp2[i][0] = -1;
    rep(i, n)
        for (int j=1; j<=l; j++) {
            int x = dp2[i][j-1];
            if (x == m) continue;
            dp[i+1][j] = *upper_bound(vf[a[i]].begin(), vf[a[i]].end(), x);
            dp2[i+1][j] = min(dp[i+1][j], dp2[i][j]);
            if (dp[i+1][j] < m && j*e+i+dp[i+1][j]+2 <= s)
                ans = max(ans, j);
        }

    cout << ans << '\n';
    return 0;
}