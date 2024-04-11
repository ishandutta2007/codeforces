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
 
template <typename T>
struct hash_map_t {
    vector <T> v, val, nxt;
    vector <int> head;
    int mod, tot, lastv;
    T lastans;
    bool have_ans;
 
    hash_map_t (int md = 0) {
        head.clear(); v.clear(); val.clear(); nxt.clear(); tot = 0; mod = md;
        nxt.resize(1); v.resize(1); val.resize(1); head.resize(mod);
        have_ans = 0;
    }
 
    void clear() { *this = hash_map_t(mod); }
 
    bool count(int x) {
        int u = x % mod;
        for(register int i = head[u]; i; i = nxt[i]) {
            if(v[i] == x) {
                have_ans = 1;
                lastv = x;
                lastans = val[i];
                return 1;
            }
        }
        return 0;
    }
 
    void ins(int x, int y) {
        int u = x % mod;
        nxt.push_back(head[u]); head[u] = ++tot;
        v.push_back(x); val.push_back(y);
    }
 
    int qry(int x) {
        if(have_ans && lastv == x) return lastans;
        count(x);
        return lastans;
    }
};
 
const int N = 3e5 + 5;
 
struct node_t { int l, r, maxn; } p[N << 2];
 
int a[N], b[N], t1[N], t2[N], now[N], pre[N];
int T, n;
 
void update(int u) { p[u].maxn = max(p[u << 1].maxn, p[u << 1 | 1].maxn); }
 
void build(int u, int l, int r) {
    p[u].l = l; p[u].r = r;
    if(l == r) {
        p[u].maxn = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
    update(u);
}
 
void change(int u, int x) {
    if(p[u].l == p[u].r) {
        p[u].maxn = 0;
        return;
    }
    int mid = (p[u].l + p[u].r) >> 1;
    if(mid >= x) change(u << 1, x);
    else change(u << 1 | 1, x);
    update(u);
}
 
int query(int u, int l, int r) {
    if(l <= p[u].l && p[u].r <= r) return p[u].maxn;
    int mid = (p[u].l + p[u].r) >> 1, ans = 0;
    if(mid >= l) ans = query(u << 1, l, r);
    if(mid + 1 <= r) ans = max(ans, query(u << 1 | 1, l, r));
    return ans;
}
 
int main() {
    read(T);
    while(T--) {
        read(n);
        for(register int i = 1; i <= n; i++) read(a[i]), t1[i] = a[i];
        for(register int i = 1; i <= n; i++) read(b[i]), t2[i] = b[i];
        sort(t1 + 1, t1 + n + 1); sort(t2 + 1, t2 + n + 1);
        bool ok = 1;
        for(register int i = 1; i <= n; i++) {
            if(t1[i] != t2[i]) {
                ok = 0;
                break;
            }
        }
        if(!ok) {
            printf("NO\n");
            continue;
        }
        for(register int i = 1; i <= n; i++) now[i] = 0;
        for(register int i = 1; i <= n; i++) if(!now[t1[i]]) now[t1[i]] = i;
        for(register int i = 1; i <= n; i++) t2[i] = now[i];
        for(register int i = 1; i <= n; i++) {
            int tmp = a[i];
            a[i] = now[a[i]];
            ++now[tmp];
            pre[a[i]] = i;
        }
        for(register int i = 1; i <= n; i++) now[i] = t2[i];
        for(register int i = 1; i <= n; i++) {
            int tmp = b[i];
            b[i] = now[b[i]];
            ++now[tmp];
        }
        build(1, 1, n);
        // for(register int i = 1; i <= n; i++) {
        //     fprintf(stderr, "%d %d %d\n", a[i], b[i], pre[b[i]]);
        // }
        for(register int i = n; i >= 1; i--) {
            if(query(1, pre[b[i]], n) > b[i]) {
                ok = 0;
                break;
            }
            change(1, pre[b[i]]);
        }
        if(!ok) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }
    return 0;
}