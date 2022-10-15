#include <bits/stdc++.h>

//@formatter:off
namespace {
    using namespace std;
#define int long long
    template<typename T>inline bool whitespace(const vector<T> &) { return false; }
    template<typename S, typename T>inline bool whitespace(const pair<S, T> &) { return false; }
    template<typename T>inline bool whitespace(const T &) { return true; }
    inline bool whitespace(const char) { return false; }
    template<typename S, typename T>ostream &operator<<(ostream &os, const pair<S, T> &p){ os << p.first << (whitespace(p.second) ? " " : "") << p.second << "\n"; return os;}
    template<typename S, typename T>istream &operator>>(istream &is, pair<S, T> &p){ is >> p.first >> p.second; return is;}
    template<typename T>istream &operator>>(istream &is, vector<T> &v) { for (T &t : v) is >> t; return is; }
    template<typename T>ostream &operator<<(ostream &os, const vector<T> &v) { for (const T &t : v) {os << t << (whitespace(t) ? " " : ""); } os << "\n"; return os; }
    template<typename T>istream &operator>>(istream &is, deque<T> &v) { for (T &t : v) is >> t; return is; }
    template<typename T>ostream &operator<<(ostream &os, const deque<T> &v) { for (const T &t : v) {os << t << (whitespace(t) ? " " : ""); } os << "\n"; return os; }
    template<typename T>T gcd(T a, T b) { while (b) { T mod = a % b; a = b; b = mod; } return a; }
    template<typename T>vector<T> prefix_sum(const vector<T> &v, int from = 0, int till = 0) { vector<T> res = vector<T>(v.size() + 1); for (int i = from; i + till < v.size(); ++i) { res[i - from + 1] = res[i - from] + v[i]; } return res; }
    class exit_exception : exception {};
    istream &in = cin; ostream &out = cout;
    void answer(){}
    template<typename First, typename... Args>void answer(First&& val, Args&&... ans){out << val << "\n"; answer(ans...); throw exit_exception();}
    struct autoint{ int x; autoint(int i):x(i){} autoint():x(0){in >> x;} operator int(){return x;}                                               //NOLINT
        int operator--(){return --x;} int operator--(signed){return x--;} int operator ++(){return ++x;} int operator++(signed){return x++;} };   //NOLINT
    template<typename T> struct autoread : T { template<typename... Args>autoread(Args&&... args): T(args...){ in >> *dynamic_cast<T *>(this);} };//NOLINT
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

struct cell {
    int x, y;

    friend istream &operator>>(istream &is, cell &c) {
        is >> c.x >> c.y;
        --c.x, --c.y;
        return is;
    }

    bool operator==(const cell &c) const {
        return x == c.x && y == c.y;
    }

    bool operator!=(const cell &c) const {
        return x != c.x || y != c.y;
    }

    cell(int x = 0, int y = 0) : x(x), y(y) {}
};

bool valid(int i, int j, int n) {
    return i >= 0 && j >= 0 && i < n && j < n;
}

void dfs(const vector<vector<cell>> &a, vector<vector<char>> &board, int i, int j) {
    int n = a.size();
    if (valid(i, j + 1, n) && a[i][j + 1] == a[i][j] && board[i][j + 1] == 'X' && a[i][j + 1] != cell(i, j + 1)) {
        board[i][j + 1] = 'L';
        dfs(a, board, i, j + 1);
    }
    if (valid(i + 1, j, n) && a[i + 1][j] == a[i][j] && board[i + 1][j] == 'X' && a[i + 1][j] != cell(i + 1, j)) {
        board[i + 1][j] = 'U';
        dfs(a, board, i + 1, j);
    }
    if (valid(i, j - 1, n) && a[i][j - 1] == a[i][j] && board[i][j - 1] == 'X' && a[i][j - 1] != cell(i, j - 1)) {
        board[i][j - 1] = 'R';
        dfs(a, board, i, j - 1);
    }
    if (valid(i - 1, j, n) && a[i - 1][j] == a[i][j] && board[i - 1][j] == 'X' && a[i - 1][j] != cell(i - 1, j)) {
        board[i - 1][j] = 'D';
        dfs(a, board, i - 1, j);
    }
}

void solve() {
    autoint n;
    autoread<vector<vector<cell>>> a(n, vector<cell>(n));
    vector<vector<char>> board(n, vector<char>(n, 'X'));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == cell(i, j)) {
                dfs(a, board, i, j);
            }
            if (a[i][j] == cell(-2, -2)) {
                if (valid(i, j + 1, n) && a[i][j + 1] == a[i][j]) board[i][j] = 'R';
                if (valid(i + 1, j, n) && a[i + 1][j] == a[i][j]) board[i][j] = 'D';
                if (valid(i, j - 1, n) && a[i][j - 1] == a[i][j]) board[i][j] = 'L';
                if (valid(i - 1, j, n) && a[i - 1][j] == a[i][j]) board[i][j] = 'U';
                if (board[i][j] == 'X') answer("INVALID");
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) if (a[i][j] != cell(i, j) && board[i][j] == 'X')answer("INVALID");
    }
    cout << "VALID\n";
    for (const auto &row : board) {
        for (char v : row) {
            cout << v;
        }
        cout << "\n";
    }
}