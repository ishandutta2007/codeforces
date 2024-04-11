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

const int MAXN = 21;
const int MOD = 1e9 + 7;

int n, ans;
ll s, f[MAXN];
int inv[MAXN];

int exp(int b, int e) {
    if (!e) return 1;
    int res = exp(b, e/2);
    if (e&1) return ll(res)*res%MOD*b%MOD;
    return ll(res)*res%MOD;
}

int C(int a, int b) {
    int ret = 1;
    for (int i=1; i<=b; i++)
        ret = ll(ret)*(a-i+1)%MOD*inv[i]%MOD;
    return ret;
}

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> s;
    rep(i, n) cin >> f[i];
    rep(i, n) inv[i] = exp(i, MOD-2);
    rep(i, 1<<n) {
        int x = 1;
        ll k = 0;
        rep(j, n)
            if (i&1<<j) x *= -1, k += f[j]+1;
        if (s-k >= 0)
            ans = (ans+(x*C((s-k+n-1)%MOD, n-1)+MOD)%MOD)%MOD;
    }

    cout << ans << '\n';
    return 0;
}