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

const int N = 2e5 + 5, eps = 1e-8, INF = 0x7fffffff;

struct segtree {
    int maxn[N << 2], minn[N << 2];
    double val[N];

    void update(int u) {
        if(val[maxn[u << 1]] > val[maxn[u << 1 | 1]]) maxn[u] = maxn[u << 1]; else maxn[u] = maxn[u << 1 | 1];
        if(val[minn[u << 1]] < val[minn[u << 1 | 1]]) minn[u] = minn[u << 1]; else minn[u] = minn[u << 1 | 1];
    }

    void change(int u, int l, int r, int x, double y) {
        if(l == r) {
            val[l] = y; maxn[u] = minn[u] = l;
            return;
        }
        int mid = (l + r) >> 1;
        if(mid >= x) change(u << 1, l, mid, x, y);
        else change(u << 1 | 1, mid + 1, r, x, y);
        update(u);
    }
} a, d;

double ans;
int cnt[N], p[N], l[N];
int n, t, q;

bool check(double x, double y) { return fabs(x - y) <= eps; }

double calc(double x, double y) { return (x + 1) / (y + 1) - x / y; }

void add(int wz) {
    ans += a.val[wz]; ++cnt[wz];
    d.change(1, 1, n, wz, a.val[wz]);
    if(cnt[wz] == l[wz]) a.change(1, 1, n, wz, -1);
    else a.change(1, 1, n, wz, calc(cnt[wz], cnt[wz] + l[wz]) * p[wz]);
    --t;
}

void del(int wz) {
    ans -= d.val[wz]; --cnt[wz];
    if(cnt[wz] < l[wz]) a.change(1, 1, n, wz, d.val[wz]);
    else a.change(1, 1, n, wz, -1);
    if(cnt[wz] == 0) d.change(1, 1, n, wz, INF);
    else d.change(1, 1, n, wz, calc(cnt[wz] - 1, cnt[wz] + l[wz] - 1) * p[wz]);
    ++t;
}

int main() {
    read(n); read(t); read(q);
    for(register int i = 1; i <= n; i++) read(p[i]);
    for(register int i = 1; i <= n; i++) read(l[i]);
    for(register int i = 1; i <= n; i++) {
        a.change(1, 1, n, i, calc(0, l[i]) * p[i]);
        d.change(1, 1, n, i, INF);
    }
    while(t && !check(a.val[a.maxn[1]], -1)) add(a.maxn[1]);
    while(q--) {
        int opt, x;
        read(opt); read(x);
        if(opt == 1) {
            ans -= (double)cnt[x] / (cnt[x] + l[x]) * p[x];
            ++l[x];
            ans += (double)cnt[x] / (cnt[x] + l[x]) * p[x];
            a.change(1, 1, n, x, calc(cnt[x], cnt[x] + l[x]) * p[x]);
            if(cnt[x]) d.change(1, 1, n, x, calc(cnt[x] - 1, cnt[x] + l[x] - 1) * p[x]);
            while(t && !check(a.val[a.maxn[1]], -1)) add(a.maxn[1]);
            while(a.val[a.maxn[1]] > d.val[d.minn[1]]) {
                int tmp = d.minn[1];
                del(tmp);
                add(a.maxn[1]);
            }
        }
        if(opt == 2) {
            ans -= (double)cnt[x] / (cnt[x] + l[x]) * p[x];
            --l[x];
            ans += (double)cnt[x] / (cnt[x] + l[x]) * p[x];
            if(cnt[x] < l[x]) a.change(1, 1, n, x, calc(cnt[x], cnt[x] + l[x]) * p[x]);
            else a.change(1, 1, n, x, -1);
            if(cnt[x]) d.change(1, 1, n, x, calc(cnt[x] - 1, cnt[x] + l[x] - 1) * p[x]);
            if(cnt[x] > l[x]) del(x);
            while(t && !check(a.val[a.maxn[1]], -1)) add(a.maxn[1]);
            while(a.val[a.maxn[1]] > d.val[d.minn[1]]) {
                int tmp = d.minn[1];
                del(tmp);
                add(a.maxn[1]);
            }
        }
        printf("%.7lf\n", ans);
    }
    return 0;
}