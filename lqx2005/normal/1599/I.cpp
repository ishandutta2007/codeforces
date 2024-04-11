#include <bits/stdc++.h>
using namespace std;
struct node {
    int son[2], fa;
    int revtag, tag, key, sum, qwq;
} t[750010];
int n, m;
inline void up(int x) {
    t[x].sum = t[t[x].son[0]].sum | t[t[x].son[1]].sum | t[x].key;
    t[x].qwq = t[t[x].son[0]].qwq | t[t[x].son[1]].qwq | (x > n);
}
inline void rev(int x) {
    t[x].revtag ^= 1;
    swap(t[x].son[0], t[x].son[1]);
}
inline void cover(int x, int k) {
    t[x].tag = k;
    if (x > n) t[x].key = k;
    if (t[x].qwq) t[x].sum = k;
}
inline void down(int x) {
    if (t[x].revtag) {
        rev(t[x].son[0]);
        rev(t[x].son[1]);
        t[x].revtag = 0;
    }
    if (t[x].tag != -1) {
        cover(t[x].son[0], t[x].tag);
        cover(t[x].son[1], t[x].tag);
        t[x].tag = -1;
    }
}
inline int nroot(int x) {
    return x == t[t[x].fa].son[0] || x == t[t[x].fa].son[1];
}
inline void rotate(int x) {
    int f = t[x].fa, g = t[f].fa, k = x == t[f].son[1];
    int b = t[x].son[k ^ 1];
    t[x].son[k ^ 1] = f, t[f].son[k] = b;
    if (nroot(f)) {
        t[g].son[f == t[g].son[1]] = x;
    }
    t[x].fa = g, t[f].fa = x, t[b].fa = f;
    up(f);
}
void pushall(int x) {
    if (nroot(x)) pushall(t[x].fa);
    down(x);
}
inline void splay(int x) {
    pushall(x);
    while (nroot(x)) {
        int f = t[x].fa;
        if (nroot(f)) rotate((x == t[f].son[0]) == (f == t[t[f].fa].son[0]) ? f : x);
        rotate(x);
    }
    up(x);
}
inline void access(int x) {
    for (int y = 0; x; y = x, x = t[x].fa)
        splay(x), t[x].son[1] = y, up(x);
}
inline void make_root(int x) {
    access(x), splay(x), rev(x);
}
inline void link(int x, int y) {
    make_root(x), t[x].fa = y;
}
inline void cut(int x, int y) {
    make_root(x), access(y), splay(x);
    t[x].son[1] = 0;
    t[y].fa = 0;
    up(x);
}
inline void getpath(int x, int y) {
    make_root(x);
    access(y);
    splay(y);
}
int u[500010], v[500010], vis[500010];
inline int add(int x) {
    getpath(u[x], v[x]);
    if (t[u[x]].fa == 0) {
        link(u[x], x + n);
        link(x + n, v[x]);
        vis[x] = 1;
        return 1;
    }
    else {
        if (t[v[x]].sum) return 0;
        cover(v[x], x);
        return 1;
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", u + i, v + i);
    }
    long long ans = 0;
    for (int l = 1, r = 0; l <= m; l++) {
        while (r < m && add(r + 1)) r++;
        ans += r - l + 1;
        if (vis[l]) {
            getpath(l + n, l + n);
            if (t[l + n].key) {
                int qwq = t[l + n].key;
                getpath(u[qwq], v[qwq]);
                cover(v[qwq], 0);
                cut(u[l], l + n);
                cut(v[l], l + n);
                cut(u[l], l + n);
                cut(v[l], l + n);
                link(u[qwq], qwq + n);
                link(v[qwq], qwq + n);
                vis[qwq] = 1;
            }
            else {
                cut(u[l], l + n);
                cut(v[l], l + n);
            }
        }
        else {
            getpath(u[l], v[l]);
            cover(v[l], 0);
        }
    }
    cout << ans << endl;
}