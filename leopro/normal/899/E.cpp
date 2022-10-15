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
    template<typename T>void answer(T ans, ostream &os = cout){os << ans << "\n"; throw ExitException();}
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

struct Segment {
    int value;
    int len;
    int L;

    const bool operator<(const Segment &s) const {
        if (len != s.len) return len > s.len;
        return L < s.L;
    }

    mutable Segment *next, *prev;

    Segment(int v = 0, int l = 0, int L = 0) : value(v), len(l), L(L), next(nullptr), prev(nullptr) {}
};

void solve() {
    autoint n;
    autoread<vector<int>> a(n);
    vector<Segment> segments;
    segments.emplace_back(a[0], 1, 0);
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i - 1]) segments.back().len++; else segments.emplace_back(a[i], 1, i);
    }
    for (int i = 1; i < segments.size(); ++i) segments[i].prev = new Segment(segments[i - 1]);
    for (int i = 0; i < segments.size() - 1; ++i) segments[i].next = new Segment(segments[i + 1]);
    set<Segment> s;
    for (int i = 0; i < segments.size(); ++i) {
        s.insert(segments[i]);
    }
    int ans = 0;
    while (!s.empty()) {
        auto seg = s.begin();
        if (seg->prev == nullptr || seg->next == nullptr || seg->prev->value != seg->next->value) {
            if (seg->prev != nullptr) s.find(*seg->prev)->next = seg->next;
            if (seg->next != nullptr) s.find(*seg->next)->prev = seg->prev;
        } else {
            int value = seg->prev->value;
            int len = seg->prev->len + seg->next->len;
            int L = seg->prev->L;
            Segment *New = new Segment(value, len, L);
            if (s.find(*seg->prev)->prev != nullptr) {
                s.find(*s.find(*seg->prev)->prev)->next = New;
                New->prev = new Segment(*s.find(*seg->prev)->prev);
            }
            if (s.find(*seg->next)->next != nullptr) {
                s.find(*s.find(*seg->next)->next)->prev = New;
                New->next = new Segment(*s.find(*seg->next)->next);
            }
            Segment *x = seg->prev;
            Segment *y = seg->next;
            s.erase(*seg->prev);
            s.erase(*seg->next);
            s.insert(*New);
        }
        s.erase(seg);
        ++ans;
    }
    answer(ans);
}