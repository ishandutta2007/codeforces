
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

#define answer(ans) {cout << ans << '\n'; return;}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int &x: a) cin >> x;
    for (int &x: b) cin >> x;
    ll sumSquared = 0;
    for (int x: a) sumSquared += x * x;
    for (int x: b) sumSquared += x * x;
    ll sumA = accumulate(a.begin(), a.end(), 0);
    ll sumB = accumulate(b.begin(), b.end(), 0);
    vector<int> d(n);
    for (int i = 0; i < n; ++i) d[i] = a[i] - b[i];
    vector ok(n + 1, vector<bool>(sumB + sumA + 1));
    ok[0][sumB] = true;
    for (int j = 0; j < n; ++j) {
        int x = d[j];
        for (int i = 0; i <= sumA + sumB; ++i) {
            if (0 <= i + x && i + x <= sumA + sumB && ok[j][i]) ok[j + 1][i + x] = true;
            if (ok[j][i]) ok[j + 1][i] = true;
        }
    }
    ll ans = 1e18;
    for (int s = 0; s <= sumA + sumB; ++s) {
        if (ok[n][s]) ans = min(ans, s * 1LL * s + (sumA + sumB - s) * 1LL * (sumA + sumB - s));
    }
    cout << ans + (n - 2) * sumSquared << '\n';
}