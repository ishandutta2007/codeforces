#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
 
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;
 
template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
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

const int N = 5e5 + 5;

int fa[N], ch[N][2], rev[N], st[N], sum[N], val[N], tag[N], col[N], colsum[N], u[N], v[N], id[N], rub[N];
int n, m, len, top, tot; ll ans;

inline int newNode() {
    if (top) return rub[top--];
    return ++tot;
}

int isroot(int u) { return ch[fa[u]][0] != u && ch[fa[u]][1] != u; }
int get(int u) { return ch[fa[u]][1] == u; }

void update(int u) {
    sum[u] = val[u] | sum[ch[u][0]] | sum[ch[u][1]];
    colsum[u] = col[u] | colsum[ch[u][0]] | colsum[ch[u][1]];
}

void add_rev(int u) {
    if (!u) return;
    rev[u] ^= 1;
    swap(ch[u][0], ch[u][1]);
}

void add_tag(int u, int x) {
    if (!u) return;
    tag[u] = x;
    if (col[u]) val[u] = x;
    if (colsum[u]) sum[u] = x;
}

void pushdown(int u) {
    if (rev[u]) {
        add_rev(ch[u][0]);
        add_rev(ch[u][1]);
        rev[u] = 0;
    }
    if (tag[u] != -1) {
        add_tag(ch[u][0], tag[u]);
        add_tag(ch[u][1], tag[u]);
        tag[u] = -1;
    }
}

void rotate(int u) {
    int old = fa[u], oldd = fa[old], k = get(u);
    if (!isroot(old)) { ch[oldd][get(old)] = u; } fa[u] = oldd;
    ch[old][k] = ch[u][k ^ 1]; fa[ch[u][k ^ 1]] = old;
    fa[old] = u; ch[u][k ^ 1] = old;
    update(old); update(u);
}

void splay(int u) {
    st[len = 1] = u;
    for (int i = u; !isroot(i); i = fa[i]) st[++len] = fa[i];
    for (int i = len; i >= 1; i--) pushdown(st[i]);
    for (; !isroot(u); rotate(u)) if(!isroot(fa[u])) rotate(get(u) == get(fa[u]) ? fa[u] : u);
}

void access(int u) {
    for (int i = 0; u; i = u, u = fa[u]) {
        splay(u);
        ch[u][1] = i;
        update(u);
    }
}

void makeroot(int u) {
    access(u);
    splay(u);
    add_rev(u);
}

int findroot(int u) {
    access(u); splay(u);
    while (ch[u][0]) {
        u = ch[u][0];
        pushdown(u);
    }
    int ans = u; splay(u);
    return ans;
}

void link(int u, int v) {
    // fprintf(stderr, "link : u = %d, v = %d\n", u, v);
    makeroot(u);
    fa[u] = v;
}

void cut(int u, int v) {
    makeroot(u);
    access(v);
    splay(v);
    fa[u] = ch[v][0] = 0;
    update(v);
}

int main() {
    read(n); read(m); tot = n;
    for (int i = 1; i <= 2 * n; i++) tag[i] = -1;
    for (int i = n + 1; i <= 2 * n; i++) col[i] = colsum[i] = 1;
    for (int i = 1, j = 1; i <= m; i++) {
        read(u[i]); read(v[i]);
        while (1) {
            // fprintf(stderr, "findroot(u[i]) = %d, findroot(v[i]) = %d\n", findroot(u[i]), findroot(v[i]));
            if (findroot(u[i]) != findroot(v[i])) break;
            makeroot(u[i]); access(v[i]); splay(v[i]);
            if (!sum[v[i]]) break;
            if (id[j]) {
                splay(id[j]);
                int tem = val[id[j]];
                if (tem) {
                    makeroot(u[tem]); access(v[tem]); splay(v[tem]);
                    add_tag(v[tem], 0);
                }
                cut(id[j], u[j]);
                cut(id[j], v[j]);
                rub[++top] = id[j];
                if (tem) {
                    id[tem] = newNode();
                    val[id[tem]] = rev[id[tem]] = 0; tag[id[tem]] = -1; update(id[tem]);
                    link(id[tem], u[tem]); link(id[tem], v[tem]);
                }
            } else {
                makeroot(u[j]); access(v[j]); splay(v[j]);
                add_tag(v[j], 0);
            }
            ++j;
        }
        if (findroot(u[i]) != findroot(v[i])) {
            id[i] = newNode();
            val[id[i]] = rev[id[i]] = 0; tag[id[i]] = -1; update(id[i]);
            link(id[i], u[i]); link(id[i], v[i]);
        } else {
            makeroot(u[i]); access(v[i]); splay(v[i]);
            add_tag(v[i], i);
        }
        ans += (i - j + 1);
    }
    print(ans, '\n');
    return 0;
}