
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5, M = 998244353;

ll euclid(ll a, ll b, ll &x, ll &y) {
    ll xx = y = 0;
    ll yy = x = 1;
    while(b) {
        ll q = a / b;
        ll t = b; b = a % b; a = t;
        t = xx; xx = x - q * xx; x = t;
        t = yy; yy = y - q * yy; y = t;
    }
    return a;
}
ll modinverse(ll a) {
    ll x, y;
    ll g = euclid(a, M, x, y);
    return g > 1 ? -1 : ((x % M) + M) % M;
}

ll solve(int n, int m) {
    if(n <= 2 || m <= n - 2) return 0;
    ll ans = n - 2;
    for(int i = 0; i < n - 3; i++) {
        ans = (ans * 2) % M;
    }
    for(ll k = m; k >= m - n + 2; k--) {
        ans = (ans * k) % M;
    }
    ll denom = 1;
    for(int i = 1; i < n; i++) {
        denom = (denom * i) % M;
    }
    return (ans * modinverse(denom)) % M;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    cout << solve(n, m) << endl;
}