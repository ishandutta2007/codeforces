#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ld = long double;

unordered_set<ll> fact(ll n) {
    unordered_set<ll> ans;
    for (ll i = 1; i * i <= n; i++) 
        if (n % i == 0) {
            ans.insert(n / i);
            ans.insert(i);
        }
    return ans;
}

bool in(ll l, ll r, ll x) {
    return l <= x && x <= r;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    ll l, r;
    cin >> l >> r;
    ll x, y;
    cin >> x >> y;
    ll ans = 0;
    auto as = fact(x);
    auto bs = fact(y);
    ll prod = x * y;
    unordered_set<ll> ds;
    for (auto a : as)
        for (auto b : bs)
            ds.insert(a * b);
    for (auto d : ds) {
        auto A = d;
        auto B = prod / d;
        if (in(l, r, A) && in(l, r, B) && __gcd(A, B) == x)
            ans++;
    }
    cout << ans << endl;
}