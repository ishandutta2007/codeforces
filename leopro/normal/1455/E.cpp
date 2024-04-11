#include <bits/stdc++.h>

namespace {
    using namespace std;
#define int long long

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

struct point {
    int x, y;

    point() = default;

    point(int x, int y) : x(x), y(y) {}

    friend istream &operator>>(istream &is, point &p) {
        is >> p.x >> p.y;
        return is;
    }

    int dist(point other) { return abs(x - other.x) + abs(y - other.y); }
};

int solve(vector<point> points, int x1, int x2, int y1, int y2) {
    vector<point> dest{{x1, y1},
                       {x1, y2},
                       {x2, y1},
                       {x2, y2}};
    int ans = 1e10;
    vector<int> ord{0, 1, 2, 3};
    do {
        int cur = 0;
        for (int i = 0; i < 4; ++i) cur += points[i].dist(dest[ord[i]]);
        ans = min(ans, cur);
    } while (next_permutation(ord.begin(), ord.end()));
    return ans;
}

void solve() {
    vector<point> points(4);
    cin >> points;
    vector<int> x(4), y(4);
    sort(points.begin(), points.end(), [&](point a, point b) { return a.x < b.x; });
    for (int i = 0; i < 4; ++i) x[i] = points[i].x;
    sort(points.begin(), points.end(), [&](point a, point b) { return a.y < b.y; });
    for (int i = 0; i < 4; ++i) y[i] = points[i].y;

    int ans = 1e10;

    ans = min(ans, solve(points, x[1], x[1] + (y[3] - y[0]), y[0], y[3]));
    ans = min(ans, solve(points, x[3], x[3] - (y[3] - y[0]), y[0], y[3]));

    ans = min(ans, solve(points, x[0], x[3], y[1], y[1] + (x[3] - x[0])));
    ans = min(ans, solve(points, x[0], x[3], y[3], y[3] - (x[3] - x[0])));

    cout << ans << '\n';
}