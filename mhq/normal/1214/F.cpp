#include <bits/stdc++.h>
using namespace std;

/// It's the same as Petr Mitrichev Contest 1, Problem H

typedef long long ll;
const int maxN = 2 * (int)1e5 + 10;
int n;
int L;
pair < int, int > a[2 * maxN];
pair < int, int > f[2 * maxN];
ll b[2 * maxN];
int main() {
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    cin >> L >> n;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + 2 * n + 1);
    a[2 * n + 1].first = a[1].first + L;
    a[2 * n + 1].second = a[1].second;
    for (int i = 1; i <= 2 * n; i++) {
        b[i] = a[i + 1].first - a[i].first;
    }
    f[0] = make_pair(0, 0);
    for (int i = 1; i <= 2 * n; i++) {
        f[i].first = f[i - 1].first;
        if (a[i].second >= n + 1) f[i].first--;
        else f[i].first++;
        f[i].second = i;
    }
    ll all = 0;
    for (int i = 1; i <= 2 * n; i++) {
        all += 1LL * b[i] * f[i].first;
    }
    sort(f + 1, f + 2 * n + 1);
    ll ans = (ll)1e18;
    int ind = -1;
    // b[1] * |f[1] - f[j]| + b[2] * |f[2] - f[j]| + .. + b[2 * n] * |f[2 * n] - f[j]|
    // j
    ll sum_b = L;
    ll cur = all;

    for (int i = 1; i <= 2 * n; i++) {
        auto t = f[i];
        int pos = t.second;
        ll val = cur - (all - cur) - t.first * sum_b + t.first * (L - sum_b);
        if (val < ans) {
            ans = val;
            ind = pos;
        }
        cur -= b[pos] * t.first;
        sum_b -= b[pos];
    }
    cout << ans << '\n';
    vector < int > inds(n + 1);
    vector < int > of, em;
    for (int i = 1; i <= 2 * n; i++) {
        int id = a[(i + ind - 1) % (2 * n) + 1].second;
        if (id <= n) em.push_back(id);
        else of.push_back(id);
    }
    for (int i = 0; i < of.size(); i++) {
        inds[em[i]] = of[i] - n;
    }
    for (int i = 1; i <= n; i++) {
        cout << inds[i] << " ";
    }
}