// Skyqwq
#include <iostream>
#include <cstdio>
#include <vector>
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}
 
template <typename T> void print(T x) {
	if (x < 0) { putchar('-'); print(-x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 2.5e6 + 5;

int n, nxt[N], in[N], q[N], pos[N];

vector<int> g[N];
 
void inline clear() {
    for (int i = 1; i <= 5 * n; i++) g[i].clear(), in[i] = 0;;
} 

#define ls (p << 1)
#define rs (p << 1 | 1)

void build(int p, int l, int r) {
    if (l == r)  { 
        g[r].pb(p + n);
        in[p + n]++;
        return; 
    } 
    int mid = (l + r) >> 1;
    g[ls + n].pb(p + n);
    g[rs + n].pb(p + n);
    in[p + n] += 2;
    build(ls, l, mid);
    build(rs, mid + 1, r);
}

void link(int p, int l, int r, int x, int y, int k) {
    if (x > y) return;
    if (x <= l && r <= y) {
        g[p + n].pb(k); in[k]++;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) link(ls, l, mid, x, y, k);
    if (mid < y) link(rs, mid + 1, r, x, y, k);
}

bool inline topo() {
    int cnt = 0, hh = 1, tt = 0, t = 0;
    for (int i = 1; i <= 5 * n; i++)
        if (!in[i]) q[++tt] = i;
    while (hh <= tt) {
        int u = q[hh++]; ++cnt;
        if (u <= n) pos[u] = ++t;
        for (int v : g[u]) {
            if (--in[v] == 0) q[++tt] = v;
        }
    }
    return cnt == 5 * n;
}

int main() {
    int T; read(T);
    while (T--) {
        read(n);
        build(1, 1, n);
        for (int i = 1; i <= n; i++) read(nxt[i]);
        for (int i = 1; i <= n; i++) {
            if (nxt[i] == -1) continue;
            if (nxt[i] <= n) g[i].pb(nxt[i]), in[nxt[i]]++;
            link(1, 1, n, i + 1, nxt[i] - 1, i);
        }
        if (!topo()) puts("-1");
        else { for (int i = 1; i <= n; i++) printf("%d ", pos[i]); puts(""); } 
        clear();
    }
	return 0;
}