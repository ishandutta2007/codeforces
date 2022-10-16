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

typedef unsigned long long ULL;

const int N = 4e5 + 5;

mt19937 rnd(114333);

int n, d[N], t;

ULL h[N], X[N], Y[N];

struct E{
    int x, y, id;
    bool operator < (const E &b) const {
        if (x == b.x) return y < b.y;
        return x < b.x;
    }
} a[N], b[N];
 
int inline get(int x) {
    return lower_bound(d + 1, d + 1 + t, x) - d;
}

ULL c[N];

void inline add(int x, ULL k) {
    for (; x <= t; x += x & -x) c[x] += k;
}

ULL inline ask(int x) {
    ULL ret = 0;
    for (; x; x -= x & -x) ret += c[x];
    return ret;
}

int main() {
    read(n);
    for (int i = 1; i <= n; i++) {
        h[i] = rnd();
        read(a[i].x), read(a[i].y), read(b[i].x), read(b[i].y);
        d[++t] = a[i].x;
        d[++t] = a[i].y;
        d[++t] = b[i].x;
        d[++t] = b[i].y;
        a[i].id = b[i].id = i;
    }
    sort(d + 1, d + 1 + t);
    t = unique(d + 1, d + 1 + t) - d - 1;
    for (int i = 1; i <= n; i++) {
        a[i].x = get(a[i].x);
        a[i].y = get(a[i].y);
        b[i].x = get(b[i].x);
        b[i].y = get(b[i].y);
    }
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i++) {
        X[a[i].id] += ask(t) - ask(a[i].x - 1);
        add(a[i].y, h[a[i].id]);
    }
    memset(c, 0, sizeof c);
    for (int i = 1; i <= n; i++) {
        Y[b[i].id] += ask(t) - ask(b[i].x - 1);
        add(b[i].y, h[b[i].id]);
    }
    memset(c, 0, sizeof c);
    for (int i = n; i; i--) {
        X[a[i].id] += ask(a[i].y);
        add(a[i].x, h[a[i].id]);
    }
    memset(c, 0, sizeof c);
    for (int i = n; i; i--) {
        Y[b[i].id] += ask(b[i].y);
        add(b[i].x, h[b[i].id]);
    }
    for (int i = 1; i <= n; i++) {
        if (X[i] != Y[i]) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}