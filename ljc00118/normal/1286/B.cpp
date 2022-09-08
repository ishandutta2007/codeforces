#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
 
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;
 
template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}
 
template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}
 
template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 2005;

vector <int> adj[N];
int fa[N], c[N], ans[N], siz[N];
int n, root;

void dfs1(int u) {
    siz[u] = 1;
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        dfs1(v); siz[u] += siz[v];
    }
}

void dfs2(int u, vector <int> now) {
    if (c[u] >= (int)now.size()) {
        printf("NO\n");
        exit(0);
    }
    ans[u] = now[c[u]]; now[c[u]] = 0;
    int pos = -1;
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        vector <int> go;
        for (int j = 0; j < siz[v]; j++) {
            ++pos;
            if (!now[pos]) ++pos;
            go.push_back(now[pos]);
        }
        dfs2(v, go);
    }
}

int main() {
    read(n);
    for (int i = 1; i <= n; i++) {
        read(fa[i]); read(c[i]);
        if (fa[i]) adj[fa[i]].push_back(i);
        else root = i;
    }
    vector <int> now;
    for (int i = 1; i <= n; i++) now.push_back(i);
    dfs1(root); dfs2(root, now);
    printf("YES\n");
    for (int i = 1; i <= n; i++) print(ans[i], i == n ? '\n' : ' ');
    return 0;
}