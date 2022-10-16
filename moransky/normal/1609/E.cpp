// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 1e5 + 5;

int tot, n, q;

struct E{
    int u, v, w;
} e[N];
 
bool inline chk(int x) {
    if (x >> 3 & 1) {
        if (!(x & 1)) return 0;
        if (!(x >> 1 & 1)) return 0;
    }
    if (x >> 4 & 1) {
        if (!(x >> 2 & 1)) return 0;
        if (!(x >> 1 & 1)) return 0;
    }
    return 1;
}

const int INF = 0x3f3f3f3f;

struct Node{
    int w[32];
} t[N << 2];

Node operator + (const Node &a, const Node &b) {
    Node c;
    memset(c.w, 0x3f, sizeof c.w);
    for (int i = 1; i <= tot; i++) {
        chkMin(c.w[e[i].w], a.w[e[i].u] + b.w[e[i].v]);
    }
    return c;
}

char s[N], op[5];

Node inline get(int c) {
    Node u;
    memset(u.w, 0x3f, sizeof u.w);
    u.w[1 << c] = 0;
    int a = 0;
    if (a == c) a++;
    int b = 3 - a - c;
    u.w[1 << b] = 1;
    u.w[1 << a] = 1;
    return u;
}

#define ls p << 1
#define rs p << 1 | 1

void inline pushup(int p) {
    t[p] = t[ls] + t[rs];
}

void build(int p, int l, int r) {
    if (l == r) {
        t[p] = get(s[r] - 'a');
        return;
    }
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    pushup(p);
}

void change(int p, int l, int r, int x, int y) {
    if (l == r) {
        t[p] = get(y);
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) change(ls, l, mid, x, y);
    else change(rs, mid + 1, r, x, y);
    pushup(p);
} 

void inline out() {
    int ans = INF;
    for (int i = 0; i < (1 << 5); i++)
        chkMin(ans, t[1].w[i]);
    printf("%d\n", ans);
}

void inline prework() {
    for (int x = 0; x < (1 << 5); x++) {
        for (int y = 0; y < (1 << 5); y++) {
            bool o = 1;
            int z = x | y;
            if (!chk(x) || !chk(y)) continue;
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    if (x >> i & 1) {
                        if (y >> j & 1) {
                            if (i == 0 && j == 4) {
                                o = 0;
                            }
                            if (i == 3 && j == 2) {
                                o = 0;
                            }
                            if (i == 0 && j == 1) z |= 1 << 3;
                            if (i == 1 && j == 2) z |= 1 << 4;
                        }
                    }
                }
            }
            if (o) e[++tot] = (E) { x, y, z}; 
        }
    }
}

int main() {
    prework();
    read(n); read(q);
    scanf("%s", s + 1);
    build(1, 1, n);
    while (q--) {
        int i; read(i); scanf("%s", op);
        change(1, 1, n, i, op[0] - 'a');
        out();
    }
    return 0;
}