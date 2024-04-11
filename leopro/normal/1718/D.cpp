#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

#define answer(answer) { cout << (answer) << '\n'; return; }

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

using segment = pair<int, int>;
#define l first
#define r second

struct MaxTree {
    int n;
    vector<pair<int, int>> mx;

    MaxTree(vector<int> a) : n(a.size()), mx(2 * n) {
        for (int i = 0; i < n; ++i) mx[i + n] = {a[i], i};
        for (int i = n - 1; i > 0; --i) mx[i] = max(mx[2 * i], mx[2 * i + 1]);
    }

    int get(int l, int r) {
        auto res = pair{INT_MIN, -1};
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) res = max(res, mx[l++]);
            if (r & 1) res = max(res, mx[--r]);
        }
        return res.second;
    }
};

int assign(vector<segment> diapasons, vector<int> points) {
    sort(diapasons.rbegin(), diapasons.rend(), [](auto a, auto b) { return a.r < b.r; });
    sort(points.rbegin(), points.rend());
    priority_queue<segment> accessible;
    int i = 0;
    int any = 0;
    for (int pt: points) {
        while (i < diapasons.size() && pt < diapasons[i].r) {
            accessible.emplace(diapasons[i++]);
        }
        if (accessible.empty()) return -1;
        auto last = accessible.top();
        if (last.l >= pt) {
            any = last.r;
            accessible.pop();
        }
        if (accessible.empty() || accessible.top().l >= pt) return -1;
        accessible.pop();
    }
    while (i < diapasons.size()) {
        accessible.emplace(diapasons[i++]);
    }
    if (!accessible.empty()) any = accessible.top().r;
    return any;
}

vector<int> operator+(vector<int> a, int x) {
    a.push_back(x);
    return a;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> p(n);
    for (int &x: p) cin >> x;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    int k = count(a.begin(), a.end(), 0);
    vector<int> s(k - 1);
    for (int &x: s) cin >> x;

//    vector<int> xs(a.size() + s.size());
//    for (int i = 0; i < a.size(); ++i) xs[i] = a[i];
//    for (int i = 0; i < s.size(); ++i) xs[i + a.size()] = s[i];
//    sort(xs.begin(), xs.end());
//    xs.erase(unique(xs.begin(), xs.end()), xs.end());
//    for (int &x: a) x = lower_bound(xs.begin(), xs.end(), x) - xs.begin();
//    for (int &x: s) x = lower_bound(xs.begin(), xs.end(), x) - xs.begin();
//    int c = xs.size();

    vector<segment> diapasons;
    MaxTree mt(p);
    bool ok = true;
    auto solve = [&](auto solve, int l, int r, int max) -> int {
        if (l == r) return -1;
        int m = mt.get(l, r);
        int newMax = (a[m] ? a[m] : max);
        int min = std::max(solve(solve, l, m, newMax), solve(solve, m + 1, r, newMax));
        if (a[m] == 0) diapasons.emplace_back(min, max); else if (!(min < a[m] && a[m] < max)) ok = false;
        return std::max(min, a[m]);
    };
    solve(solve, 0, n, 2e6);
    int l, r;
    if (ok) {
        int any = assign(diapasons, s);
        l = [&] {
            int l = -1, r = any;
            while (r - l > 1) {
                int m = (l + r) / 2;
                if (assign(diapasons, s + m) == -1) l = m; else r = m;
            }
            return r;
        }();
        r = [&] {
            int l = any, r = 2e6;
            while (r - l > 1) {
                int m = (l + r) / 2;
                if (assign(diapasons, s + m) == -1) r = m; else l = m;
            }
            return l;
        }();
    }
    for (int j = 0; j < q; ++j) {
        int x;
        cin >> x;
        cout << (ok && l <= x && x <= r ? "YES" : "NO") << '\n';
    }
}