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
    template<typename C>void incr_sort(C &v) { stable_sort(v.begin(), v.end()); }
    template<typename C>void decr_sort(C &v) { stable_sort(v.rbegin(), v.rend()); }
    template<typename T>T sum(const vector<T> &v) { T s = 0; for (T value : v) s += value; return s; }
    template<typename T>vector<T> prefix_sum(const vector<T> &v) { vector<T> res(v.size()); res[0] = v[0]; for (int i = 1; i < v.size(); ++i) res[i] = res[i - 1] + v[i]; return res; }
    class ExitException : exception {};
    template<typename T>void answer(T ans, ostream &os = cout){os << ans << "\n"; throw ExitException();}
    void answer(ostream &os = cout){os << "\n"; throw ExitException();}
    istream &is = cin;
    struct autoint {int x; autoint() {is >> x;} operator int(){return x;}};
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
    do { try { solve(); } catch (ExitException) {}} while (--t);
    return 0;
}

char third(char a, char b) {
    if (a == b) return a;
    return 'S' + 'E' + 'T' - a - b;
}

void solve() {
    autoint n;
    autoread<deque<int>> p(n);
    p.push_back(0);
    p.push_front(0);
    int complexity = 0;
    for (int i = 1; i < n + 2; ++i) if (p[i] && p[i - 1] && ((p[i] + p[i - 1]) & 1)) ++complexity;
    int ans = 1e5;
    for (int first = 1; first < 3; ++first) {
        for (int last = 1; last < 3; ++last) {
            int evens = n / 2, odds = n - n / 2;
            for (int i = 1; i < n + 1; ++i) if (p[i]) (p[i] % 2 == 0 ? evens : odds) -= 1;
            vector<vector<int>> lines(4);
            p.front() = first;
            p.back() = last;
            int length = 0, begin = 0, end = 0;
            for (int i = 1; i < n + 2; ++i) {
                if (!p[i]) {
                    ++length;
                    if (p[i - 1]) begin = p[i - 1];
                }
                if (end = p[i]) {
                    if (length) lines[(begin & 1) * 2 + (end & 1)].push_back(length);
                    length = 0;
                }
            }
            for (int j = 0; j < 4; ++j) incr_sort(lines[j]);
            int cur = lines[1].size() + lines[2].size();
            if (evens < sum(lines[0])){
                for (int j = 0; j < lines[0].size(); ++j) {
                    if (evens >= lines[0][j]) evens -= lines[0][j]; else cur += 2;
                }
            }
            if (odds < sum(lines[3])){
                for (int j = 0; j < lines[3].size(); ++j) {
                    if (odds >= lines[3][j]) odds -= lines[3][j]; else cur += 2;
                }
            }
            ans = min(ans, cur);
        }
    }
    answer(ans + complexity);
}