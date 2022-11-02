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

const int MAXN = 20;

int n, m, mat[MAXN][MAXN];
ll dp[1<<MAXN][MAXN], ans;

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        mat[a][b] = mat[b][a] = 1;
    }

    rep(i, n) dp[1<<i][i] = 1;

    rep(i, 1<<n) {
        int l = __builtin_ctz(i);
        rep(j, n)
            if (i&1<<j)
                for (int k=l; k<n; k++)
                    if (mat[j][k]) {
                        if (k == l) ans += dp[i][j];
                        else if (!(i&1<<k)) dp[i^1<<k][k] += dp[i][j];
                    }
    }

    cout << (ans-m)/2 << '\n';
    return 0;
}