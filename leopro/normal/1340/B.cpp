#include <bits/stdc++.h>

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
    template<typename T>T gcd(T a, T b) { while (b) { T mod = a % b; a = b; b = mod; } return a; }
    template<typename T>vector<T> prefix_sum(const vector<T> &v, int from = 0) { vector<T> res(v.size()+1-from); res[0] = 0; for (int i = from; i < v.size(); ++i) res[i+1-from] = res[i-from] + v[i]; return res; }
    template<typename F, typename S>F min(F a, S b){return a < (F)b ? a : b; }
    template<typename F, typename S>F max(F a, S b){return a < (F)b ? b : a; }
    class exit_exception : exception {};
    istream &in = cin; ostream &out = cout;
    template<typename T>void answer(T ans){out << ans << "\n"; throw exit_exception();}
    struct autoint{int x; autoint(){in >> x;} operator int(){return x;} autoint(autoint &i){x = i.x;} int operator=(int i){ return x = i; }
        int operator--(){return --x;} int operator--(signed){return x--;} int operator ++(){return ++x;} int operator++(signed){return x++;} };
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

struct val {
    int digit;
    int i, j;

    val(int d = -1, int i = -1, int j = -1) : digit(d), i(i), j(j) {}
};

int dist(const string &source, const string &dest) {
    int ans = 0;
    for (int i = 0; i < source.size(); ++i) {
        if (source[i] == '0' && dest[i] == '1') return 1e9;
        if (source[i] == '1' && dest[i] == '0') ans++;
    }
    return ans;
}

void solve() {
    autoint n, k;
    vector<string> digit(
            {"1110111", "0010010", "1011101", "1011011", "0111010",
             "1101011", "1101111", "1010010", "1111111", "1111011"});
    vector<string> cur(n);
    cin >> cur;
    vector<vector<int>> distance(10, vector<int>(n, 1e9));
    for (int i = 0; i < n; ++i) {
        for (int d = 0; d <= 9; ++d) {
            distance[d][i] = dist(digit[d], cur[i]);
        }
    }

    vector<vector<bool>> dp(n + 1, vector<bool>(k + 1));
    dp[n][0] = true;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j <= k; ++j) {
            for (int d = 0; d <= 9; ++d) {
                if (j >= distance[d][i]) {
                    dp[i][j] = dp[i][j] || dp[i + 1][j - distance[d][i]];
                }
            }
        }
    }
    if (!dp[0][k]) answer(-1);
    int rem = k;
    for (int i = 0; i < n; ++i) {
        int best = -1;
        for (int d = 0; d <= 9; ++d) {
            if (rem >= distance[d][i] && dp[i + 1][rem - distance[d][i]]) best = d;
        }
        cout << best;
        rem -= distance[best][i];
    }
}