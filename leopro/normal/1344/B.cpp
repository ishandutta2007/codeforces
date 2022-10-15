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
//    cin >> t;
    do { try { solve(); } catch (exit_exception &) {}} while (--t);
    return 0;
}

void dfs(vector<vector<char>> &board, vector<vector<int>> &comp, int i, int j, int c){
    if (comp[i][j] || board[i][j] == '.') return;
    comp[i][j] = c;
    dfs(board, comp, i - 1, j, c);
    dfs(board, comp, i + 1, j, c);
    dfs(board, comp, i, j - 1, c);
    dfs(board, comp, i, j + 1, c);
}

void solve() {
    autoint n, m;
    vector<vector<char>> board(n + 2, vector<char>(m + 2));
    for (int i = 0; i <= n + 1; ++i) for (int j = 0; j <= m + 1; ++j) board[i][j] = '.';
    for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j) cin >> board[i][j];

    bool empty_row = false;
    for (int i = 1; i <= n; ++i) {
        int wb = 0, bw = 0;
        for (int j = 1; j <= m + 1; ++j) {
            if (board[i][j] != board[i][j - 1]) {
                if (board[i][j] == '#') bw++; else wb++;
            }
        }
        if (wb == 0 && bw == 0) empty_row = true;
        if (wb > 1 || bw > 1) answer(-1);
    }
    bool empty_col = false;
    for (int j = 1; j <= m; ++j) {
        int wb = 0, bw = 0;
        for (int i = 1; i <= n + 1; ++i) {
            if (board[i][j] != board[i - 1][j]) {
                if (board[i][j] == '#') bw++; else wb++;
            }
        }
        if (wb == 0 && bw == 0) empty_col = true;
        if (wb > 1 || bw > 1) answer(-1);
    }


    if (empty_row ^ empty_col) answer(-1);
    vector<vector<int>> comp(n + 2, vector<int>(m + 2, 0));
    int c = 0;
    for (int i = 0; i <= n + 1; ++i){
        for (int j = 0; j <= m + 1; ++j){
            if (board[i][j] == '.') continue;
            if (comp[i][j]) continue;
            dfs(board, comp, i, j, ++c);
        }
    }
    cout << c << '\n';
}