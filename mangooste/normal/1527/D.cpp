#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define vec vector
#define ar array

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

template<typename A, typename B>
ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }

template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type>
ostream& operator<<(ostream &out, A vec) { out << '{'; string sep; for (B x : vec) out << sep << x, sep = ", "; return out << '}'; }

void dbg_print() { cerr << endl; }
template<typename A, typename... B> void dbg_print(A a, B... b) { cerr << ' ' << a; dbg_print(b...); }

#ifdef LOCAL
    #define dbg(...) cerr << '#' << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbg_print(__VA_ARGS__)
#else
    #define dbg(...)
#endif

struct graph {
    int n;
    vec<vec<int>> g;

    int timer;
    vec<int> tin, tout, size;

    graph(int n) : n(n), g(n), timer(0), tin(n), tout(n), size(n) {}

    void init(int v, int par) {
        tin[v] = timer++;
        if (par != v)
            g[v].erase(find(all(g[v]), par));

        size[v] = 1;
        for (auto u : g[v]) {
            init(u, v);
            size[v] += size[u];
        }

        tout[v] = timer;
    }

    void read() {
        for (int i = 1; i < n; i++) {
            int v, u;
            cin >> v >> u;

            g[v].push_back(u);
            g[u].push_back(v);
        }

        init(0, 0);
    }

    bool is_par(int v, int u) {
        return tin[v] <= tin[u] && tout[u] <= tout[v];
    }

    int binary_search(int v, int u) {
        assert(is_par(v, u));

        int l = 0, r = len(g[v]);
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (tin[g[v][mid]] <= tin[u])
                l = mid;
            else
                r = mid;
        }

        return g[v][l];
    }

    void solve() {
        vec<ll> values(n + 1);
        values[0] = ll(n) * (n - 1) / 2;

        ll sum = 1;
        for (auto u : g[0]) {
            values[1] += sum * size[u];
            sum += size[u];
        }

        int l = 0, r = 1;
        for (int v = 1; v < n; v++) {
            if (l == 0)
                values[v + 1] += ll(n - size[binary_search(0, r)]) * size[r];
            else
                values[v + 1] += ll(size[l]) * size[r];

            if (v == n - 1)
                continue;

            if (l == 0) {
                if (is_par(r, v + 1))
                    r = v + 1;
                else if (!is_par(v + 1, r)) {
                    if (binary_search(0, v + 1) == binary_search(0, r))
                        break;

                    l = v + 1;
                }
            } else {
                if (is_par(r, v + 1))
                    r = v + 1;
                else if (is_par(l, v + 1))
                    l = v + 1;
                else if (!is_par(v + 1, l) && !is_par(v + 1, r))
                    break;
            }
        }

        for (int i = 0; i < n; i++)
            cout << values[i] - values[i + 1] << ' ';

        cout << values.back() << '\n';
    }
};

void solve() {
    int n;
    cin >> n;

    graph g(n);
    g.read();
    g.solve();
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}