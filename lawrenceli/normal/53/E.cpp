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

const int MAXN = 10;

int n, m, k;
bool mat[MAXN][MAXN];
ll dp[1<<MAXN][1<<MAXN];

ll calc(int x, int y) {
    if (__builtin_popcount(y) < 2) return 0;
    ll& ret = dp[x][y];
    if (ret != -1) return ret;
    ret = 0;
    int p = __builtin_ctz(y);
    rep(i, n)
        if (x&1<<i)
            if (!(y&1<<i))
                if (mat[p][i])
                    ret += calc(x^1<<p, y^1<<p) + calc(x^1<<p, y^1<<p^1<<i);
    return ret;
}

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m >> k;
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        mat[a][b] = mat[b][a] = 1;
    }

    memset(dp, -1, sizeof(dp));
    rep(i, 1<<n)
        rep(j, 1<<n)
            if (__builtin_popcount(i) <= 2)
                dp[i][j] = 0;

    rep(i, n)
        rep(j, n)
            if (i != j)
                if (mat[i][j])
                    dp[1<<i|1<<j][1<<i|1<<j] = 1;

    ll ans = 0;
    rep(i, 1<<n)
        if (__builtin_popcount(i) == k)
            ans += calc((1<<n)-1, i);
    cout << ans << '\n';
    return 0;
}