#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

struct MaxTree {
    int n;
    vector<int> mx;

    explicit MaxTree(int n) : n(n), mx(2 * n, -1) {}

    void set(int i, int x) {
        mx[i += n] = x;
        for (i /= 2; i > 0; i /= 2) mx[i] = ::max(mx[2 * i], mx[2 * i + 1]);
    }

    int get(int l, int r) {
        int res = -1;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) res = ::max(res, mx[l++]);
            if (r & 1) res = ::max(res, mx[--r]);
        }
        return res;
    }
};

#define answer(ans) {cout << (ans) << '\n'; return;}

struct query {
    int l, r, x, i;

    query(int l, int r, int x, int i) : l(l), r(r), x(x), i(i) {}

    query() = default;
};

void solve() {
    int n, q;
    cin >> n >> q;
    set<int> na, ok;
    for (int i = 0; i < n; ++i) na.insert(i);
    vector<query> qu;
    vector<pair<int, int>> h;
    vector<int> ans(q, -2);
    MaxTree time(n);
    for (int j = 0; j < q; ++j) {
        int t;
        cin >> t;
        if (t == 0) {
            int l, r, x;
            cin >> l >> r >> x;
            --l;
            if (x == 0) {
                while (true) {
                    auto it = na.lower_bound(l);
                    if (it == na.end() || *it >= r) break;
                    ok.insert(*it);
                    time.set(*it, j);
                    na.erase(it);
                }
            }
            h.emplace_back(0, qu.size());
            qu.emplace_back(l, r, x, j);
        } else {
            int idx;
            cin >> idx;
            h.emplace_back(1, --idx);
            ans[j] = -1;
            if (ok.find(idx) != ok.end()) ans[j] = 1;
        }
    }
    vector<int> ill(n, q + 2);
    for (auto[l, r, x, j]: qu) {
        if (x == 0) continue;
        auto it = ++na.lower_bound(l);
        if (it == na.end() || *it >= r) {
            --it;
            int cur = *it;
            ill[cur] = min(ill[cur],max(j, max(time.get(l, cur), time.get(cur + 1, r))));
        }
    }
    for (int j = 0; j < q; ++j) {
        auto[t, idx] = h[j];
        if (t == 1 && ill[idx] < j) ans[j] = 0;
    }
    for (int i = 0; i < q; ++i) {
        int x = ans[i];
        if (x > -2) {
            if (x == -1) cout << "N/A\n";
            if (x == 0) cout << "YES\n";
            if (x == 1) cout << "NO\n";
        }
    }
}