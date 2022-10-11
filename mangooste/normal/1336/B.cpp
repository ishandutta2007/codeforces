#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

// #define int long long
#define all(a) a.begin(), a.end()

ll sqr(ll a) {
    return a * a;
}

ll get(ll a, ll b, ll c) {
    return sqr(a - b) + sqr(a - c) + sqr(b - c);
}

void get_best(ll L, ll R, vector<ll> &a, ll &ans) {
    ll mid = (L + R) / 2;
    int lb = lower_bound(all(a), mid) - a.begin();
    if (lb != a.size())
        ans = min(ans, get(L, R, a[lb]));
    if (lb != 0)
        ans = min(ans, get(L, R, a[lb - 1]));
    if (lb < a.size() - 1)
        ans = min(ans, get(L, R, a[lb + 1]));
}

void solve() {
    int na, nb, nc;
    cin >> na >> nb >> nc;
    vector<ll> a(na), b(nb), c(nc);
    for (ll &i : a)
        cin >> i;
    for (ll &i : b)
        cin >> i;
    for (ll &i : c)
        cin >> i;
    sort(all(a));
    sort(all(b));
    sort(all(c));
    vector<vector<ll>> best_b(na);
    for (int i = 0; i < na; i++) {
        int lb = lower_bound(all(b), a[i]) - b.begin();
        if (lb != nb)
            best_b[i].push_back(b[lb]);
        if (lb != 0)
            best_b[i].push_back(b[lb - 1]);
    }
    vector<vector<ll>> best_c(na);
    for (int i = 0; i < na; i++) {
        int lb = lower_bound(all(c), a[i]) - c.begin();
        if (lb != nc)
            best_c[i].push_back(c[lb]);
        if (lb != 0)
            best_c[i].push_back(c[lb - 1]);
    }
    ll ans = get(a[0], b[0], c[0]);
    for (int i = 0; i < na; i++)
        for (ll j : best_b[i])
            get_best(a[i], j, c, ans);
    for (int i = 0; i < na; i++)
        for (ll j : best_c[i])
            get_best(a[i], j, b, ans);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}