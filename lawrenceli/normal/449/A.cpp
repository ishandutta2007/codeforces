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

ll n, m, k;

ll val(ll x) {
    return ll(n/(x+1))*(m/(k-x+1));
}

int main() { _
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }

    cin >> n >> m >> k;
    if (k > n-1+m-1) {
        cout << "-1\n";
        return 0;
    }

    ll lo = max(0LL, k-m+1), hi = min(k, n-1);
    ll ans = max(val(lo), val(hi));

    cout << ans << '\n';
    return 0;
}