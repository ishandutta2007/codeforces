#include <bits/stdc++.h>

//@formatter:off
namespace {
    using namespace std;
//    #define int long long
    template<typename T>inline bool whitespace(const vector<T> &) { return false; }
    template<typename T>inline bool whitespace(const T &) { return true; }
    inline bool whitespace(const char) { return false; }
    template<typename S, typename T>ostream &operator<<(ostream &os, const pair<S, T> &p){ os << p.first << (whitespace(p.second) ? " " : "") << p.second << '\n'; return os;}
    template<typename S, typename T>istream &operator>>(istream &is, pair<S, T> &p){ is >> p.first >> p.second; return is;}
    template<typename T>istream &operator>>(istream &is, vector<T> &v) { for (T &t : v) is >> t; return is; }
    template<typename T>ostream &operator<<(ostream &os, const vector<T> &v) { for (const T &t : v) {os << t << (whitespace(t) ? " " : ""); } os << "\n"; return os; }
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

pair<int, int> pos(int i, int p, int q) {
    if (p == q) return {i % p, (i % p + (i / p) + q) % q};
    return {i % p, (i % p - (i / p) + q) % q};
}

void answer(int p, int q, map<int, int> &count) {
    vector<pair<int, int>> pairs;
    for (auto p : count) pairs.push_back(p);
    stable_sort(pairs.begin(), pairs.end(),
                [](const pair<int, int> &p1, const pair<int, int> &p2) { return p1.second > p2.second; });
    vector<vector<int>> ans(p, vector<int>(q));
    auto it = pairs.begin();
    for (int i = 0; i < p * q; ++i) {
        if (!it->second) ++it;
        if (it->second > p) it->second = p;
        pair<int, int> point = pos(i, p, q);
        ans[point.first][point.second] = it->first;
        --it->second;
    }
    answer(ans);
}

int countsums(vector<int> &sorted_counts, vector<int> &prefixsum, int max) {
    auto i = lower_bound(sorted_counts.begin(), sorted_counts.end(), max);
    if (i == sorted_counts.begin()) return max * sorted_counts.size();
    return prefixsum[i - sorted_counts.begin() - 1] + max * (sorted_counts.size() - (i - sorted_counts.begin()));
}

void solve() {
    autoint n;
    map<int, int> count;
    for (int i = 0; i < n; ++i) count[autoint()]++;
    vector<int> counts;
    for (auto pair : count) counts.push_back(pair.second);
    vector<int> sums(sqrt(n.x) + 2, 0);
    incr_sort(counts);
    auto prefixsum = prefix_sum(counts);
    for (int i = 0; i < sums.size(); ++i) sums[i] = countsums(counts, prefixsum, i);
    int S = 0;
    pair<int, int> params;
    for (int p = 1; p * p <= n; ++p) {
        int q = sums[p] / p;
        if (p > q) break;
        if (S < p * q) {
            S = p * q;
            params = {p, q};
        }
    }
    cout << S << "\n" << params;
    answer(params.first, params.second, count);
}