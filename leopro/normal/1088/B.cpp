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
 
void my_sort(vector<int>::iterator first, vector<int>::iterator last) {
    int size = last - first;
    vector<vector<int>> buckets(size);
    auto min = *min_element(first, last);
    auto max = *max_element(first, last);
    if (min == max) {
        fill(first, last, min);
        return;
    }
    for (auto it = first; it != last; ++it) {
        if (*it == max)
            buckets[size - 1].push_back(*it);
        else
            buckets[(*it - min) * size / (max - min)].push_back(*it);
    }
    for (auto &b : buckets) {
        if (b.size() == 2 && b[0] > b[1])swap(b[0], b[1]);
        if (b.size() > 2) my_sort(b.begin(), b.end());
    }
    for (auto b : buckets) {
        auto it = b.begin();
        while (it != b.end()) *first++ = *it++;
    }
}
 
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    cin >> a;
    vector<int> b(n);
    for (int i = 0; i < 10; ++i) {
        b = a;
        my_sort(b.begin(), b.end());
    }
    a.push_back(0);
    my_sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    for (int i = 1; i < k + 1; ++i) {
        cout << (i < a.size() ? a[i] - a[i - 1] : 0) << "\n";
    }
}