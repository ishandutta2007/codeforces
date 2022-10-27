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

template<typename T, typename U>
struct SegmentTree {
    int n;
    T neutral;
    U unite;
    vector<T> data;

    template<typename I>
    SegmentTree(int n, T neutral, U unite, I init) : n(n), neutral(neutral), unite(unite), data(2 * n) {
        for (int i = 0; i < n; ++i) data[i + n] = init(i);
        for (int i = n - 1; i > 0; --i) data[i] = unite(data[2 * i], data[2 * i + 1]);
    }

    SegmentTree(int n, T neutral, U unite) : n(n), neutral(neutral), unite(unite), data(2 * n, neutral) {}

    void set(int i, T x) {
        data[i += n] = x;
        for (i /= 2; i > 0; i /= 2) data[i] = unite(data[2 * i], data[2 * i + 1]);
    }

    T get(int l, int r) {
        T leftRes = neutral, rightRes = neutral;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) leftRes = unite(leftRes, data[l++]);
            if (r & 1) rightRes = unite(data[--r], rightRes);
        }
        return unite(leftRes, rightRes);
    }
};

mt19937 rng(566);
const int MX = .7e4;

struct qu {
    int t, l, r, k;

    friend istream &operator>>(istream &is, qu &q) {
        is >> q.t;
        if (q.t == 1) {
            is >> q.l >> q.k;
        } else {
            is >> q.l >> q.r >> q.k;
        }
        return is;
    }
};

void solve() {
    const int aaa = 30;
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &x: a) {
        cin >> x;
    }
    vector<qu> qu(q);
    for (auto &r: qu) cin >> r;
    vector<int> all;
    for (int x: a) all.push_back(x);
    for (auto &[t, l, r, k]: qu) if (t == 1) all.push_back(k);
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    vector<vector<int>> ens(aaa, vector<int>(all.size()));
    for (int i = 0; i < aaa; ++i) { for (int j = 0; j < all.size(); ++j) ens[i][j] = rng() % MX; }
    auto ensure = [&](int i, int x) -> int {
        int idx = lower_bound(all.begin(), all.end(), x) - all.begin();
        return ens[i][idx];
    };
    vector st(aaa, SegmentTree(n, 0, [](int x, int y) { return x + y; }));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < aaa; ++j) st[j].set(i, ensure(j, a[i]));
    }
    for (int tc = 0; tc < q; ++tc) {
        auto[t, l, r, k]=qu[tc];
        if (t == 1) {
            int i = l, x = k;
            --i;
            for (int j = 0; j < aaa; ++j) st[j].set(i, ensure(j, x));
            a[i] = x;
        } else if (t == 2) {
            --l;
            bool ok = true;
            if ((r - l) % k != 0) ok = false;
            for (int j = 0; j < aaa; ++j) {
                if (!ok) break;
                int s = st[j].get(l, r);
                if (s % k != 0) ok = false;
            }
            cout << (ok ? "YES" : "NO") << '\n';
        }
    }
}