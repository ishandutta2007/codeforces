#include <bits/stdc++.h>

#include <utility>

using namespace std;
using ll = long long;

void solve();

#define answer(answer) { cout << (answer) << '\n'; return; }

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}

struct segment_tree {
    int n;
    vector<pair<int, int>> min, max;

    explicit segment_tree(vector<int> a) : n(2 << __lg(a.size())), min(2 * n), max(2 * n) {
        for (int i = 0; i < a.size(); ++i) min[i + n] = max[i + n] = {a[i], i};
        for (int i = n - 1; i > 0; --i) {
            min[i] = std::min(min[2 * i], min[2 * i + 1]);
            max[i] = std::max(max[2 * i], max[2 * i + 1]);
        }
    }

    pair<int, int> maxQuery(int l, int r) {
        auto res = pair{0, 0};
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) res = std::max(res, max[l++]);
            if (r & 1) res = std::max(res, max[--r]);
        }
        return res;
    }

    pair<int, int> minQuery(int l, int r) {
        auto res = pair{INT_MAX, 0};
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) res = std::min(res, min[l++]);
            if (r & 1) res = std::min(res, min[--r]);
        }
        return res;
    }
};

int go(const vector<int> &a, segment_tree &s, int i) {
    if (i + 1 == a.size()) return 0;
    auto cmp = [&](int j) { return a[i + 1] > a[i] == a[j] > a[i]; };
    auto val = [&](int j) { return (a[i + 1] > a[i]) ? a[j] - a[i] : a[i] - a[j]; };
    int maxVal = 0;
    int where = i;
    int j = [&] {
        int l = i + 1, r = a.size();
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (s.minQuery(i, m + 1).first == a[i] || s.maxQuery(i, m + 1).first == a[i]) l = m; else r = m;
        }
        return l;
    }();
    if (a[i + 1] > a[i]) return 1 + go(a, s, s.maxQuery(i, j + 1).second);
    if (a[i + 1] < a[i]) return 1 + go(a, s, s.minQuery(i, j + 1).second);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    segment_tree s(a);
    cout << go(a, s, 0) << '\n';
}