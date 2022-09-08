#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
using namespace std;
 
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;
 
template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}
 
template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}
 
template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}
 
const int N = 1005, MAXN = 2520;
 
inline int add(int x, int y) {
    x += y;
    if(x >= MAXN) x -= MAXN;
    return x;
}
 
queue <pii> q;
int f[N][MAXN], in[N][MAXN];
bool vis[N][MAXN], vis2[N][MAXN], v[N];
int e[N], go[N][15];
int k[N];
int n, big, m;
 
void dfs1(int i, int j) {
    vis[i][j] = 1; if(!v[i]) { v[i] = 1; ++big; }
    int t = add(j, k[i]), v = go[i][t % e[i] + 1];
    if(!vis[v][t]) dfs1(v, t);
}
 
void dfs2(int i, int j) {
    vis2[i][j] = 1; f[i][j] = big; v[i] = 0;
    int t = add(j, k[i]), v = go[i][t % e[i] + 1];
    if(!vis2[v][t]) dfs2(v, t);
}
 
void dfs3(int i, int j) {
    if(vis[i][j]) { return; } vis[i][j] = 1;
    int t = add(j, k[i]), v = go[i][t % e[i] + 1];
    dfs3(v, t); f[i][j] = f[v][t];
}
 
int main() {
    read(n);
    for(register int i = 1; i <= n; i++) read(k[i]), k[i] = (k[i] % MAXN + MAXN) % MAXN;
    for(register int i = 1; i <= n; i++) {
        read(e[i]);
        for(register int j = 1; j <= e[i]; j++) read(go[i][j]);
    }
    for(register int i = 1; i <= n; i++) {
        for(register int j = 0; j < MAXN; j++) {
            int t = add(j, k[i]), v = go[i][t % e[i] + 1];
            ++in[v][t];
        }
    }
    for(register int i = 1; i <= n; i++) {
        for(register int j = 0; j < MAXN; j++) {
            if(!in[i][j]) q.push(make_pair(i, j));
        }
    }
    while(!q.empty()) {
        pii u = q.front(); q.pop();
        int t = add(u.second, k[u.first]), v = go[u.first][t % e[u.first] + 1];
        --in[v][t]; if(!in[v][t]) q.push(make_pair(v, t));
    }
    for(register int i = 1; i <= n; i++) {
        for(register int j = 0; j < MAXN; j++) {
            if(in[i][j] && !vis[i][j]) {
                big = 0;
                dfs1(i, j);
                dfs2(i, j);
            }
        }
    }
    for(register int i = 1; i <= n; i++) {
        for(register int j = 0; j < MAXN; j++) {
            if(!vis[i][j]) {
                dfs3(i, j);
            }
        }
    }
    read(m);
    for(register int i = 1; i <= m; i++) {
        int x, y;
        read(x); read(y);
        y = (y % MAXN + MAXN) % MAXN;
        print(f[x][y], '\n');
    }
    return 0;
}