#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vec vector
#define ar array

#define all(a) begin(a), end(a)
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

const int N = 1e5 + 4;
vec<int> g[N];
int n, q, tin[N], tout[N], timer, up[N], type[N], par[N], root[N];

void dfs(int v) {
    tin[v] = timer++;
    for (auto u : g[v]) {
        if (type[u] == type[v]) {
            up[u] = up[v];
        } else {
            up[u] = v;
        }
        root[u] = root[v];
        dfs(u);
    }
    tout[v] = timer;
}

inline bool is_par(int v, int u) {
    return tin[v] <= tin[u] && tout[u] <= tout[v];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> par[i] >> type[i];
        if (par[i] != -1) {
            par[i]--;
            g[par[i]].push_back(i);
        }
    }
    for (int i = 0; i < n; i++) {
        if (par[i] == -1) {
            root[i] = i;
            dfs(i);
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int tp, v, u;
        cin >> tp >> v >> u;
        v--, u--;
        if (v == u || root[v] != root[u]) {
            cout << "No\n";
            continue;
        }
        if (tp == 1) {
            if (is_par(v, u) && type[u] == 0 && is_par(up[u], v)) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        } else {
            if (is_par(v, u) && type[u] == 1 && is_par(up[u], v)) {
                cout << "Yes\n";
            } else if (type[u] == 1 && type[v] == 0 && is_par(up[u], v) && is_par(up[v], u) && up[v] != u) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }
}