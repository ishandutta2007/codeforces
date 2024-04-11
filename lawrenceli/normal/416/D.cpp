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

const int MAXN = 200100;
const int INF = 1e9 + 10;

int n, ar[MAXN], last[MAXN], dp[MAXN];
vector<pii> v;
int cur, d=INF;

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    rep(i, n) cin >> ar[i];
    v.push_back(pii(1, -1));
    rep(i, n) {
        if (ar[i] != -1) {
            v.push_back(pii(ar[i], i));
            if (sz(v) > 2) {
                if (abs(v[sz(v)-1].fi-v[sz(v)-2].fi) % (v[sz(v)-1].se-v[sz(v)-2].se))
                    cur = v[sz(v)-2].se+1, d = INF;
                else {
                    int d2 = (v[sz(v)-1].fi-v[sz(v)-2].fi) / (v[sz(v)-1].se-v[sz(v)-2].se);
                    if (d2 != d) {
                        d = d2;
                        if (d <= 0) cur = v[sz(v)-3].se+1;
                        else cur = max(v[sz(v)-3].se+1, v[sz(v)-1].se-(v[sz(v)-1].fi-1)/d);
                    }
                }
            }
        } else if (d != INF && v[sz(v)-1].fi+ll(i-v[sz(v)-1].se)*d <= 0)
            cur = v[sz(v)-2].se+1, d = INF;
        last[i] = cur;
    }

    dp[0] = 0;
    rep(i, n) dp[i+1] = dp[last[i]]+1;
    cout << dp[n] << '\n';
    return 0;
}