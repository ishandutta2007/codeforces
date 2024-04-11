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
const int LG = 31;
vec<int> g[N];
bool used[N];
int n, m, edges[N][3], dep[N], dist[N], who[LG];

inline int another(int i, int v) {
    return edges[i][0] ^ edges[i][1] ^ v;
}

inline void insert(int x) {
    while (x != 0) {
        int b = __lg(x);
        if (who[b] == -1) {
            who[b] = x;
            break;
        }
        x ^= who[b];
    }
}

void dfs(int v, int par) {
    used[v] = 1;
    for (auto i : g[v]) {
        if (i == par) continue;
        int u = another(i, v), w = edges[i][2];
        if (used[u]) {
            if (dep[u] <= dep[v]) insert(dist[v] ^ dist[u] ^ w);
        } else {
            dep[u] = dep[v] + 1;
            dist[u] = dist[v] ^ w;
            dfs(u, i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2], edges[i][0]--, edges[i][1]--;
        g[edges[i][0]].push_back(i);
        g[edges[i][1]].push_back(i);
    }
    fill(all(who), -1);
    dfs(0, -1);
    int ans = dist[n - 1];
    for (int i = LG - 1; i >= 0; i--) {
        if ((ans >> i) % 2 && who[i] != -1) ans ^= who[i];;
    }
    cout << ans << '\n';
}