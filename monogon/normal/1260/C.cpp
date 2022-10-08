
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t;
ll r, b, k;

// how many multiples of r between kb and (k+1)b, exclusive?
// how many multiples of r less than or equal to x?
// floor(x / r) + 1

// floor((k + 1)b - 1) / r) - floor((kb) / r).
// maximized when kb + b - 1 is a multiple of r
// kb + b - 1 = l r
// (k+1)b - lr = 1

// k + 1 = -1
// k = lcm(r, b) - 2

// 0 1 2 3 4 5
// 1 1 1 2 2 2 3

// rb r r b r r r b r r rb

// 0 3 6 8 9 12 15 16 18 21 24

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
    cin >> t;
    while(t--) {
        cin >> r >> b >> k;
        if(b < r) swap(r, b);
        ll g = gcd(r, b);
        r /= g;
        b /= g;
        ll x, y;
        euclid(r, b, x, y);

        euclid(r, b, x, y);
        ll K = (r * b + y - 1) % r;
        ll m = ((K * b + b - 1) / r) - ((K * b) / r);
        cout << (m >= k ? "REBEL" : "OBEY") << endl;
    }
}