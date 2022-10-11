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

const int N = 2.5e5 + 4;
vec<int> g[N];
int n, m, k, dep[N], par[N];
bool used[N];
vec<vec<int>> cycles;

void add(int v, int u) {
    cycles.push_back({});
    while (v != u) {
        cycles.back().push_back(v);
        v = par[v];
    }
    cycles.back().push_back(v);
}

void dfs(int v) {
    if (dep[v] + 1 == (n + k - 1) / k) {
        cout << "PATH\n";
        cout << (n + k - 1) / k << '\n';
        while (v != -1) {
            cout << v + 1 << ' ';
            v = par[v];
        }
        cout << '\n';
        exit(0);
    }
    used[v] = 1;
    vec<int> rev;
    bool down = false;
    for (auto u : g[v]) {
        if (u == par[v]) continue;
        if (used[u]) {
            if (dep[u] < dep[v]) rev.push_back(u);
        } else {
            dep[u] = dep[v] + 1;
            par[u] = v;
            dfs(u);
            down = true;
        }
    }
    if (!down && len(cycles) < k) {
        assert(len(rev) >= 2);
        int a = rev[0], b = rev[1];
        if (dep[a] > dep[b]) swap(a, b);
        if ((dep[v] - dep[a] + 1) % 3 != 0) {
            add(v, a);
        } else if ((dep[v] - dep[b] + 1) % 3 != 0) {
            add(v, b);
        } else {
            add(b, a);
            cycles.back().push_back(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u, v--, u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    par[0] = -1;
    dfs(0);
    assert(len(cycles) == k);
    cout << "CYCLES\n";
    for (auto cycle : cycles) {
        cout << len(cycle) << '\n';
        for (auto x : cycle) {
            cout << x + 1 << ' ';
        }
        cout << '\n';
    }
}