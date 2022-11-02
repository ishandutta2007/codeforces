
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

const int MAXN = 1000100;
const int MAXLG = 20;
const int MOD = 1e9 + 7;

int n, a[MAXN], dp[MAXN];
int sgn[2]={1, -1}, pw[MAXN];

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    rep(i, n) {
        scanf("%d", &a[i]);
        dp[a[i]]++;
    }

    pw[0] = 1;
    for (int i=1; i<MAXN; i++) pw[i] = pw[i-1]*2%MOD;

    rep(k, MAXLG)
        rep(i, MAXN)
            if (i&1<<k)
                dp[i^1<<k] += dp[i];

    int ans = 0;
    rep(i, MAXN)
        ans = (ans+(sgn[__builtin_popcount(i)&1]*((pw[dp[i]]+MOD-1)%MOD)+MOD)%MOD)%MOD;

    printf("%d\n", ans);
    return 0;
}