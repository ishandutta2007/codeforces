#include <bits/stdc++.h>

//@formatter:off
namespace {
    using namespace std;
#define int long long
    template<typename T>inline bool whitespace(const vector<T> &) { return false; }
    template<typename T>inline bool whitespace(const T &) { return true; }
    inline bool whitespace(const char) { return false; }
    template<typename S, typename T>ostream &operator<<(ostream &os, const pair<S, T> &p){ os << p.first << (whitespace(p.second) ? " " : "") << p.second << "\n"; return os;}
    template<typename S, typename T>istream &operator>>(istream &is, pair<S, T> &p){ is >> p.first >> p.second; return is;}
    template<typename T>istream &operator>>(istream &is, vector<T> &v) { for (T &t : v) is >> t; return is; }
    template<typename T>ostream &operator<<(ostream &os, const vector<T> &v) { for (const T &t : v) {os << t << (whitespace(t) ? " " : ""); } os << "\n"; return os; }
    template<typename T>istream &operator>>(istream &is, deque<T> &v) { for (T &t : v) is >> t; return is; }
    template<typename T>ostream &operator<<(ostream &os, const deque<T> &v) { for (const T &t : v) {os << t << (whitespace(t) ? " " : ""); } os << "\n"; return os; }
    template<typename T>T gcd(T a, T b) { while (b) { T mod = a % b; a = b; b = mod; } return a; }
    template<typename T>T sum(const vector<T> &v) { T s = 0; for (T value : v) s += value; return s; }
    template<typename T>vector<T> prefix_sum(const vector<T> &v) { vector<T> res(v.size()+1); res[0] = 0; for (int i = 0; i < v.size(); ++i) res[i+1] = res[i] + v[i]; return res; }
    class exit_exception : exception {};
    istream &in = cin; ostream &out = cout;
    void answer(){};
    template<typename First, typename... Args>void answer(First&& val, Args&&... ans){out << val << "\n"; answer(ans...); throw exit_exception();} 
    struct autoint{int x; autoint(){in >> x;} operator int(){return x;} autoint(autoint &i){x = i.x;}
        int operator--(){return --x;} int operator--(signed){return x--;} int operator ++(){return ++x;} int operator++(signed){return x++;} };
    template<typename T> struct autoread : T{template<typename... Args>autoread(Args&&... args): T(args...){ in >> *dynamic_cast<T *>(this);} };
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

struct segment_tree {
    struct segment {
        int min;
        int L, R;
        int add;

        segment(int l = 0, int r = 0, int v = 0) : L(l), R(r), min(0), add(0) {}

        void assign(int l, int r) { L = l, R = r; }
    };

    vector<segment> values;

    void create_segment(int L, int R, int s) {
        if (s >= values.size()) return;
        values[s].assign(L, R);
        create_segment(L, (L + R) / 2, 2 * s + 1);
        create_segment((L + R) / 2, R, 2 * s + 2);
    }

    void add(int x, int L, int R, int s = 0) {
        if (R <= values[s].L || L >= values[s].R) return;
        if (L <= values[s].L && R >= values[s].R) {
            values[s].add += x;
            values[s].min += x;
            return;
        }
        if (2 * s + 2 >= values.size()) return;
        push(s);
        add(x, L, R, 2 * s + 1);
        add(x, L, R, 2 * s + 2);
        values[s].min = ::min(values[2 * s + 1].min, values[2 * s + 2].min);
    }

    void push(int s) {
        int v = values[s].add;
        values[s].add = 0;
        if (2 * s + 2 >= values.size()) return;
        values[2 * s + 1].add += v;
        values[2 * s + 1].min += v;
        values[2 * s + 2].add += v;
        values[2 * s + 2].min += v;
    }

    int min(int L, int R, int s = 0) {
        push(s);
        if (R <= values[s].L || L >= values[s].R) return 2e9;
        if (L <= values[s].L && R >= values[s].R) return values[s].min;
        int l = values[s].L, r = values[s].R;
        return ::min(min(L, R, 2 * s + 1), min(L, R, 2 * s + 2));
    }

    segment_tree(vector<int> &a) {
        int size = 1;
        while (size < a.size()) size <<= 1;
        values.assign(size << 1, segment());
        create_segment(0, size, 0);
        for (int i = 0; i < a.size(); ++i) add(a[i], i, i + 1);
    }

    friend ostream &operator<<(ostream &os, segment_tree &st) {
        for (int i = 0; i + i < st.values.size(); ++i) os << st.min(i, i + 1) << " ";
        os << "\n";
        return os;
    }
};

void solve() {
    autoint n;
    autoread<vector<int>> p(n), a(n);
    for (int i = 0; i < n; ++i) p[i]--;
    vector<int> pos(n);
    for (int i = 0; i < n; ++i) pos[p[i]] = i;
    vector<int> t(n);
    for (int i = 1; i < n; ++i) {
        t[i] = t[i - 1] + a[i - 1];
    }
    segment_tree ans(t);
    int res = ans.min(1, n);
    for (int val = 0; val < n; ++val) {
        int i = pos[val];
        ans.add(+a[i], 0, i + 1);
        ans.add(-a[i], i + 1, n);
        res = min(res, ans.min(1, n));
    }
    answer(res);
}