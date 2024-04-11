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

const int N = 5e5 + 5;

struct UFS {
    int fa[N], siz[N], val[N], st[N];
    int n, top;

    void init_t(int n) {
        for(register int i = 1; i <= n; i++) {
            fa[i] = 0;
            siz[i] = 1;
            val[i] = 0;
        }
    }

    int find(int x) {
        while(fa[x]) x = fa[x];
        return x;
    }

    int dis(int x) {
        int ans = 0;
        while(x) ans ^= val[x], x = fa[x];
        return ans;
    }

    void merge(int u, int v, int x = 0, int y = 0) {
        if(!x) x = find(u), y = find(v);
        if(siz[x] > siz[y]) swap(x, y);
        val[x] = dis(u) ^ dis(v) ^ 1; fa[x] = y; siz[y] += siz[x]; st[++top] = x;
    }

    void revoke(int ti) {
        while(top != ti) {
            int u = st[top--];
            siz[fa[u]] -= siz[u]; fa[u] = val[u] = 0;
        }
    }
} ufs[51];

vector <int> G[N << 2];
int col[N], las[N], id[N], c[N], x[N], y[N], ans[N];
int n, m, k, q;

void change(int u, int L, int R, int l, int r, int id) {
    if(l <= L && R <= r) {
        G[u].push_back(id);
        return;
    }
    int mid = (L + R) >> 1;
    if(mid >= l) change(u << 1, L, mid, l, r, id);
    if(mid + 1 <= r) change(u << 1 | 1, mid + 1, R, l, r, id);
}

int now[30][55];
void query(int u, int l, int r, int dep) {
    for(register int i = 1; i <= k; i++) now[dep][i] = ufs[i].top;
    for(register int i = 0; i < (int)G[u].size(); i++) {
        if(!col[G[u][i]]) continue;
        int c = col[G[u][i]];
        // no odd cycle
        if(ufs[c].find(x[G[u][i]]) != ufs[c].find(y[G[u][i]])) {
            // fprintf(stderr, "merge : %d %d %d\n", c, x[G[u][i]], y[G[u][i]]);
            ufs[c].merge(x[G[u][i]], y[G[u][i]]);
        }
    }
    if(l == r) {
        int _x = ufs[c[l]].find(x[id[l]]), _y = ufs[c[l]].find(y[id[l]]);
        // fprintf(stderr, "c[%d] = %d, _x = %d, _y = %d\n", l, c[l], _x, _y);
        if(_x == _y) {
            if(ufs[c[l]].dis(x[id[l]]) ^ ufs[c[l]].dis(y[id[l]]) ^ 1) {
                ans[l] = 0;
            } else {
                ans[l] = 1;
                col[id[l]] = c[l];
            }
        } else {
            ans[l] = 1;
            col[id[l]] = c[l];
        }
        return;
    }
    int mid = (l + r) >> 1;
    query(u << 1, l, mid, dep + 1); query(u << 1 | 1, mid + 1, r, dep + 1);
    for(register int i = 1; i <= k; i++) ufs[i].revoke(now[dep][i]);
}

int main() {
    read(n); read(m); read(k); read(q);
    for(register int i = 1; i <= k; i++) ufs[i].init_t(n);
    for(register int i = 1; i <= m; i++) read(x[i]), read(y[i]);
    for(register int i = 1; i <= q; i++) {
        read(id[i]); read(c[i]);
        if(las[id[i]] && las[id[i]] + 1 <= i - 1) change(1, 1, q, las[id[i]] + 1, i - 1, id[i]);
        las[id[i]] = i;
    }
    for(register int i = 1; i <= m; i++) {
        if(las[i] && las[i] + 1 <= q) {
            change(1, 1, q, las[i] + 1, q, i);
        }
    }
    query(1, 1, q, 1);
    for(register int i = 1; i <= q; i++) {
        if(ans[i]) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}