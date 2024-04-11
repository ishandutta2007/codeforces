#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

#define answer(out) { cout << (out) << '\n'; return; }
#define answerExit(out) { cout << (out) << '\n'; exit(0); }

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

void solve() {
    int n, k;
    cin >> n >> k;
    set<vector<int>> c;
    for (int i = 0; i < n; ++i) {
        vector<int> cur(k);
        for (int &x: cur) cin >> x;
        c.insert(cur);
    }
    ll ans = 0;
    for (auto &c1: c) {
        int cnt = 0;
        for (auto &c2: c) {
            vector<int> c3(k);
            for (int i = 0; i < k; ++i) c3[i] = (6 - c1[i] - c2[i]) % 3;
            cnt += c.contains(c3);
        }
        ans += cnt / 2 * (cnt / 2 - 1);
    }
    cout << ans / 2 << '\n';
}