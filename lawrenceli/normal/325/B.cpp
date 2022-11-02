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

const int MAXB = 62;
const ll INF = 1e18;

ll n;
vector<ll> ans;

bool check(int i, ll m) {
    ll num;
    if (i) {
        if (m > n/((1LL<<i)-1)) return 0;
        num = n-m*((1LL<<i)-1);
    } else num = n;
    ll a = m, b = m-1;
    if (a&1) b >>= 1;
    else a >>= 1;
    if (!a || !b) return 1;
    if (a > num/b) return 0;
    return a*b<=num;
}

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    rep(i, MAXB) {
        ll lo = 0, hi = INF;
        while (lo < hi) {
            ll mid = (lo + hi + 1) / 2;
            if (check(i, 2*mid+1)) lo = mid;
            else hi = mid - 1;
        }
        lo = 2*lo+1;
        ll num = lo*((1LL<<i)-1)+lo*(lo-1)/2;
        if (num == n) ans.push_back(lo*(1LL<<i));
    }

    if (!sz(ans)) cout << "-1\n";
    else {
        sort(ans.begin(), ans.end());
        rep(i, ans.size())
            cout << ans[i] << '\n';
    }
    return 0;
}