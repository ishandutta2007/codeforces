#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

#define answer(out) { cout <<  (out) << '\n'; return; }
#define answerExit(out) { cout << (out) << '\n'; exit(0); }

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

int cur = 0;

int query(int x) {
    cur += x;
    cout << "? " << x << endl;
    int y;
    cin >> y;
    return y;
}

template<typename T, typename U>
struct RangeTree {
    int n;
    T neutral;
    U unite;
    vector<T> data;

    template<typename I>
    RangeTree(int n, T neutral, U unite, I init) : n(n), neutral(neutral), unite(unite), data(2 * n) {
        for (int i = 0; i < n; ++i) data[i + n] = init(i);
    }

    RangeTree(int n, T neutral, U unite) : n(n), neutral(neutral), unite(unite), data(2 * n, neutral) {}

    void apply(int i, T x) {
        data[i] = unite(data[i], x);
    }

    void apply(int l, int r, T x) {
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) apply(l++, x);
            if (r & 1) apply(--r, x);
        }
    }

    T get(int i) const {
        T res = neutral;
        for (i += n; i > 0; i /= 2) res = unite(res, data[i]);
        return res;
    }
};


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    map<int, vector<int>> p;
    for (int i = 0; i < n; ++i) p[a[i]].push_back(i);
    for (int x = 1; x <= n + 2; ++x) p[x].push_back(-1), p[x].push_back(n);
    for (auto &[u, v]: p) sort(v.begin(), v.end());
    RangeTree right(n + 2, 0, [](int a, int b) { return max(a, b); }, [](int i) { return i; });
    for (int x = 1;; ++x) {
        auto v = p[x];
        bool ok = false;
        for (int i = 1; i < v.size(); ++i) {
            int l = v[i - 1] + 1, r = v[i];
            int rg = right.get(l);
            if (rg < r) ok = true;
        }
        if (!ok) answer(x);
        for (int i = 1; i < v.size(); ++i) {
            int l = v[i - 1] + 1, r = v[i];
            right.apply(l, r, r);
        }
    }

}