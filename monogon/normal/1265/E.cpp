
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const ll M = 998244353;
int n;
ll p;

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

ll modinverse(ll a, ll m) {
    ll x, y;
    ll g = euclid(a, m, x, y);
    return g > 1 ? -1 : (x % m + m) % m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    ll A = 0;
    for(int i = 0; i < n; i++) {
        cin >> p;
        A = ((((A + 1) * 100) % M) * modinverse(p, M)) % M;
    }
    cout << A << endl;
}