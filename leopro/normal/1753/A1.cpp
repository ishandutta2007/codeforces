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
    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    vector<pair<int, int>> ans;
    bool bad = false;
    auto solve = [&](auto solve, int l, int r) -> void {
        if (accumulate(a.begin(), a.end(), 0LL) & 1) {
            bad = true;
            return;
        }
        ll s = 0;
        for (int i = l; i < r; ++i) if ((i - l) & 1) s -= a[i]; else s += a[i];
        if (s == 0) {
            ans.emplace_back(l, r);
            return;
        }
        ll c = 0;
        for (int i = l; i < r; ++i) {
            if ((i - l) & 1) c -= a[i]; else c += a[i];
            if (c + c == s) {
                if ((i + 1 - l) & 1) {
                    ans.emplace_back(l, i + 1);
                    ans.emplace_back(i + 1, r);
                    return;
                }
                solve(solve, l, i + 1);
                solve(solve, i + 1, r);
                return;
            }
        }
    };
    solve(solve, 0, n);
    if (bad) answer(-1);
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto [l, r]: ans) cout << l + 1 << ' ' << r << '\n';

}