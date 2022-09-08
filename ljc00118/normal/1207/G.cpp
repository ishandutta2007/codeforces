#pragma GCC optimize(2)
#pragma GCC optimize(3)
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
 
const int N = 8e5 + 5;
 
queue <int> q;
vector <int> adj[N];
vector <pii> Q[N];
char c[N];
int ch[N][26], fail[N], rt[N], f[N], siz[N], ans[N], tops[N];
int n, m, tot, len, cnt;
 
char readChar() {
    char c = getchar();
    while(c < 'a' || c > 'z') c = getchar();
    return c;
}
 
inline int lowbit(int x) { return x & -x; }
 
inline void add(int x, int y) {
    for(register int i = x; i <= cnt; i += lowbit(i))
        f[i] += y;
}
 
inline int query(int x) {
    int ans = 0;
    for(register int i = x; i; i ^= lowbit(i))
        ans += f[i];
    return ans;
}
 
void dfs1(int u) {
    siz[u] = 1; tops[u] = ++cnt;
    for(register int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        dfs1(v); siz[u] += siz[v];
    }
    // fprintf(stderr, "u = %d, siz[u] = %d, tops[u] = %d\n", u, siz[u], tops[u]);
}
 
void dfs2(int u) {
    add(tops[u], 1);
    for(register int i = 0; i < (int)Q[u].size(); i++) ans[Q[u][i].second] = query(tops[Q[u][i].first] + siz[Q[u][i].first] - 1) - query(tops[Q[u][i].first] - 1);
    for(register int i = 0; i <= 25; i++) if(ch[u][i]) dfs2(ch[u][i]);
    add(tops[u], -1);
}
 
int main() {
    read(n);
    for(register int i = 1; i <= n; i++) {
        int opt; read(opt);
        if(opt == 1) {
            char c = readChar();
            if(!ch[0][c - 'a']) ch[0][c - 'a'] = ++tot;
            rt[i] = ch[0][c - 'a'];
        }
        if(opt == 2) {
            int pre; read(pre); char c = readChar();
            int now = rt[pre];
            if(!ch[now][c - 'a']) ch[now][c - 'a'] = ++tot;
            rt[i] = ch[now][c - 'a'];
        }
    }
    read(m);
    for(register int i = 1; i <= m; i++) {
        int x; read(x);
        scanf("%s", c + 1); len = strlen(c + 1);
        int now = 0;
        for(register int j = 1; j <= len; j++) {
            int x = c[j] - 'a';
            if(!ch[now][x]) ch[now][x] = ++tot;
            now = ch[now][x];
        }
        Q[rt[x]].push_back(make_pair(now, i));
    }
    for(register int i = 0; i <= 25; i++) if(ch[0][i]) q.push(ch[0][i]), adj[0].push_back(ch[0][i]);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(register int i = 0; i <= 25; i++) {
            int v = ch[u][i];
            if(!v) continue;
            int now = fail[u], las = 1;
            while(las) {
                if(ch[now][i]) {
                    fail[v] = ch[now][i];
                    break;
                }
                las = now; now = fail[now];
            }
            adj[fail[v]].push_back(v); q.push(v);
        }
    }
    dfs1(0); dfs2(0);
    for(register int i = 1; i <= m; i++) print(ans[i], '\n');
    return 0;
}