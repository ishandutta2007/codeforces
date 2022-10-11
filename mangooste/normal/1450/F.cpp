#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

#ifdef LOCAL
#include "./Templates/debug.h"
#else
#define dbg(...)
#endif

#define len(a) int((a).size())
#define all(a) (a).begin(), (a).end()

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
        x--;
    }

    vector<int> cnt(n, 0);
    for (auto &x : a) {
        cnt[x]++;
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
        ok &= cnt[i] <= (n + 1) / 2;
    }
    if (!ok) {
        cout << "-1\n";
        return;
    }

    cnt.assign(n, 0);
    int bad = 1;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == a[i + 1]) {
            cnt[a[i]] += 2;
            bad++;
        }
    }
    cnt[a[0]]++;
    cnt[a.back()]++;

    int mx = *max_element(all(cnt));
    cout << max(0, mx - (bad + 1)) + bad - 1 << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}