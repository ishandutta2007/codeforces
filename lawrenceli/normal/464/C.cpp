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
const int MAXD = 10;
const int MOD = 1e9 + 7;

int n;
int st[MAXN];
string nd[MAXN];
pii dp[MAXN][MAXD];

int exp(int b, int e) {
    if (!e) return 1;
    int res = exp(b, e/2);
    if (e&1) return ll(res)*res%MOD*b%MOD;
    return ll(res)*res%MOD;
}

pii calc(int i, int j) {
    if (i == n) return pii(j, 1);
    pii& ret = dp[i][j];
    if (ret.fi != -1) return ret;
    if (st[i] != j) return ret = calc(i+1, j);
    ret = pii(0, 0);
    rep(k, nd[i].length()) {
        pii p = calc(i+1, nd[i][k]-'0');
        ret.fi = (ret.fi+ll(p.fi)*exp(10, ret.se)%MOD)%MOD;
        ret.se = (ret.se+p.se)%(MOD-1);
    }
    return ret;
}

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    string s; cin >> s;
    reverse(s.begin(), s.end());
    st[0] = 0, nd[0] = s;

    cin >> n;
    for (int i=1; i<=n; i++) {
        string t; cin >> t;
        st[i] = t[0]-'0';
        nd[i] = t.substr(3);
        reverse(nd[i].begin(), nd[i].end());
    }
    n++;

    rep(i, MAXN)
        rep(j, MAXD)
            dp[i][j] = pii(-1, -1);
    cout << calc(0, 0).fi << '\n';
    return 0;
}