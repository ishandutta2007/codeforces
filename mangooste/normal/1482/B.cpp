#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vec vector
#define ar array

#define all(a) (a).begin(), (a).end()
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

const ll INF = 1e12;

inline ll min(ll a, ll b) { return a < b ? a : b; }
inline ll max(ll a, ll b) { return a > b ? a : b; }

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vec<vec<ar<int, 3>>> g(n);
    vec<vec<ll>> dist(n, vec<ll>(n, INF));
    for (int i = 0; i < n; i++)
        dist[i][i] = 0;

    for (int i = 0; i < m; i++) {
        int v, u, w;
        cin >> v >> u >> w;
        v--, u--;
        dist[v][u] = dist[u][v] = w;
        g[v].push_back({u, w, i});
        g[u].push_back({v, w, i});
    }

    for (int m = 0; m < n; m++)
        for (int v = 0; v < n; v++)
            for (int u = 0; u < n; u++)
                dist[v][u] = min(dist[v][u], dist[v][m] + dist[m][u]);

    int q;
    cin >> q;
    vec<vec<pair<int, int>>> maybe(n);
    for (int i = 0; i < q; i++) {
        int v, u, l;
        cin >> v >> u >> l;
        v--, u--;
        if (dist[v][u] > l)
            continue;
        maybe[v].emplace_back(u, l);
    }

    vec<char> good(m);
    for (int c = 0; c < n; c++)
        if (len(maybe[c])) {
            vec<char> used(n);
            vec<ll> vals(n, -INF);
            vals[c] = 0;
            for (auto [v, l] : maybe[c])
                vals[v] = l;

            for (int i = 0; i < n; i++) {
                int mx = -1;
                for (int j = 0; j < n; j++)
                    if (!used[j] && (mx == -1 || vals[j] > vals[mx]))
                        mx = j;

                if (vals[mx] <= 1)
                    break;

                used[mx] = 1;
                for (auto [v, w, id] : g[mx])
                    vals[v] = max(vals[v], vals[mx] - w);
            }

            for (int i = 0; i < n; i++)
                for (auto [j, w, id] : g[i])
                    good[id] |= dist[c][i] + w <= vals[j];
        }

    cout << accumulate(all(good), 0) << '\n';
}