
#include <bits/stdc++.h>

#define ll long long
using namespace std;

ll a, b, c;
const ll M = 5000000000000000000LL;

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b >> c;
    ll x, y;
    ll g = euclid(a, b, x, y);
    // a x + b y = - c
    if(c % g == 0) {
        cout << (-x * (c / g)) << " " << (-y * (c / g)) << endl;
    }else {
        cout << -1 << endl;
    }
}