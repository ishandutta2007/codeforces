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

const int N = 5e6 + 5, M = 2e5 + 5, md = 1e9 + 7;

inline int add(int x, int y) {
    if (x + y >= md) return x + y - md;
    return x + y;
}

inline void addx(int &x, int y) {
    x += y;
    if (x >= md) x -= md;
}

inline int sub(int x, int y) {
    if (x - y < 0) return x - y + md;
    return x - y;
}

inline void subx(int &x, int y) {
    x -= y;
    if (x < 0) x += md;
}

inline int mul(int x, int y) { return 1ll * x * y % md; }

inline int fpow(int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = mul(ans, x);
        y >>= 1; x = mul(x, x);
    }
    return ans;
}

int p[M], k[M], b[M], w[M];
int seed, base;

inline int rnd() {
    int ret = seed;
    seed = add(mul(seed, base), 233);
    return ret;
}

ll sum[N], res[N];
int ans[N], a[N], t[N], opt[N], l[N], r[N];
int n, m, tot;
ll cnt[3];

void gg() {
    int _ans = 1;
    for (int i = 1; i <= n; i++) _ans = mul(_ans, ((ans[i] ^ (1ll * i * i)) + 1) % md);
    print(_ans, '\n');
    exit(0);
}

int main() {
    read(n); read(m);
    for (int i = 1; i <= m; i++) {
        read(p[i]); read(k[i]); read(b[i]); read(w[i]);
        seed = b[i]; base = w[i];
        for (int j = p[i - 1] + 1; j <= p[i]; j++) {
            t[j] = rnd() % 2 + 1;
            a[j] = rnd() % k[i] + 1;
        }
    }
    --a[1]; ans[1] = 1;
    for (int i = 1; i <= n; i++) cnt[t[i]] += a[i];
    if (!cnt[3 - t[1]]) gg();
    int pos = 0;
    for (int i = 1; i <= n; i++) {
        if (t[i] == 3 - t[1]) {
            pos = i;
            break;
        }
    }
    int flag = 0;
    if (cnt[t[1]] < cnt[t[pos]]) {
        --a[pos];
        ans[pos] = 1;
        --cnt[t[pos]];
        flag = 1;
        tot = -1;
    }
    for (int i = pos; ; ) {
        ++tot; sum[tot] = a[i]; opt[tot] = t[i];
        int j = i;
        while (t[j % n + 1] == t[i]) {
            j = j % n + 1;
            sum[tot] += a[j];
        }
        l[tot] = i; r[tot] = j;
        i = j % n + 1;
        if (i == pos) break;
    }
    if (flag) {
        ++tot;
        sum[tot] = sum[0];
        opt[tot] = opt[0];
        l[tot] = l[0];
        r[tot] = r[0];
    }
    ll now = -sum[1], minn = -sum[1]; pos = 1;
    for (int i = tot; i >= 2; i--) {
        if (opt[i] == opt[1]) now -= sum[i];
        else now += sum[i];
        if (now < minn) {
            minn = now;
            pos = i;
        }
    }
    // fprintf(stderr, "tot = %d, sum[1] = %lld, sum[2] = %lld, opt[1] = %d, opt[2] = %d\n", tot, sum[1], sum[2], opt[1], opt[2]);
    now = 0;
    for (int i = pos; ; ) {
        if (opt[i] == opt[1]) now += sum[i];
        else {
            res[i] = min(now, sum[i]);
            now -= res[i];
        }
        i = i % tot + 1;
        if (i == pos) break;
    }
    for (int i = 1; i <= tot; i++) {
        if (opt[i] == opt[1]) res[i] = sum[i];
        for (int j = l[i]; ; j = j % n + 1) {
            ll det = min((ll)a[j], res[i]);
            ans[j] += det;
            res[i] -= det;
            if (j == r[i]) break;
        }
    }
    gg();
    return 0;
}