/*
    author:  Maksim1744
    created: 07.07.2021 18:32:03
*/

#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             vector<T>& operator--            (vector<T> &v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T> &v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define SHOW_COLORS
#include "C:/C++ libs/print.cpp"
#else
#define show(...) void(0)
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};
template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
// auto gcd = std::y_combinator([](auto gcd, int a, int b) -> int {
//     return b == 0 ? a : gcd(b, a % b);
// });

void test_case(int test) {
    int n;
    cin >> n;
    vector<vector<int>> g(1 << n);
    for (int i = 0; i < n * (1 << (n - 1)); ++i) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    auto bfs = [&](const vector<vector<int>> &g, int v) {
        int n = g.size();
        vector<int> d(n, 1e9);
        d[v] = 0;
        queue<int> q;
        q.push(v);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int k : g[v]) {
                if (d[k] > d[v] + 1) {
                    d[k] = d[v] + 1;
                    q.push(k);
                }
            }
        }
        return d;
    };

    auto getp = y_combinator([&](auto getp, const vector<vector<int>> &g) -> vector<int> {
        if (g.size() == 1) return {0};
        int n = g.size();
        auto d1 = bfs(g, 0);
        auto d2 = bfs(g, g[0][0]);
        vector<int> where(n);
        vector<pair<int, int>> prs;
        for (int i = 0; i < n; ++i) {
            for (int j : g[i]) {
                if (d1[i] == d2[j] && d2[i] == d1[i] + 1 && d1[j] == d2[j] + 1) {
                    where[i] = where[j] = prs.size();
                    prs.eb(i, j);
                }
            }
        }

        show(g);
        show(prs);

        assert(prs.size() == g.size() / 2);
        vector<vector<int>> g1(g.size() / 2);
        for (int i = 0; i < n; ++i) {
            for (int j : g[i]) {
                if (where[i] != where[j])
                    g1[where[i]].pb(where[j]);
            }
        }
        for (auto &v : g1) {
            sort(v.begin(), v.end());
            v.erase(unique(v.begin(), v.end()), v.end());
        }
        auto p0 = getp(g1);
        vector<int> p(n);
        for (int i = 0; i < prs.size(); ++i) {
            auto [u, v] = prs[i];
            p[u] = p0[i];
            p[v] = p0[i] + n / 2;
        }
        return p;
    });

    auto p = getp(g);
    vector<int> pi(p.size());
    for (int i = 0; i < p.size(); ++i) {
        pi[p[i]] = i;
    }
    cout << pi << '\n';
    for (int i = 0; i < g.size(); ++i)
        for (int j : g[i])
            assert(__builtin_popcount(p[i] ^ p[j]) == 1);

    if (__builtin_popcount(n) != 1) {
        cout << -1 << '\n';
        return;
    }
    for (int i = 0; i < (1 << n); ++i) {
        int x = p[i];
        int u = 0;
        for (int j = 0; j < n; ++j) {
            if ((x >> j) & 1)
                u ^= j;
        }
        cout << u << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        test_case(test);
    }

    return 0;
}