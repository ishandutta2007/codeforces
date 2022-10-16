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

const int N = 105, M = 1e5 + 5, SZ = M;

int n, m, q, pos[M], L[M], R[M];
LL a[N], b[M], c[M], sum, tag[M], tot;

void inline add(int l, int r, int x) {
    int p = pos[l], q = pos[r];
    if (p == q) {
        for (int i = l; i <= r; i++)
            c[i] += x;    
    } else {
        for (int i = l; i <= R[p]; i++) c[i] += x;
        for (int i = L[q]; i <= r; i++) c[i] += x;
        for (int i = p + 1; i < q; i++) tag[i] += x;
    }
}

LL inline get(int x) {
    return c[x] + tag[pos[x]];
}

struct BIT{
    int n;
    LL c[SZ];
    void inline init(int len, LL a[]) {
        n = len;
        for (int i = 1; i <= n; i++) {
            c[i] += a[i];
            if (i + (i & -i) <= n) c[i + (i & -i)] += c[i];
        }
    }
    void inline add(int x, LL k) {
        for (; x <= n; x += x & -x) c[x] += k;
    }
    LL inline ask(int x) {
        LL res = 0;
        for (; x; x -= x & -x) res += c[x];
        return res;
    }
} ;

struct exBIT{
    BIT t1, t2;
    int n;
    void inline init(int len, LL a[]) {
        n = len;
        for (int i = 1; i <= n; i++) 
            b[i] = a[i] - a[i - 1];
        t1.init(n, b);
        for (int i = 1; i <= n; i++) b[i] *= i;
        t2.init(n, b);
    }
    void inline add(int l, int r, LL c) {
        t1.add(l, c), t1.add(r + 1, -c);
        t2.add(l, c * l), t2.add(r + 1, -c * (r + 1));
    }
    LL inline ask(int x) {
        return (x + 1) * t1.ask(x) - t2.ask(x);
    }
    LL inline ask(int x, int y) { return ask(y) - ask(x - 1); }
} t;

void inline work() {
    int x = 1, y = 1;
    LL ans = sum;
    int s = 1;
    while (x <= n) {
        int c = 0;
        if (x != n) {
            int l = y, r = m;
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if (get(mid) <= a[x + 1] - a[x]) l = mid;
                else r = mid - 1;
            }
            c = r - y;
        } else c = m - s;
        y += c;
        s += c;
        ans += c * a[x];
        if (x != n) ans += t.ask(1, s);
        x++;
    }
    printf("%lld\n", ans);
}
 
int main() {
    read(n); read(m), read(q);
    for (int i = 1; i <= n; i++) read(a[i]), sum += a[i];
    for (int i = 1; i <= m; i++) read(b[i]), c[i] = b[i] - b[i - 1], sum += b[i];
    tot = sqrt(m);
    for (int i = 1; i <= m; i++) {
        pos[i] = (i - 1) / tot + 1;
        R[pos[i]] = i;
        if (!L[pos[i]]) L[pos[i]] = i;
    }
    t.init(m, c);
    while (q--) {
        int op, k, d; read(op), read(k), read(d);
        if (op == 1) {
            for (int i = 1; i <= k; i++) {
                a[n - k + i] += i * d;
                sum += i * d;
            }
        } else {
            sum += k * (k + 1ll) / 2 * d;
            add(m - k + 1, m, d);
            t.add(m - k + 1, m, d);
        }
        work();
    }
    return 0;
}