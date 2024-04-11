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
    template<typename T>ostream &operator<<(ostream &os, const vector<T> &v) { for (const T &t : v) {os << t + 1 << (whitespace(t) ? " " : ""); } os << '\n'; return os; }
    template<typename T>T gcd(T a, T b) { while (b) { T mod = a % b; a = b; b = mod; } return a; }
    template<typename C>void incr_sort(C &v) { stable_sort(v.begin(), v.end()); }
    template<typename C>void decr_sort(C &v) { stable_sort(v.rbegin(), v.rend()); }
    template<typename T>T sum(const vector<T> &v) { T s = 0; for (T value : v) s += value; return s; }
    template<typename T>vector<T> prefix_sum(const vector<T> &v) { vector<T> res(v.size()); res[0] = v[0]; for (int i = 1; i < v.size(); ++i) res[i] = res[i - 1] + v[i]; return res; }
    class ExitException : exception {};
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

struct Stage {
    int len;

    virtual void read(istream &is = cin) = 0;

    Stage(int len) : len(len) {}

    virtual int value(vector<Stage *> &stages, vector<int> &prefix_len, int idx) = 0;
};

int value(vector<Stage *> &stages, vector<int> &prefix_len, int idx);

struct Add : Stage {
    int x;

    void read(istream &is = cin) final {
        is >> x;
        len = 1;
    }

    Add(int x = 0) : x(x), Stage(1) {}

    int value(vector<Stage *> &stages, vector<int> &prefix_len, int idx) final {
        if (idx == 1) return x;
        return -1;
    }
};

struct Copy : Stage {
    int l, c;

    void read(istream &is = cin) {
        is >> l >> c;
        len = l * c;
    }

    Copy(int l = 0, int c = 0) : l(l), c(c), Stage(l * c){}

    int value (vector<Stage *> &stages, vector<int> &prefix_len, int idx) final {
        return ::value(stages, prefix_len, (idx - 1) % l + 1);
    }
};

int value(vector<Stage *> &stages, vector<int> &prefix_len, int idx){
    int L = 0, R = stages.size();
    while (R - L > 1){
        int m = (L + R) / 2;
        (prefix_len[m] < idx ? L : R) = m;
    }
    int stage = (prefix_len[R] < idx ? R : L);
    return stages[stage]->value(stages, prefix_len, idx - prefix_len[stage]);
}

void solve() {
    int m;
    cin >> m;
    vector<Stage *> stages(m);
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        if (x == 1) stages[i] = new Add(); else stages[i] = new Copy();
        stages[i]->read();
    }
    vector<int> prefix_len(m + 1);
    for (int i = 0; i < m; ++i) {
        prefix_len[i + 1] = prefix_len[i] + stages[i]->len;
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int idx;
        cin >> idx;
        cout << value(stages, prefix_len, idx) << " ";
    }
}