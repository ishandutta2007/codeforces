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
    template<typename T>ostream &operator<<(ostream &os, const vector<T> &v) { for (const T &t : v) {os << t << (whitespace(t) ? " " : ""); } return os; }
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
    cin >> t;
    do { try { solve(); } catch (ExitException) {}} while (--t);
    return 0;
}

void solve() {
    autoint n;
    autoread<vector<string>> s(n);
    set<string> set;
    for (string str : s) set.insert(str);
    vector<bool> has_reversed;
    for (string str : s) {
        string t = str;
        reverse(t.begin(), t.end());
        has_reversed.push_back(set.find(t) != set.end());
    }
    if (find_if(s.begin(), s.end(), [](string &s) { return s.front() != s.back(); }) == s.end() &&
        find_if(s.begin(), s.end(), [](string &s) { return s.front() == '0'; }) != s.end() &&
        find_if(s.begin(), s.end(), [](string &s) { return s.front() == '1'; }) != s.end())
        answer(-1);
    int cnt01 = count_if(s.begin(), s.end(), [](string &s) { return s.front() == '0' && s.back() == '1'; });
    int cnt10 = count_if(s.begin(), s.end(), [](string &s) { return s.front() == '1' && s.back() == '0'; });
    int k = (max(cnt01, cnt10) - min(cnt01, cnt10)) / 2;
    cout << k << "\n";
    for (int i = 0; i < n && k; ++i) {
        if (!has_reversed[i] && (cnt10 > cnt01 ? (s[i].front() == '1' && s[i].back() == '0') :
                                                 (s[i].front() == '0' && s[i].back() == '1'))) {
            cout << i + 1 << " ";
            k--;
        }
    }
    answer();
}