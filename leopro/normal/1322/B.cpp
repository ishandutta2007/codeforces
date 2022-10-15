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
    template<typename T>vector<T> prefix_sum(const vector<T> &v, double from = 0, double till = 0) { vector<T> res(v.size()+1); for (double i=from; i+till < v.size(); ++i) res[i-from+1] = res[i-from] + v[i]; return res; }
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

struct point {
    int x, y;

    friend istream &operator>>(istream &is, point &point) {
        is >> point.x >> point.y;
        return is;
    }

    point(int x = 0, int y = 0) : x(x), y(y) {}

    bool operator<(point &point) const {
        if (x != point.x) return x < point.x;
        return y < point.y;
    }
};

struct graph {
    struct vertex {
        struct edge {
            vertex *p;
            int weight;

            edge(vertex *p, int w) : p(p), weight(w) {}
        };

        bool operator<(const vertex &vertex) const {
            return n < vertex.n;
        }

        vector<edge> edges;
        int n;
        point p;

        vertex(int i = 0) : n(i) {}
    };

    vector<vertex *> vertices;

    void link(int i, int j, int w) {
        vertices[i]->edges.emplace_back(vertices[j], w);
    }

    explicit graph(int n) : vertices(n) {
        for (int i = 0; i < n; ++i) vertices[i] = new vertex(i);
    }
};

struct cost {
    int c;
    graph::vertex *v;

    bool operator<(const cost &cost) const {
        if (c != cost.c) return c < cost.c;
        return *v < *cost.v;
    }

    cost(int c, graph::vertex *v) : c(c), v(v) {}
};

void solve() {
    autoint n;
    autoread<vector<int>> a(n);
    int ans = 0;
    for (int bit = 0; bit < 30; ++bit) {
        vector<int> b = a;
        for (int i = 0; i < n; ++i) {
            b[i] &= (1 << (bit + 1)) - 1;
        }
        stable_sort(b.begin(), b.end());
        int cnt = 0;
        for (int x : b) {
            cnt += upper_bound(b.begin(), b.end(), (1 << (bit + 1)) - x - 1) -
                   lower_bound(b.begin(), b.end(), (1 << bit) - x);
            cnt += upper_bound(b.begin(), b.end(), (1 << (bit + 2)) - x - 1) -
                   lower_bound(b.begin(), b.end(), (1 << (bit + 1)) + (1 << bit) - x);
            cnt -= (1 << bit) <= x + x && x + x < (1 << (bit + 1));
            cnt -= (1 << (bit + 1)) + (1 << bit) <= x + x && x + x < (1 << (bit + 2));
        }
        if ((cnt / 2) & 1) ans |= 1 << bit;
    }
    answer(ans);
}