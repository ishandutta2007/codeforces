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
    if (accumulate(a.begin(), a.end(), 0LL) & 1) answer(-1);
    vector<pair<int, int>> ans;
    bool bad = false;
    auto solve = [&](auto solve, int l, int r) -> void {
        assert((r - l) % 2 == 0);
        if (accumulate(a.begin() + l, a.begin() + r, 0LL) & 1) {
            assert(false);
            return;
        }
        ll s = 0;
        for (int i = l; i < r; ++i) if ((i - l) & 1) s -= a[i]; else s += a[i];
        if (s == 0) {
            if (l < r) ans.emplace_back(l, r);
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
    int l = 0, r = 0;
    int k = 0;
    int f = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i]) {
            f = a[i];
            break;
        }
    }
    vector<bool> used(n);
    for (int i = 0; i < n; ++i) {
        if (a[i] && (i == 0 || !a[i - 1])) {
            l = i;
        }
        if (a[i] && (i + 1 == n || !a[i + 1])) {
            r = i + 1;
            if ((r - l) % 2 == 0) {
                solve(solve, l, r);
            } else {
                solve(solve, l + 1, r);
                if ((k & 1) == (f == a[l])) {
                    ans.emplace_back(l - 1, l + 1);
                    used[l - 1] = true;
                } else {
                    ans.emplace_back(l, l + 1);
                }
                k++;
            }
        }
    }
    assert ((k & 1) == 0);
    assert(!bad);
    for (int i = 0; i < n; ++i) if (!used[i] && !a[i]) ans.emplace_back(i, i + 1);
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    assert(ans[0].first == 0);
    assert(ans.back().second == n);
    for (auto [l, r]: ans) {
        assert(l < r);
        cout << l + 1 << ' ' << r << '\n';
    }
}