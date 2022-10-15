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
        for (const T &t : v) {
            os << t << (whitespace(t) ? " " : "");
        }
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
        for (const T &t : v) {
            os << t << (whitespace(t) ? " " : "");
        }
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

        autoint() : x(0) { cin >> x; }

        operator int() { return x; }                                               //NOLINT
        int operator--() { return --x; }

        int operator--(signed) { return x--; }

        int operator++() { return ++x; }

        int operator++(signed) { return x++; }
    };   //NOLINT
    template<typename T>
    T gcd(T a, T b) {
        while (b) {
            T mod = a % b;
            a = b;
            b = mod;
        }
        return a;
    }

    template<typename T>
    vector<T> prefix_sum(const vector<T> &v, int from = 0) {
        vector<T> res(v.size() + 1 - from);
        res[0] = 0;
        for (int i = from; i < v.size(); ++i) res[i + 1 - from] = res[i - from] + v[i];
        return res;
    }
}

void solve();

signed main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    do { try { solve(); } catch (exit_exception &) {}} while (--t);
    return 0;
}

#define x first
#define y second

void solve() {
    autoint n, m;
    vector<pair<int, int>> men(n), lights(m);
    cin >> men >> lights;
    for (auto &l : lights) l.x++;
    for (auto &l : lights) l.y++;
    vector<int> compressed;

    stable_sort(lights.begin(), lights.end());
    vector<pair<int, int>> new_lights(1, lights[0]);
    for (int i = 1; i < lights.size(); ++i) {
        if (lights[i].y >= new_lights.back().y) continue;
        new_lights.push_back(lights[i]);
    }

    vector<vector<pair<int, int>>> xy(n);
    for (int l = 0; l <= new_lights.size(); ++l) {
        for (int i = 0; i < n; ++i) {
            xy[i].emplace_back((l ? new_lights[l - 1].x : (int) -1e9) - men[i].x,
                               (l == new_lights.size() ? (int) -1e9 : new_lights[l].y) - men[i].y);
        }
    }
    vector<vector<pair<int, int>>> points(1e6 + 3);
    for (int i = 0; i < n; ++i) {
        for (int s = 0; s < xy[i].size(); ++s) if (xy[i][s].x >= 0) points[xy[i][s].x].push_back({i, s});
    }

    int y = 0;
    int ans = 1e9;
    for (int x = 1e6 + 1; x >= 0; --x) {
        for (auto p : points[x + 1]) {
            y = max(y, xy[p.first][p.second - 1].y);
        }
        ans = min(ans, x + y);
    }
    answer(ans);
}