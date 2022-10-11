#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> x(n);
    for (auto &a : x)
        cin >> a;

    if (find(x.begin(), x.end(), k) != x.end())
        return cout << "YES\n", void();
    if (n == 1)
        return cout << "NO\n", void();

    vector<ll> preffix_gcd(n, 0);
    for (int i = 1; i < n; i++)
        preffix_gcd[i] = gcd(preffix_gcd[i - 1], abs(x[i] - x[i - 1]));
    vector<ll> suffix_gcd(n, 0);
    for (int i = n - 2; i >= 0; i--)
        suffix_gcd[i] = gcd(suffix_gcd[i + 1], abs(x[i + 1] - x[i]));

    bool any = false;
    for (int which = 0; which < n; which++) {
        ll g = 0;
        if (which)
            g = gcd(g, gcd(preffix_gcd[which - 1], abs(x[which - 1] - x[which])));
        if (which != n - 1)
            g = gcd(g, gcd(suffix_gcd[which + 1], abs(x[which + 1] - x[which])));
        any |= abs(k - x[which]) % g == 0;
    }
    cout << (any ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}