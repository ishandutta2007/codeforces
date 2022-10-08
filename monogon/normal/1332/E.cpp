
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// sufficient to make all cells the same parity (even, odd)
// the rest is taken care of with operation 2
// a sequence of operation 1 can change the parity of 2 cells of choice
// so, we only care that the numbers mod 2 has one group of even size
// if n * m is odd, then everything works: (R - L + 1) ^ (n * m)
// otherwise, split in group of size 2k and nm - 2k
// ans = sum_{k=0,2,4,...,nm} (nm choose k) e^(nm - k) o^(k)

// A = sum_{k=0,1,2,...,nm} (nm choose k) e^(nm - k) o^(k) = (e + o)^nm = (R - L + 1)^nm
// B = sum_{k=0,1,2,...,nm} (nm choose k) e^(nm - k) (-o)^(k) = (e - o)^nm
// A + B = 2 * sum_{k even} (nm choose k) e^(nm - k) o^(k) = 2 * ans

const int M = 998'244'353;

ll n, m, L, R;

ll mod(ll a, ll m) {
    return (a % m + m) % m;
}
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
    return g > 1 ? -1 : mod(x, m);
}
ll modpow(ll a, ll b) {
    a = mod(a, M);
    ll ans = 1;
    while(b > 0) {
        if(b & 1) {
            ans = mod(ans * a, M);
        }
        a = mod(a * a, M);
        b /= 2;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> L >> R;
    ll A = modpow(R - L + 1, n * m);
    if(n % 2 == 1 && m % 2 == 1) {
        cout << A << '\n';
        return 0;
    }
    ll o = mod((R + 1) / 2 - L / 2, M);
    ll e = mod((R - L + 1) - o, M);
    ll ans = mod(mod(A + modpow(e - o, n * m), M) * modinverse(2, M), M);
    cout << ans << '\n';
}