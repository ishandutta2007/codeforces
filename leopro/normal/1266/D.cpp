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
    template<typename T>ostream &operator<<(ostream &os, const vector<T> &v) { for (const T &t : v) {os << t << (whitespace(t) ? " " : ""); } os << '\n'; return os; }
    template<typename T>T gcd(T a, T b) { while (b) { T mod = a % b; a = b; b = mod; } return a; }
    template<typename C>void incr_sort(C &v) { stable_sort(v.begin(), v.end()); }
    template<typename C>void decr_sort(C &v) { stable_sort(v.rbegin(), v.rend()); }
    template<typename T>T sum(const vector<T> &v) { T s = 0; for (T value : v) s += value; return s; }
    template<typename T>vector<T> prefix_sum(const vector<T> &v) { vector<T> res(v.size()); res[0] = v[0]; for (int i = 1; i < v.size(); ++i) res[i] = res[i - 1] + v[i]; return res; }
    class ExitException : exception {};
    template<typename T>void answer(T ans, ostream &os = cout){os << ans << "\n"; throw ExitException();}}
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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> company(n);
    for (int i = 0; i < m; ++i) {
        int u, v, d;
        cin >> u >> v >> d;
        --u, --v;
        company[u] -= d;
        company[v] += d;
    }
    vector<pair<int, int>> left, right;
    for (int i = 0; i < n; ++i) {
        if (company[i] < 0) left.emplace_back(i, -company[i]);
        if (company[i] >= 0) right.emplace_back(i, company[i]);
    }
    int a = 0, b = 0;
    vector<pair<pair<int, int>, int>> ans;
    while (a < left.size() && b < right.size()){
        while(a < left.size() && left[a].second == 0)++a;
        while(b < right.size() && right[b].second == 0)++b;
        if (a == left.size() || b == right.size()) break;
        if (left[a].second < right[b].second) {
            ans.push_back({{left[a].first + 1, right[b].first + 1}, left[a].second});
            right[b].second -= left[a].second;
            ++a;
        } else {
            ans.push_back({{left[a].first + 1, right[b].first + 1}, right[b].second});
            left[a].second -= right[b].second;
            ++b;
        }
    }

    cout << count_if(ans.begin(), ans.end(), [](pair<pair<int, int>, int> x){return x.second != 0;}) << "\n";
    for (auto x : ans) {
        if (x.second == 0) continue;
       cout << x.first.first << " " << x.first.second << " " << x.second << "\n";
    }
}