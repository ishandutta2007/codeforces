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

bool good(ll n, ll k, ll d1, ll d2) {
    if ((k-d1-2*d2)%3) return 0;
    ll c = (k-d1-2*d2)/3;
    ll b = d2+c, a = d1+b;
    if (a<0 || b<0 || c<0) return 0;
    if (n%3) return 0;
    if (a <= n/3 && b <= n/3 && c <= n/3 &&
        n/3-a <= n-k && n/3-b <= n-k && n/3-c <= n-k) return 1;
    return 0;
}

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    int t; cin >> t;
    rep(ii, t) {
        ll n, k, d1, d2;
        cin >> n >> k >> d1 >> d2;
        if (good(n, k, d1, d2) ||
            good(n, k, d1, -d2) ||
            good(n, k, -d1, d2) ||
            good(n, k, -d1, -d2)) cout << "yes\n";
        else cout << "no\n";

    }
    return 0;
}