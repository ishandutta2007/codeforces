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

const int MAXN = 2005;

int n, p[MAXN], dp[MAXN], ans;

int calc(int x) {
    int& ret = dp[x];
    if (ret != -1) return ret;
    return p[x]<0 ? 1 : calc(p[x])+1;
}

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    memset(dp, -1, sizeof(dp));
    cin >> n;
    rep(i, n) cin >> p[i], p[i]--;
    rep(i, n) ans = max(ans, calc(i));
    cout << ans << '\n';
    return 0;
}