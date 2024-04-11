
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// find prime factorization of D
// at most 14 distinct prime factors
// so we can quickly find prime factorization of each u and v, knowing they divide D.
// number of shortest paths is found by multinomial coefficients.
// precompute factorials up to 60 * 14

const ll M = 998244353;
int q;
ll D, u, v, fact[905], factinv[905];
vector<ll> primes;

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

ll solve(ll x) {
    ll ans = 1, sum = 0;
    for(ll p : primes) {
        ll cnt = 0;
        while(x % p == 0) {
            x /= p;
            cnt++;
        }
        sum += cnt;
        ans = (ans * modinverse(fact[cnt], M)) % M;
    }
    return (ans * fact[sum]) % M;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    fact[0] = factinv[0] = 1;
    for(int i = 1; i < 905; i++) {
        fact[i] = (i * fact[i - 1]) % M;
        factinv[i] = modinverse(fact[i], M);
    }
    cin >> D >> q;
    for(ll i = 2; i * i <= D; i++) {
        if(D % i == 0) {
            primes.push_back(i);
            while(D % i == 0) D /= i;
        }
    }
    if(D > 1) primes.push_back(D);
    while(q--) {
        cin >> u >> v;
        ll g = gcd(u, v);
        cout << ((solve(u / g) * solve(v / g)) % M) << '\n';
    }
}