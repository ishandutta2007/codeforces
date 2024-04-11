/*
    author:  Maksim1744
    created: 28.05.2021 15:26:04
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
class _y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit _y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};
template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return _y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
// auto gcd = std::y_combinator([](auto gcd, int a, int b) -> int {
//     return b == 0 ? a : gcd(b, a % b);
// });

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    cin >> a;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> par(n, -1);
    vector<int> lvl(n, 0);

    y_combinator([&](auto dfs, int v, int p = -1) -> void {
        for (int k : g[v]) {
            if (k != p) {
                lvl[k] = lvl[v] + 1;
                par[k] = v;
                dfs(k, v);
            }
        }
    })(0, -1);

    const int B = 8;
    const int B2 = B * 2;
    const int N = (1 << B);

    vector<vector<int>> prec(n, vector<int>(N));
    vector<int> jump(n, -1);
    show(lvl);
    for (int i = 0; i < n; ++i) {
        if (lvl[i] < N) continue;
        show(i);
        struct Node {
            array<int, 2> to;
            Node() {
                to.fill(0);
            }
        };
        vector<Node> vv(1);
        auto new_node = [&]() {
            vv.eb();
            return vv.size() - 1;
        };
        int root = new_node();
        int v = i;
        for (int j = 0; j < N; ++j) {
            int x = (j ^ a[v]);
            int node = root;
            for (int b = B2 - 1; b >= 0; --b) {
                int e = ((x >> b) & 1);
                if (!vv[node].to[e])
                    vv[node].to[e] = new_node();
                node = vv[node].to[e];
            }
            v = par[v];
            assert(v != -1);
        }
        jump[i] = v;
        for (int sh0 = 0; sh0 < N; ++sh0) {
            int shift = sh0 * N;
            int node = root;
            int res = 0;
            for (int b = B2 - 1; b >= 0; --b) {
                int want = 1 ^ ((shift >> b) & 1);
                if (vv[node].to[want]) {
                    node = vv[node].to[want];
                    res |= (1 << b);
                } else {
                    node = vv[node].to[want ^ 1];
                }
            }
            prec[i][sh0] = res;
        }
    }

    while (q--) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        int ans = 0;
        int cur = 0;
        while (true) {
            if (lvl[v] - N >= lvl[u]) {
                show(v, cur);
                ans = max(ans, prec[v][cur]);
                ++cur;
                v = jump[v];
            } else {
                cur *= N;
                while (v != -1 && lvl[v] >= lvl[u]) {
                    ans = max(ans, cur ^ a[v]);
                    v = par[v];
                    ++cur;
                }
                break;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}