#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
vector < ll > pr;
ll gcd(ll a, ll b) {
    while (a > 0 && b > 0) {
        if (a < b) swap(a, b);
        a %= b;
    }
    return (a + b);
}
ll x, y;
ll solve(ll x, ll y) {
    if (y == 0) return 0;
    if (x == 1) return y;
    ll d = gcd(x, y);
    ll biggest = 0;
    vector < ll > npr;
    ll f = (x / d);
    ll c = (y / d);
    for (ll p : pr) {
        if (f % p == 0) npr.push_back(p);
    }
    for (ll p : npr) {
        biggest = max(biggest, (c / p) * p);
    }
    return solve(x, biggest * d) + (c - biggest);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> x >> y;
    ll copx = x;
    for (int i = 2; 1LL * i * i <= copx; i++) {
        if (copx % i == 0) {
            while (copx % i == 0) copx /= i;
            pr.push_back(i);
        }
    }
    if (copx > 1) pr.push_back(copx);
    cout << solve(x, y);
    return 0;
}