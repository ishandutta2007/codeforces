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

const int N = 1e5 + 4;
vec<int> g[N];
int l[N], r[N];
ll dp[N][2];

void dfs(int v, int par) {
    dp[v][0] = dp[v][1] = 0;

    for (auto u : g[v])
        if (u != par) {
            dfs(u, v);

            dp[v][0] += max(abs(l[u] - l[v]) + dp[u][0], abs(r[u] - l[v]) + dp[u][1]);
            dp[v][1] += max(abs(l[u] - r[v]) + dp[u][0], abs(r[u] - r[v]) + dp[u][1]);
        }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        g[i].clear();

    for (int i = 0; i < n; i++)
        cin >> l[i] >> r[i];

    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u, v--, u--;

        g[v].push_back(u);
        g[u].push_back(v);
    }

    dfs(0, 0);

    cout << max(dp[0][0], dp[0][1]) << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}