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

const int N = 2e5 + 4;
vec<int> g[N];
bool used[N];
int dep[N];
int n, m;
vec<ar<int, 3>> ans;

bool dfs(int v, int par) {
    used[v] = 1;
    vec<int> ok;
    for (auto u : g[v]) {
        if (u == par) continue;
        if (used[u]) {
            if (dep[u] < dep[v]) ok.push_back(u);
        } else {
            dep[u] = dep[v] + 1;
            if (dfs(u, v)) ok.push_back(u);
        }
    }
    dbg(v, par, ok);
    while (len(ok) >= 2) {
        int a = ok.end()[-1];
        int b = ok.end()[-2];
        ok.pop_back();
        ok.pop_back();
        ans.push_back({a, v, b});
    }
    if (par == v) return false;
    if (len(ok) == 1) {
        ans.push_back({par, v, ok.back()});
        return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u, v--, u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) dfs(i, i);
    }
    cout << len(ans) << '\n';
    for (auto [a, b, c] : ans) {
        cout << a + 1 << ' ' << b + 1 << ' ' << c + 1 << '\n';
    }
}