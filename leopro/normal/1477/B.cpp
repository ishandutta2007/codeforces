#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

namespace {
    using namespace std;
#define int long long
    using ll = long long;

    template<typename T>
    inline bool whitespace(const vector<T> &) { return false; }

    template<typename T>
    inline bool whitespace(const T &) { return true; }

    inline bool whitespace(const char) { return false; }

    template<typename F, typename S>
    inline bool whitespace(const pair<F, S> &) { return false; }

    template<typename F, typename S>
    ostream &operator<<(ostream &os, const pair<F, S> &p) {
        os << p.first << (whitespace(p.second) ? " " : "") << p.second << "\n";
        return os;
    }

    template<typename F, typename S>
    istream &operator>>(istream &is, pair<F, S> &p) {
        is >> p.first >> p.second;
        return is;
    }

    template<typename T>
    istream &operator>>(istream &is, vector<T> &v) {
        for (T &t : v) is >> t;
        return is;
    }

    template<typename T>
    ostream &operator<<(ostream &os, const vector<T> &v) {
        for (const T &t : v) os << t << (whitespace(t) ? " " : "");
        os << "\n";
        return os;
    }

    template<typename T>
    istream &operator>>(istream &is, deque<T> &v) {
        for (T &t : v) is >> t;
        return is;
    }

    template<typename T>
    ostream &operator<<(ostream &os, const deque<T> &v) {
        for (const T &t : v) os << t << (whitespace(t) ? " " : "");
        os << "\n";
        return os;
    }

    class exit_exception : exception {
    };

    void answer() {}

    template<typename First, typename... Args>
    void answer(First &&val, Args &&... ans) {
        cout << val << "\n";
        answer(ans...);
        throw exit_exception();
    }

    struct autoint {
        int x;

        autoint(int i) : x(i) {}

        autoint() { cin >> x; }

        operator int() { return x; }

        int operator--() { return --x; }

        int operator--(signed) { return x--; }

        int operator++() { return ++x; }

        int operator++(signed) { return x++; }
    };
}

void solve();


signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    do { try { solve(); } catch (exit_exception &) {}} while (--t);
    return 0;
}

struct segment {
    int l, r;

    segment() {}

    segment(int l, int r) : l(l), r(r) {}

    friend istream &operator>>(istream &is, segment &s) {
        is >> s.l >> s.r;
        return is;
    }
};

struct segment_tree {
    vector<int> sum, mod;
    int n;

    explicit segment_tree(int n) : n(n), sum(2 * n), mod(n, -1) {}

    void apply(int i, int v, int sz) {
        if (i < mod.size()) mod[i] = v;
        sum[i] = sz * v;
    }

    void push(int i, int sz) {
        if (i >= mod.size() || mod[i] == -1) return;
        apply(2 * i, mod[i], sz / 2);
        apply(2 * i + 1, mod[i], sz / 2);
        mod[i] = -1;
    }

    void update(int i) {
        sum[i] = sum[2 * i] + sum[2 * i + 1];
    }

    void set(int l, int r, int v) {
        l += n, r += n;
        for (int h = 20; h >= 0; --h) {
            push(l >> h, 1 << h);
            push((r - 1) >> h, 1 << h);
        }
        for (int L = l, R = r, sz = 1; L < R; L /= 2, R /= 2, sz *= 2) {
            if (L & 1) apply(L++, v, sz);
            if (R & 1) apply(--R, v, sz);
        }
        for (int h = 1; h <= 20; ++h) {
            if (mod[l >> h] == -1) update(l >> h);
            if (mod[(r - 1) >> h] == -1) update((r - 1) >> h);
        }
    }

    int get(int l, int r) {
        l += n, r += n;
        for (int h = 20; h >= 0; --h) {
            push(l >> h, 1 << h);
            push((r - 1) >> h, 1 << h);
        }
        int res = 0;
        for (; l < r; l /= 2, r /= 2) {
            if (l & 1) res += sum[l++];
            if (r & 1) res += sum[--r];
        }
        return res;
    }
};

void solve() {
    autoint n, q;
    string s, f;
    cin >> s >> f;
    vector<segment> sg(q);
    cin >> sg;
    reverse(sg.begin(), sg.end());
    segment_tree fst(n);
    for (int i = 0; i < n; ++i) fst.set(i, i + 1, f[i] - '0');
    for (int j = 0; j < q; ++j) {
        int l = --sg[j].l;
        int r = sg[j].r;
        int len = r - l;
        int sm = fst.get(l, r);
        if (sm + sm == len) answer("NO");
        if (sm + sm < len) fst.set(l, r, 0); else fst.set(l, r, 1);
    }
    for (int i = 0; i < n; ++i) if (fst.get(i, i + 1) != s[i] - '0') answer("NO");
    answer("YES");
}