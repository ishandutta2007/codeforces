#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define ll long long
using namespace std;
const int N = 4e3 + 10, P = 998244353;
int n, m, k, cnt[N], vis[N];
vector<int> g[N], id[N];
char str[N][N];
int power(int a, int b, int c = 1) {
    for(; b; b >>= 1, a = (ll)a * a % P) if(b & 1) c = (ll)c * a % P;
    return c;
}
int calc(int x, int l, int r) {
    int tot = k;
    for(int i = l; i <= r; i++) {
        if(g[i].empty()) {
            if(cnt[i] != x) return 0;
        } else tot--;
    }
    return power(2, tot);
}
void dfs(int u, int x) {
    vis[u] = 1;
    id[x].emplace_back(u);
    for(auto v : g[u]) if(!vis[v]) dfs(v, x);
}
int calc(int x) {
    for(int i = 1; i <= n + m; i++) vis[i] = 0, id[i].clear();
    int idtot = 0;
    for(int i = 1; i <= n + m; i++) if(!vis[i]) {
        idtot++;
        dfs(i, idtot);
    }
    int tot = 0;
    for(int i = 1; i <= idtot; i++) {
        int v = 0, c = 0;
        for(auto x : id[i]) v ^= cnt[x], c += sz(g[x]);
        if(v != (x * sz(id[i]) % 2)) return 0;
        tot += c / 2 - (sz(id[i]) - 1);
    }
    return power(2, tot);
}
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> (str[i] + 1);
        for(int j = 1; j <= m; j++) {
            if(str[i][j] == '?') {
                g[i].emplace_back(j + n), g[j + n].emplace_back(i);
                k++;
            } else {
                int c = str[i][j] - '0';
                cnt[i] ^= c, cnt[j + n] ^= c;
            }
        }
    }
    if(n % 2 == 0 && m % 2 == 0) {
        cout << power(2, k) << endl;
        return 0;
    }
    if(n % 2 == 0 && m % 2 == 1) {
        int res = (calc(0, 1, n) + calc(1, 1, n)) % P;
        cout << res << endl;
        return 0;
    }
    if(n % 2 == 1 && m % 2 == 0) {
        int res = (calc(0, n + 1, n + m) + calc(1, n + 1, n + m)) % P;
        cout << res << endl;
        return 0;
    }
    int res = (calc(0) + calc(1)) % P;
    cout << res << endl;
    return 0;
}