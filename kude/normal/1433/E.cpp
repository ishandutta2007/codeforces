#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for (int i = (n)-1; i >= 0; --i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;

ll comb(ll n, ll m) {
    ll ans = 1;
    ll m0 = m;
    for(int i = 1; i <= m; n--, i++) {
        ans *= n;
        ans /= i;
    }
    return ans;
}

ll fact(ll n) {
    ll ans = 1;
    for(; n; --n) {
        ans *= n;
    }
    return ans;
}

ll f(ll x) {
    if (x <= 2) return 1;
    return fact(x-1);
}

int main() {
    ll n;
    cin >> n;
    //cout << n-1 << n/2-1 << ' ' << comb(n-1, n/2-1) << endl;
    cout << comb(n-1, n/2-1) * f(n/2) * f(n/2) << endl;
}