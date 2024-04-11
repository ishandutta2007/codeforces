#include <bits/stdc++.h>

//@formatter:off
namespace {
    using namespace std;
#define int long long
    template<typename T>inline bool whitespace(const vector<T> &) { return false; }
    template<typename T>inline bool whitespace(const T &) { return true; }
    inline bool whitespace(const char) { return false; }
    template<typename F, typename S>inline bool whitespace(const pair<F, S> &) { return false; }
    template<typename F, typename S>ostream &operator<<(ostream &os, const pair<F, S> &p){ os << p.first << (whitespace(p.second) ? " " : "") << p.second << "\n"; return os;}
    template<typename F, typename S>istream &operator>>(istream &is, pair<F, S> &p){ is >> p.first >> p.second; return is;}
    template<typename T>istream &operator>>(istream &is, vector<T> &v) { for (T &t : v) is >> t; return is; }
    template<typename T>ostream &operator<<(ostream &os, const vector<T> &v) { for (const T &t : v) {os << t << (whitespace(t) ? " " : ""); } os << "\n"; return os; }
    template<typename T>istream &operator>>(istream &is, deque<T> &v) { for (T &t : v) is >> t; return is; }
    template<typename T>ostream &operator<<(ostream &os, const deque<T> &v) { for (const T &t : v) {os << t << (whitespace(t) ? " " : ""); } os << "\n"; return os; }
    template<typename T>T gcd(T a, T b) { while (b) { T mod = a % b; a = b; b = mod; } return a; }
    template<typename T>vector<T> prefix_sum(const vector<T> &v, int from = 0) { vector<T> res(v.size()+1-from); res[0] = 0; for (int i = from; i < v.size(); ++i) res[i+1-from] = res[i-from] + v[i]; return res; }
    template<typename F, typename S>F min(F a, S b){return a < (F)b ? a : b; }
    template<typename F, typename S>F max(F a, S b){return a < (F)b ? b : a; }
    class exit_exception : exception {};
    istream &in = cin; ostream &out = cout;
    template<typename T>void answer(T ans){out << ans << "\n"; throw exit_exception();}
    struct autoint{int x; autoint(){in >> x;} operator int(){return x;} autoint(autoint &i){x = i.x;} int operator=(int i){ return x = i; }
        int operator--(){return --x;} int operator--(signed){return x--;} int operator ++(){return ++x;} int operator++(signed){return x++;} };
}
//@formatter:on

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

struct treasure {
    int x, y, dist;

    treasure(int i, int j) : x(i), y(j), dist(1e18) {}

    bool operator<(const treasure &treasure) const {
        if (x != treasure.x) return x < treasure.x;
        return y < treasure.y;
    }

    bool operator<(int c) const {
        return y < c;
    }
};

void find_min(treasure &t, const vector<vector<treasure>> &f) {
    for (const auto &row : f) {
        auto low = lower_bound(row.begin(), row.end(), t.y);
        auto high = low - 1;
        if (low != row.end()) t.dist = min(t.dist, low->dist + abs(low->x - t.x) + abs(low->y - t.y));
        if (low != row.begin()) t.dist = min(t.dist, high->dist + abs(high->x - t.x) + abs(high->y - t.y));
    }
}

void solve() {
    autoint n, m, p;
    vector<vector<int>> treasures(n, vector<int>(m));
    cin >> treasures;
    vector<vector<vector<treasure>>> points(p + 1);
    vector<int> opened(p + 1, -1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (opened[treasures[i][j]] < i) {
                points[treasures[i][j]].emplace_back();
                opened[treasures[i][j]] = i;
            }
            points[treasures[i][j]].back().emplace_back(i, j);
        }
    }
    for (auto &v : points[1]) for (auto &t : v) t.dist = t.x + t.y;
    for (int cur = 2; cur <= p; ++cur) {
        for (auto &v : points[cur]) {
            for (auto &t : v) {
                find_min(t, points[cur - 1]);
            }
        }
    }
    int ans = 0;
    for (auto &t : points[p]) if (!t.empty()) ans = t[0].dist;
    cout << ans << '\n';
}