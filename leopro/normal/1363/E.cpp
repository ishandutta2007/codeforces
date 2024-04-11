#include <bits/stdc++.h>

namespace {
    using namespace std;
#define int long long

    template<typename T>
    inline bool whitespace(const vector<T> &) { return false; }

    template<typename T>
    inline bool whitespace(const T &) { return true; }

    inline bool whitespace(const char) { return false; }

    template<typename F, typename S>
    inline bool whitespace(const pair<F, S> &) { return false; }

    template<typename F, typename S>
    ostream &operator<<(ostream &os, const pair<F, S> &p) {
        os << p.first << (whitespace(p.second) ? " " : "") << p.second << "\n";
        return os;
    }

    template<typename F, typename S>
    istream &operator>>(istream &is, pair<F, S> &p) {
        is >> p.first >> p.second;
        return is;
    }

    template<typename T>
    istream &operator>>(istream &is, vector<T> &v) {
        for (T &t : v) is >> t;
        return is;
    }

    template<typename T>
    ostream &operator<<(ostream &os, const vector<T> &v) {
        for (const T &t : v) {
            os << t << (whitespace(t) ? " " : "");
        }
        os << "\n";
        return os;
    }

    template<typename T>
    istream &operator>>(istream &is, deque<T> &v) {
        for (T &t : v) is >> t;
        return is;
    }

    template<typename T>
    ostream &operator<<(ostream &os, const deque<T> &v) {
        for (const T &t : v) {
            os << t << (whitespace(t) ? " " : "");
        }
        os << "\n";
        return os;
    }

    class exit_exception : exception {
    };

    void answer() {}

    template<typename First, typename... Args>
    void answer(First &&val, Args &&... ans) {
        cout << val << "\n";
        answer(ans...);
        throw exit_exception();
    }

    struct autoint {
        int x;

        autoint(int i) : x(i) {}

        autoint() : x(0) { cin >> x; }

        operator int() { return x; }

        int operator--() { return --x; }

        int operator--(signed) { return x--; }

        int operator++() { return ++x; }

        int operator++(signed) { return x++; }
    };

    template<typename T>
    T gcd(T a, T b) {
        while (b) {
            T mod = a % b;
            a = b;
            b = mod;
        }
        return a;
    }

    template<typename T>
    vector<T> prefix_sum(const vector<T> &v, int from = 0) {
        vector<T> res(v.size() + 1 - from);
        res[0] = 0;
        for (int i = from; i < v.size(); ++i) res[i + 1 - from] = res[i - from] + v[i];
        return res;
    }
}

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

struct graph {
    struct vertex {
        vector<vertex *> links;
        int a, b, c;

        friend istream &operator>>(istream &is, vertex &v) {
            is >> v.a >> v.b >> v.c;
            return is;
        }

    };

    vector<vertex *> vertices;

    explicit graph(int n) : vertices(n) { for (auto *&v : vertices) v = new vertex(); }

    static pair<int, int> dfs(vertex *v, vertex *p) {
        v->a = min(v->a, p->a);
        int pos = 0, neg = 0, ans = 0;
        for (auto *u : v->links){
            if (u == p) continue;
            auto c = dfs(u, v);
            if (c.second > 0) pos += c.second; else neg += c.second;
            ans += c.first;
        }
        if (v->b == 0 && v->c == 1) pos++;
        if (v->b == 1 && v->c == 0) neg--;
        ans += min(pos, -neg) * v->a;
        return {ans, pos + neg};
    }

    void link(int a, int b) {
        vertices[a]->links.push_back(vertices[b]);
        vertices[b]->links.push_back(vertices[a]);
    }
};

void solve() {
    autoint n;
    graph g(n);
    for (int i = 0; i < n; ++i) {
        cin >> *g.vertices[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        autoint u, v;
        g.link(--u, --v);
    }
    auto ans = graph::dfs(g.vertices[0], g.vertices[0]);
    answer(ans.second == 0 ? 2 * ans.first : -1);
}