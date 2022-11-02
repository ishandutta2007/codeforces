#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll limit = 1000 * 1000 * 10 + 10;

ll my_pow(ll x, ll n) {
    ll res = 1;
    for (int i = 0; i < n; i++) {
        res *= x;
        res = min(res, limit);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); 
    ll n, l, r;
    cin >> n >> l >> r;
    if (n == 1) {
        cout << r - l + 1 << endl;
        return 0;
    }
    if (n == 2) {
        cout << (r - l + 1) * (r - l) << endl;
        return 0;
    }
    if (n >= 30) {
        cout << 0 << endl;
        return 0;
    }
    ll res = 0;
    ll maxQ = 1;
    while (my_pow(maxQ, n - 1) < limit)
        maxQ++;
    maxQ--;
    for (ll q = 1; q <= maxQ; q++)
        for (ll p = q + 1; p <= maxQ; p++) {
            if (__gcd(p, q) != 1)
                continue;
            ll q1 = my_pow(q, n - 1);
            ll p1 = my_pow(p, n - 1);
            ll low = (l + q1 - 1) / q1;
            ll high = r / p1;
            if (low <= high)
                res += 2 * (high - low + 1);            
        }   
    cout << res << endl;  
}