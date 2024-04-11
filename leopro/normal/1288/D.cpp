#include <bits/stdc++.h>

//@formatter:off
namespace {
    using namespace std;
#define int long long
    template<typename T>inline bool whitespace(const vector<T> &) { return false; }
    template<typename T>inline bool whitespace(const T &) { return true; }
    inline bool whitespace(const char) { return false; }
    template<typename S, typename T>ostream &operator<<(ostream &os, const pair<S, T> &p){ os << p.first << (whitespace(p.second) ? " " : "") << p.second << '\n'; return os;}
    template<typename S, typename T>istream &operator>>(istream &is, pair<S, T> &p){ is >> p.first >> p.second; return is;}
    template<typename T>istream &operator>>(istream &is, vector<T> &v) { for (T &t : v) is >> t; return is; }
    template<typename T>ostream &operator<<(ostream &os, const vector<T> &v) { for (const T &t : v) {os << t << (whitespace(t) ? " " : ""); } os << "\n"; return os; }
    template<typename T>istream &operator>>(istream &is, deque<T> &v) { for (T &t : v) is >> t; return is; }
    template<typename T>ostream &operator<<(ostream &os, const deque<T> &v) { for (const T &t : v) {os << t << (whitespace(t) ? " " : ""); } os << "\n"; return os; }
    template<typename T>T gcd(T a, T b) { while (b) { T mod = a % b; a = b; b = mod; } return a; }
    template<typename T>T sum(const vector<T> &v) { T s = 0; for (T value : v) s += value; return s; }
    template<typename T>vector<T> prefix_sum(const vector<T> &v) { vector<T> res(v.size()); res[0] = v[0]; for (int i = 1; i < v.size(); ++i) res[i] = res[i - 1] + v[i]; return res; }
    class ExitException : exception {};
    template<typename T>void answer(T ans, ostream &os = cout){os << ans << "\n"; throw ExitException();}
    void answer(ostream &os = cout){os << "\n"; throw ExitException();}
    istream &is = cin;
    struct autoint {int x; autoint() { is >> x; } operator int(){return x;}};
    template<typename T> struct autoread : T{template<typename... Args>autoread(Args&&... args): T(args...){ is >> *dynamic_cast<T *>(this);} };
}
//@formatter:on

void solve();

signed main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    do { try { solve(); } catch (ExitException &) {}} while (--t);
    return 0;
}

pair<int, int> ok(int m, int minmax, vector<vector<int>> &arrays) {
    vector<pair<int, int>> arr;
    for (int i = 0; i < arrays.size(); ++i) {
        int x = 0;
        for (int j = 0; j < arrays[i].size(); ++j) {
            x *= 2;
            x += arrays[i][j] >= minmax;
        }
        if (find_if(arr.begin(), arr.end(),
                    [x](pair<int, int> &y) { return x == y.first; }) == arr.end()) {
            arr.push_back({x, i});
        }
    }
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = i; j < arr.size(); ++j) {
            bool ans = true;
            if ((arr[i].first | arr[j].first) < (1 << (m)) - 1) ans = false;
            if (ans) return {arr[i].second + 1, arr[j].second + 1};
        }
    }
    return {-1, -1};
}

void solve() {
    autoint n, m;
    autoread<vector<vector<int>>> arrays(n, vector<int>(m));
    int L = 0, R = 1e9+1;
    while (R - L > 1) {
        int M = (L + R) / 2;
        (ok(m, M, arrays) != pair<int, int>{-1, -1} ? L : R) = M;
    }
    cout << ok(m, L, arrays);
}