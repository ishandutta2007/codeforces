#include <bits/stdc++.h>
 
//@formatter:off
namespace {
#define int long long
    using namespace std;
    template<typename T>inline bool whitespace(const vector<T> &) { return false; }
    template<typename T>inline bool whitespace(const T &) { return true; }
    inline bool whitespace(const char) { return false; }
    template<typename S, typename T>ostream &operator<<(ostream &os, const pair<S, T> &p){ os << p.first << (whitespace(p.second) ? " " : "") << p.second << '\n'; return os;}
    template<typename S, typename T>istream &operator>>(istream &is, pair<S, T> &p){ is >> p.first >> p.second; return is;}
    template<typename T>istream &operator>>(istream &is, vector<T> &v) { for (T &t : v) is >> t; return is; }
    template<typename T>ostream &operator<<(ostream &os, const vector<T> &v) { for (const T &t : v) {os << t << (whitespace(t) ? " " : ""); } os << '\n'; return os; }
    template<typename T>T gcd(T a, T b) { while (b) { T mod = a % b; a = b; b = mod; } return a; }
    template<typename C>void incr_sort(C &v) { stable_sort(v.begin(), v.end()); }
    template<typename C>void decr_sort(C &v) { stable_sort(v.rbegin(), v.rend()); }
    template<typename T>T sum(const vector<T> &v) { T s = 0; for (T value : v) s += value; return s; }
    template<typename T>vector<T> prefix_sum(const vector<T> &v) { vector<T> res(v.size()); res[0] = v[0]; for (int i = 1; i < v.size(); ++i) res[i] = res[i - 1] + v[i]; return res; }
    class ExitException : exception {};
    template<typename T>void answer_ref(T &ans, ostream &os = cout){os << ans << "\n"; throw ExitException();}
    template<typename T>void answer(T ans, ostream &os = cout){os << ans << "\n"; throw ExitException();}
    const char *to_string(const vector<int> &v){ostringstream ss; for (const auto &item : v) ss << item << (whitespace(item) ? " " : ""); return ss.str().c_str();}
    const char *to_string(const vector<vector<int>> &v){string *s = new string; for (const auto & item : v) *s += string(to_string(item)) + "   "; return s->c_str();}
    const char *to_string(const pair<int, int> &p){ostringstream ss; ss << p.first << ", " << p.second; return ss.str().c_str();}
//    const char *to_string(const pair<int, vector<int>> &p){ostringstream ss; ss << p.first << ", " << p.second; return ss.str().c_str();}
    const char *to_string(const map<int, int> &m){ostringstream ss; for (const auto & item : m) ss << "(" << item << ") "; return ss.str().c_str();}
//    const char *to_string(const map<int, vector<int>> &m){ostringstream ss; for (const auto & item : m) ss << "(" << item << ") "; return ss.str().c_str();}
    const char *to_string(const set<int> &s){ostringstream ss; for (const auto & item : s) ss << "(" << item << ") "; return ss.str().c_str();}
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
 
const int inf = 1e18;
 
void solve() {
    int n, k;
    cin >> n >> k;
    vector<bool> is_free(n);
    for (int i = 0; i < n; ++i) {
        char x;
        cin >> x;
        is_free[i] = x == '0';
    }
    vector<int> free;
    free.reserve(n);
    for (int i = 0; i < n; ++i){
        if (is_free[i]) free.push_back(i);
    }
    int ans = inf;
    for (int i = 0; i < free.size() - k; ++i){
        int L = i, R = i + k;
        while (R - L > 1){
            int m = (L + R) / 2;
            int dist1 = free[i + k] - free[m];
            int dist2 = free[m] - free[i]; 
            (dist1 > dist2 ? L : R) = m;
        }
        int dist1 = free[i + k] - free[L];
        int dist2 = free[L] - free[i]; 
        ans = min(ans, max(dist1, dist2));
        dist1 = free[i + k] - free[R];
        dist2 = free[R] - free[i]; 
        ans = min(ans, max(dist1, dist2));
    }
    cout << ans << "\n";
}