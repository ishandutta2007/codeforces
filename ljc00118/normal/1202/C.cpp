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
 
const ll INF = 0x7fffffffffffffff;
const int N = 2e5 + 5;
 
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
 
struct ele {
    int x, y, mn[2], mx[2];
    ele () {
        x = y = 0;
        mn[0] = mn[1] = mx[0] = mx[1] = 0;
    }
};
 
struct node_t {
    int l, r;
    ele val;
} p[N << 2];
 
char c[N];
int T, n;
ll ans;
 
inline int calc(char c) {
    if(c == 'W') return 0;
    if(c == 'S') return 1;
    if(c == 'A') return 2;
    return 3;
}
 
ele operator + (const ele a, int wd) {
    ele ans = a;
    ans.x += dx[wd];
    ans.y += dy[wd];
    ans.mn[0] = min(ans.mn[0], ans.x);
    ans.mn[1] = min(ans.mn[1], ans.y);
    ans.mx[0] = max(ans.mx[0], ans.x);
    ans.mx[1] = max(ans.mx[1], ans.y);
    return ans;
}
 
ele operator + (const ele a, const ele b) {
    ele ans = a;
    ans.mn[0] = min(ans.mn[0], ans.x + b.mn[0]);
    ans.mn[1] = min(ans.mn[1], ans.y + b.mn[1]);
    ans.mx[0] = max(ans.mx[0], ans.x + b.mx[0]);
    ans.mx[1] = max(ans.mx[1], ans.y + b.mx[1]);
    ans.x += b.x; ans.y += b.y;
    return ans;
}
 
void build(int u, int l, int r) {
    p[u].l = l; p[u].r = r;
    if(l == r) {
        p[u].val = ele() + calc(c[l]);
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
    p[u].val = p[u << 1].val + p[u << 1 | 1].val;
}
 
ele query(int u, int l, int r) {
    if(l > r) return ele();
    if(l <= p[u].l && p[u].r <= r) return p[u].val;
    int mid = (p[u].l + p[u].r) >> 1; ele ans;
    if(mid >= l) ans = ans + query(u << 1, l, r);
    if(mid + 1 <= r) ans = ans + query(u << 1 | 1, l, r);
    return ans;
}
 
int main() {
    read(T);
    while(T--) {
        ans = INF;
        scanf("%s", c + 1); n = strlen(c + 1);
        build(1, 1, n);
        for(register int i = 0; i <= n; i++) {
            ele l = query(1, 1, i), r = query(1, i + 1, n);
            for(register int j = 0; j <= 3; j++) {
                ele sum = l + j + r;
                ans = min(ans, 1ll * (sum.mx[0] - sum.mn[0] + 1) * (sum.mx[1] - sum.mn[1] + 1));
            }
        }
        print(ans, '\n');
    }
    return 0;
}