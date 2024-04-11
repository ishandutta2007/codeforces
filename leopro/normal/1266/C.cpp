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
//struct Person;
//struct Debt{
//    Person *p;
//    int v;
//
//    Debt(Person *p, int v) : p(p), v(v){}
//};
//
//struct Person{
//    vector<Debt> friends1;
//    vector<Debt> friends2;
//    int n;
//};
//
//void solve() {
//    int n, m;
//    cin >> n >> m;
//    vector<Person> company(n);
//    for (int i = 0; i < n; ++i)company[i].n = i;
//    for (int i = 0; i < m; ++i) {
//        int u, v, d;
//        cin >> u >> v >> d;
//        --u, --v;
//        company[u].friends1.push_back({&company[v], d});
//        company[v].friends2.push_back({&company[u], d});
//    }
//    for (int i = 0; i < n; ++i) {
//        int sum1 = 0;
//        for (int j = 0; j < company[i].friends1.size(); ++j) sum1 += company[i].friends1[j].v;
//        for (int j = 0; j < company[i].friends1.size(); ++j) sum2 += company[i].friends1[j].v;
//    }
//}

void solve(){
    int r, c;
    cin >> r >> c;
    if (r == 1 && c == 1){
        answer(0);
    }
    if (r == 1){
        vector<int> ans(c);
        for (int i = 0; i < c; ++i)ans[i] = i + 2;
        answer(ans);
    }
    if (c == 1){
        vector<vector<int>> ans(r);
        for (int i = 0; i < r; ++i)ans[i].push_back(i + 2);
        answer(ans);
    }
    for (int i = 1; i < r + 1; ++i) {
        for (int j = r + 1; j < r + c + 1; ++j) {
            cout << i * j << " ";
        }
        cout << "\n";
    }
}