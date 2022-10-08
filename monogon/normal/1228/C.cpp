
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// for each prime divisor p of x, find its multiplicity k
// Then take (p^k)^m if p divides exactly m integers from 1 to n

const int M = 1e9 + 7;
ll dp[60];

ll powmod(ll base, ll k) {
    base %= M;
    k = k % (M - 1);
    ll total = 1;
    while(k) {
        if(k & 1) {
            total = (total * base) % M;
        }
        base = (base * base) % M;
        k >>= 1;
    }
    return total;
}

ll x, n;

ll solve(ll p) {
    ll powp = 1;
    ll ans = 1;
    while(powp <= (n + p - 1) / p) {
        // number of integers 1,...,n that divide p
        powp *= p;
        ll times = n / powp;
        ans = (ans * powmod(p, times)) % M;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> x >> n;
    ll ans = 1;
    for(int p = 2; p * p <= x; p++) {
        int k = 0;
        while(x % p == 0) {
            x /= p;
            k++;
        }
        if(k > 0) {
            ans = (ans * solve(p)) % M;
        }
    }
    if(x > 1) {
        ans = (ans * solve(x)) % M;
    }
    cout << ans << endl;
}