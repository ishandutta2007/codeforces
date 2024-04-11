// Skyqwq
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
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

const int N = 1e5 + 5, S = 10;

typedef pair<int, int> PII;

int n, P, a[N], q, pos[S];

map<int, int> b;

int inline power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = (LL)res * a % P;
        a = (LL)a * a % P;
        b >>= 1;
    }
    return res;
}

void inline add(int &x, int y) {
    x += y;
    if (x >= P) x -= P;
}


bool st[N];

int pr[N], tot;

void inline prework(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            pr[++tot] = i;
            for (int j = i + i; j <= n; j += i) st[j] = 1;
        }
    }
}
 
vector<PII> div(int x) {
    vector<PII> res;
    for (int i = 1; pr[i] <= x / pr[i]; i++) {
        if (x % pr[i] == 0) {
            int c = 0;
            while (x % pr[i] == 0) x /= pr[i], c++;
            res.pb(mp(pr[i], c));
        }
    }
    if (x > 1) res.pb(mp(x, 1));
    return res;
}

vector<PII> t;

#define ls (p << 1)
#define rs (p << 1 | 1)

int cnt[N << 2][10], tag[N << 2][10], s[N << 2], v[N << 2];

void inline pushup(int p) {
    s[p] = (s[ls] + s[rs]) % P;
    v[p] = (v[ls] + v[rs]) % P;
}

void inline mul(int p, int w, int k, int num) {
    tag[p][w] = 1ll * tag[p][w] * k % P;
    if (w == 0) {
        s[p] = 1ll * s[p] * k % P;
        v[p] = 1ll * v[p] * k % P;    
    } else {
        cnt[p][w] += num;
        s[p] = 1ll * s[p] * k % P;
    }
}

void inline pushdown(int p) {
    for (int i = 0; i < 10; i++) {
        if (tag[p][i] != 1) {
            mul(ls, i, tag[p][i], cnt[p][i]);
            mul(rs, i, tag[p][i], cnt[p][i]);
            tag[p][i] = 1, cnt[p][i] = 0;
        }
    }
}

void inline rebuild(int p) {
    for (int i = 0; i < t.size(); i++) {
        PII v = t[i];
        if (b.count(v.fi)) {
            cnt[p][b[v.fi]] -= v.se;
        }
    }
    s[p] = v[p];
    for (int i = 1; i <= 9; i++)
        s[p] = 1ll * s[p] * power(pos[i], cnt[p][i]) % P;
}

void build(int p, int l, int r) {
    for (int i = 0; i < 10; i++) tag[p][i] = 1;
    if (l == r) { s[p] = v[p] = 1; return; }
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    pushup(p);
}

void change(int p, int l, int r, int x, int y, int w, int k, int num) {
    if (x <= l && r <= y) {
        mul(p, w, k, num);
        return;
    }
    pushdown(p);
    int mid = (l + r) >> 1;
    if (x <= mid) change(ls, l, mid, x, y, w, k, num);
    if (mid < y) change(rs, mid + 1, r, x, y, w, k, num);
    pushup(p);
}

void inline change2(int p, int l, int r, int x) {
    if (l == r) {
        rebuild(p);
        return;
    }
    pushdown(p);
    int mid = (l + r) >> 1;
    if (x <= mid) change2(ls, l, mid, x);
    else change2(rs, mid + 1, r, x);
    pushup(p);
}

int inline query(int p, int l, int r, int x, int y) {
    if (x <= l && r <= y) return s[p];
    pushdown(p);
    int mid = (l + r) >> 1, res = 0;
    if (x <= mid) add(res, query(ls, l, mid, x, y));
    if (mid < y) add(res, query(rs, mid + 1, r, x, y));
    return res;
}

void inline Add(int l, int r, int x) {
    t = div(x);
    int w = 1;
    for (int i = 0; i < t.size(); i++) {
        PII v = t[i];
        if (b.count(v.fi)) {
            change(1, 1, n, l, r, b[v.fi], power(v.fi, v.se), v.se);
        } else w = 1ll * w * power(v.fi, v.se) % P;
    }
    if (w > 1) change(1, 1, n, l, r, 0, w, 0);
}

LL exgcd(LL a, LL b, LL &x, LL &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    LL d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int inline Inv(int a) {
    LL x, y;
    exgcd(a, P, x, y);
    x = (x % P + P) % P;
    return x;
}

void inline Div(int x, int k) {
    t = div(k);
    int w = 1;
    for (int i = 0; i < t.size(); i++) {
        PII v = t[i];
        if (!b.count(v.fi)) w = 1ll * w * power(v.fi, v.se);
    }
    w = Inv(w);
    if (w > 1) change(1, 1, n, x, x, 0, w, 0);
    change2(1, 1, n, x);
}

int inline Query(int l, int r) {
    return query(1, 1, n, l, r);
}

int main() {
    read(n), read(P); prework(100000);
    t = div(P);
    for (int i = 0; i < t.size(); i++) {
        b[t[i].fi] = i + 1;
        pos[i + 1] = t[i].fi;
    }
    build(1, 1, n);
    for (int i = 1; i <= n; i++) {
        read(a[i]);
        Add(i, i, a[i]);
    }
    read(q);
    while (q--) {
        int op; read(op);
        if (op == 1) {
            int l, r, x; read(l), read(r), read(x);
            Add(l, r, x);
        } else if (op == 2) {
            int p, x; read(p), read(x);
            Div(p, x);
        } else {
            int l, r; read(l), read(r);
            printf("%d\n", Query(l, r));
        }
    }
	return 0;
}