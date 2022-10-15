#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

struct group {
    vector<int> students;
    ll sum = 0;
    int sz;

    friend istream &operator>>(istream &is, group &g) {
        is >> g.sz;
        g.students.resize(g.sz);
        for (int &x: g.students) cin >> x, g.sum += x;
        return is;
    }

    auto operator<=>(const group &group) const {
        return sum * group.sz <=> group.sum * sz;
    }

    auto operator<=>(int x) const {
        return sum <=> x * 1LL * sz;
    }
};

struct SumTree {
    int n;
    vector<int> sum;

    explicit SumTree(int n) : n(n), sum(2 * n) {}

    void set(int i, int x) {
        sum[i += n] = x;
        for (i /= 2; i > 0; i /= 2) sum[i] = sum[2 * i] + sum[2 * i + 1];
    }

    bool all1(int l, int r) {
        return l >= r || get(l, r) == r - l;
    }

    int get(int l, int r) {
        int res = 0;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) res += sum[l++];
            if (r & 1) res += sum[--r];
        }
        return res;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    sort(a.rbegin(), a.rend());
    while (a.size() > m) a.pop_back();
    reverse(a.begin(), a.end());
    vector<group> g(m);
    for (auto &gr: g) cin >> gr;
    vector<int> indices(m);
    iota(indices.begin(), indices.end(), 0);
    sort(indices.begin(), indices.end(), [&](int i, int j) { return g[i] < g[j]; });
    vector<int> rev(m);
    for (int i = 0; i < m; ++i) rev[indices[i]] = i;
    SumTree here(m), left(m), right(m);
    for (int i = 0; i < m; ++i) {
        here.set(i, g[indices[i]] <= a[i]);
        if (i) left.set(i, g[indices[i]] <= a[i - 1]);
        if (i + 1 < m) right.set(i, g[indices[i]] <= a[i + 1]);
    }
    for (int i = 0; i < m; ++i) {
        for (int x: g[i].students) {
            group ng;
            ng.sum = g[i].sum - x;
            ng.sz = g[i].sz - 1;
            int pos = [&]() {
                if (ng >= g[indices[m - 1]]) return m;
                int l = -1, r = m;
                while (r - l > 1) {
                    int med = (l + r) / 2;
                    if (ng < g[indices[med]]) r = med; else l = med;
                }
                return r;
            }();

            bool ok = (ng <= a[pos - (pos > rev[i])]);
            if (pos < rev[i]) {
                ok &= here.all1(0, pos) && right.all1(pos, rev[i]) && here.all1(rev[i] + 1, m);
            } else {
                ok &= here.all1(0, rev[i]) && left.all1(rev[i] + 1, pos) && here.all1(max(pos, rev[i] + 1), m);
            }
            cout << ok;
        }
    }
    cout << '\n';
}