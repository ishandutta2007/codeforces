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
    // cin >> t;
    do { try { solve(); } catch (exit_exception &) {}} while (--t);
    return 0;
}

struct point {
    int x, y;
    int i;

    point() {}

    point(int x, int y) : x(x), y(y) {}

    friend istream &operator>>(istream &is, point &s) {
        is >> s.x >> s.y;
        return is;
    }

    bool operator==(const point &point) const {
        return i == point.i;
    }

    point operator-(point other) { return {x - other.x, y - other.y}; }
};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long scalar(point a, point b) { return a.x * b.x + a.y * b.y; }

long long dist(point a, point b) { return scalar(a - b, a - b); }

void solve() {
    autoint n;
    vector<point> pts(n);
    cin >> pts;
    for (int i = 0; i < n; ++i) pts[i].i = i;
    vector<point> ans{pts[0]};
    pts.erase(pts.begin());
    while (!pts.empty()) {
        vector<point> half_plane;
        point cur = ans.back();
        for (auto pt : pts) {
            if (ans.size() == 1 || scalar(cur - (*-- --ans.end()), pt - cur) < 0) {
                half_plane.push_back(pt);
            }
        }

        point farthest = *max_element(half_plane.begin(), half_plane.end(),
                                      [cur](point p, point q) { return dist(cur, p) < dist(cur, q); });
        ans.push_back(farthest);
        pts.erase(find(pts.begin(), pts.end(), farthest));
    }
    for (point &x : ans) cout << ++x.i << ' ';
    cout << '\n';
}