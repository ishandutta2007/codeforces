// woshizhengdecaia
#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define x first
#define y second
#define vi vector<int>
using namespace std;
typedef long long ll;
const int N = 2000 + 10;
int n, m, col[N];
bitset<N> e[N];

void dfs(vi ord) {
    int p = -1;
    for(int i = 0; i < sz(ord); i++) {
        int u = ord[i];
        if(e[u].count() & 1) {
            for(int v = e[u]._Find_first(); v != sz(e[u]); v = e[u]._Find_next(v)) {
                e[v] ^= e[u];
                e[v][v] = e[v][v] ^ 1;
                e[v][u] = e[v][u] ^ 1;
            }
            p = u;
            ord.erase(ord.begin() + i);
            break;
        }
    }
    if(p == -1) {
        for(int x : ord) col[x] = 1;
        return;
    }
    dfs(ord);
    int c0 = 0, c1 = 0;
    for(int v = e[p]._Find_first(); v != sz(e[p]); v = e[p]._Find_next(v)) {
        if(col[v] == 1) c0++;
        else c1++;
    }
    if(c0 & 1) col[p] = 2;
    else col[p] = 1;
    return;
}

void solve() {
    memset(col, 0, sizeof(col));
    cin >> n >> m;
    for(int i = 1; i <= n; i++) e[i].reset();
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[u][v] = e[u][v] ^ 1, e[v][u] = e[v][u] ^  1;
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++) cnt += e[i].count() & 1;
    if(cnt == 0) {
        cout << 1 << endl;
        for(int i = 1; i <= n; i++) cout << 1 <<" ";
        cout << endl;
        return;
    }
    vi ord(n);
    for(int i = 1; i <= n; i++) ord[i - 1] = i;
    dfs(ord);
    cout << 2 << endl;
    for(int i = 1; i <= n; i++) cout << col[i] <<" ";
    cout << endl;
    return;    
}

int main() {
    int t;
    for(cin >> t; t--; solve());
    return 0;
}