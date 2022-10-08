
#include <bits/stdc++.h>

#define ll long long
using namespace std;

ll n, k;

ll g(ll x) {
    int shift = log2(n) - (int) log2(x);
    ll ans = (1LL << shift) - 1;
    if((x << shift) <= n) {
        if(n >= ((x + 1) << shift)) {
            ans += (1LL << shift);
        }else {
            ans += (n & ans) + 1;
        }
    }
    return ans;
}
ll f(ll x) {
    return x % 2 ? g(x) : g(x) + g(x + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    if(f(n) >= k) {
        cout << n << '\n';
        return 0;
    }else if(f(n - 1) >= k) {
        cout << n - 1 << '\n';
        return 0;
    }
    ll L = 1, R = n / 2;
    while(L < R) {
        ll m = L + (R - L) / 2;
        if(f(2 * m) >= k) {
            L = m + 1;
        }else {
            R = m;
        }
    }
    ll l = 1, r = (n + 1) / 2;
    while(l < r) {
        ll m = l + (r - l) / 2;
        if(f(2 * m - 1) >= k) {
            l = m + 1;
        }else {
            r = m;
        }
    }
    cout << max(2 * (L - 1), 2 * (l - 1) - 1) << '\n';
}