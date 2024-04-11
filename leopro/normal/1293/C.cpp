#include <bits/stdc++.h>

//@formatter:off
namespace {
    using namespace std;
#define int long long
    template<typename T>inline bool whitespace(const vector<T> &) { return false; }
    template<typename T>inline bool whitespace(const T &) { return true; }
    inline bool whitespace(const char) { return false; }
    template<typename S, typename T>ostream &operator<<(ostream &os, const pair<S, T> &p){ os << p.first << (whitespace(p.second) ? " " : "") << p.second << "\n"; return os;}
    template<typename S, typename T>istream &operator>>(istream &is, pair<S, T> &p){ is >> p.first >> p.second; return is;}
    template<typename T>istream &operator>>(istream &is, vector<T> &v) { for (T &t : v) is >> t; return is; }
    template<typename T>ostream &operator<<(ostream &os, const vector<T> &v) { for (const T &t : v) {os << t << (whitespace(t) ? " " : ""); } os << "\n"; return os; }
    template<typename T>istream &operator>>(istream &is, deque<T> &v) { for (T &t : v) is >> t; return is; }
    template<typename T>ostream &operator<<(ostream &os, const deque<T> &v) { for (const T &t : v) {os << t << (whitespace(t) ? " " : ""); } os << "\n"; return os; }
    template<typename T>T gcd(T a, T b) { while (b) { T mod = a % b; a = b; b = mod; } return a; }
    template<typename T>T sum(const vector<T> &v) { T s = 0; for (T value : v) s += value; return s; }
    template<typename T>vector<T> prefix_sum(const vector<T> &v) { vector<T> res(v.size()+1); res[0] = 0; for (int i = 0; i < v.size(); ++i) res[i+1] = res[i] + v[i]; return res; }
    class exit_exception : exception {};
    template<typename T>void answer(T ans, ostream &os = cout){os << ans << "\n"; throw exit_exception();}
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

struct Cell {
    int x, y;

    Cell(int x = 0, int y = 0) : x(x), y(y) {}

    const bool operator<(const Cell &cell) const {
        if (x != cell.x) return x < cell.x;
        return y < cell.y;
    }

    friend istream &operator>>(istream &is, Cell &c) {
        is >> c.x >> c.y;
        --c.x, c.y;
        return is;
    }

};

void insert(Cell a, Cell b, multiset<pair<Cell, Cell>> &set) {
    set.insert({a, b});
    set.insert({b, a});
}

pair<Cell, Cell> reverse(pair<Cell, Cell> p) { return {p.second, p.first}; }

void solve() {
    int n, q;
    cin >> n >> q;
    multiset<pair<Cell, Cell>> forbid;
    vector<vector<bool>> closed(2, vector<bool>(n + 2, false));
    for (int i = 0; i < q; ++i) {
        Cell f;
        cin >> f;
        closed[f.x][f.y] = !closed[f.x][f.y];
        if (closed[f.x][f.y]) {
            if (closed[1 - f.x][f.y + 0]) insert({1 - f.x, f.y + 0}, f, forbid);
            if (closed[1 - f.x][f.y - 1]) insert({1 - f.x, f.y - 1}, f, forbid);
            if (closed[1 - f.x][f.y + 1]) insert({1 - f.x, f.y + 1}, f, forbid);
        } else {
            pair<multiset<pair<Cell, Cell>>::iterator, multiset<pair<Cell, Cell>>::iterator> eq =
                    {forbid.upper_bound({f,{-1, -1}}), forbid.upper_bound({f, {n+2, n+2}})};
            vector<pair<Cell, Cell>> to_del;
            for (auto it = eq.first; it != eq.second; ++it) to_del.push_back(reverse(*it));
            for (auto it = eq.first; it != eq.second; ++it) to_del.push_back(*it);
            for (auto p : to_del) forbid.erase(p);
        }
        cout << (forbid.size() == 0 ? "Yes\n" : "No\n");
    }
}