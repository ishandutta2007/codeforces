#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;

void solve() {
    int n;
    cin >> n;
    const int N = 1.5e7 + 5;
    vector<int> cnt(N);
    vector<int> a(n);
    int g = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        g = gcd(g, a[i]);
    }
    for (int i = 0; i < n; i++)
        cnt[a[i] / g]++;
    vector<int> isPrime(N, 1);
    int best = 0;
    for (int i = 2; i < N; i++) {
        if (!isPrime[i])
            continue;
        int sum = 0;
        for (int j = i; j < N; j += i) {
            isPrime[j] = 0;
            sum += cnt[j];
        }
        best = max(best, sum);
    }
    if (best == 0)
        cout << -1 << '\n';
    else
        cout << n - best << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
}