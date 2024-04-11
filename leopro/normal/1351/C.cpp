#include <bits/stdc++.h>

#include <utility>

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
    class exit_exception : exception {};
    void answer(){}
    template<typename First, typename... Args>void answer(First&& val, Args&&... ans){cout << val << "\n"; answer(ans...); throw exit_exception();}
    struct autoint{ int x; autoint(int i):x(i){} autoint():x(0){cin >> x;} operator int(){return x;}                                               //NOLINT
        int operator--(){return --x;} int operator--(signed){return x--;} int operator ++(){return ++x;} int operator++(signed){return x++;} };   //NOLINT
    template<typename T>T gcd(T a, T b) { while (b) { T mod = a % b; a = b; b = mod; } return a; }
    template<typename T>vector<T> prefix_sum(const vector<T> &v, int from = 0) { vector<T> res(v.size()+1-from); res[0] = 0; for (int i = from; i < v.size(); ++i) res[i+1-from] = res[i-from] + v[i]; return res; }
}
//@formatter:on

void solve();

signed main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    do { try { solve(); } catch (exit_exception &) {}} while (--t);
    return 0;
}

struct dir {
    int x, y;
    int dx, dy;

    dir(int x, int y, int dx, int dy) : x(x), y(y), dx(dx), dy(dy) {}

    bool operator < (const dir &dir) const {
        if (x != dir.x) return x < dir.x;
        if (dx != dir.dx) return dx < dir.dx;
        if (dy != dir.dy) return dy < dir.dy;
        return y < dir.y;
    }
};

void solve() {
    string s;
    cin >> s;
    set<dir> dirs;
    int x = 0, y = 0;
    int ans = 0;
    for (char c : s){
        ans++;
        if (c == 'S'){
            if (dirs.find({x, y, 0, -1}) == dirs.end()) ans += 4;
            dirs.emplace(x, y, 0, -1);
            --y;
            dirs.emplace(x, y, 0, 1);
        }
        if (c == 'N'){
            if (dirs.find({x, y, 0, 1}) == dirs.end()) ans += 4;
            dirs.emplace(x, y, 0, 1);
            ++y;
            dirs.emplace(x, y, 0, -1);
        }
        if (c == 'W'){
            if (dirs.find({x, y, -1, 0}) == dirs.end()) ans += 4;
            dirs.emplace(x, y, -1, 0);
            --x;
            dirs.emplace(x, y, 1, 0);
        }
        if (c == 'E'){
            if (dirs.find({x, y, 1, 0}) == dirs.end()) ans += 4;
            dirs.emplace(x, y, 1, 0);
            ++x;
            dirs.emplace(x, y, -1, 0);
        }
    }
    answer(ans);
}