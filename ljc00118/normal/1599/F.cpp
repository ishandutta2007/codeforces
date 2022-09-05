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

const int md = 1e9 + 7;

inline int add(int x, int y) {
    if (x + y >= md) return x + y - md;
    return x + y;
}

inline void addx(int &x, int y) {
    x += y;
    if (x >= md) x -= md;
}

inline int sub(int x, int y) {
    if (x < y) return x - y + md;
    return x - y;
}

inline void subx(int &x, int y) {
    x -= y;
    if (x < 0) x += md;
}

inline int mul(int x, int y) { return 1ull * x * y % md; }

inline int fpow(int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = mul(ans, x);
        y >>= 1; x = mul(x, x);
    }
    return ans;
}

const int N = 2e5 + 5, M = 10;

int a[N];
int n, q;

struct fenwick {
    int f[N];

    void add(int x, int y) {
        while (x <= n) {
            f[x] = ::add(f[x], y);
            x += (x & -x);
        }
    }

    int query(int x) {
        int ans = 0;
        while (x) {
            ans = ::add(ans, f[x]);
            x &= (x - 1);
        }
        return ans;
    }

    int query(int l, int r) {
        return sub(query(r), query(l - 1));
    }
} tr[M + 1];

map <int, int> pre;
vector <int> qry[N];
int C[M + 1][M + 1], s[M + 1][N], l[N], r[N], d[N], ans[N];

int main() {
    for (int i = 0; i <= M; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
    }
    read(n); read(q);
    for (int i = 1; i <= n; i++) read(a[i]);
    for (int i = 0; i <= n; i++) {
        int now = 1;
        for (int j = 0; j <= M; j++) {
            s[j][i] = now;
            now = mul(now, i);
        }
    }
    for (int i = 0; i <= M; i++) {
        for (int j = 1; j <= n; j++) s[i][j] = add(s[i][j - 1], s[i][j]);
    }
    for (int i = 1; i <= q; i++) {
        read(l[i]); read(r[i]); read(d[i]);
        qry[r[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        if (pre.count(a[i])) {
            int pos = pre[a[i]];
            int now = 1;
            for (int j = 0; j <= M; j++) {
                tr[j].add(pos, sub(0, now));
                now = mul(now, a[i]);
            }
        }
        int now = 1;
        for (int j = 0; j <= M; j++) {
            tr[j].add(i, now);
            now = mul(now, a[i]);
        }
        pre[a[i]] = i;
        for (auto id : qry[i]) {
            int cnt = tr[0].query(l[id], r[id]);
            int sum = tr[1].query(l[id], r[id]);
            int x = mul(mul(2, sum), fpow(cnt, md - 2));
            x = mul(sub(x, mul(cnt - 1, d[id])), (md + 1) / 2);
            static int pwx[M + 1], pwd[M + 1];
            pwx[0] = pwd[0] = 1;
            for (int t = 1; t <= M; t++) {
                pwx[t] = mul(pwx[t - 1], x);
                pwd[t] = mul(pwd[t - 1], d[id]);
            }
            // fprintf(stderr, "id = %d, x = %d, cnt = %d\n", id, x, cnt);
            ans[id] = 1;
            for (int j = 2; j <= M; j++) {
                int val = 0;
                for (int t = 0; t <= j; t++) {
                    val = add(val, mul(mul(C[j][t], mul(pwx[t], pwd[j - t])), s[j - t][cnt - 1]));
                }
                // fprintf(stderr, "id = %d, j = %d, val = %d\n", id, j, val);
                if (val != tr[j].query(l[id], r[id])) {
                    ans[id] = 0;
                    break;
                }
            }
        }
    }
    for (int i = 1; i <= q; i++) printf("%s\n", ans[i] ? "Yes" : "No");
    return 0;
}