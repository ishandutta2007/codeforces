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

const int N = 65;

int used[N], a[N], fac[N], inv[N], b[15], f[1 << 15], g[1 << 15], t[1 << 15];
int n, m, ans = 1, sum;

int main() {
    read(n);
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = mul(fac[i - 1], i);
        inv[i] = fpow(fac[i], md - 2);
    }
    for (int i = 1; i <= n; i++) read(a[i]);
    for (int i = 1; i <= n; i++) {
        if (used[i]) continue;
        vector <int> seq;
        queue <int> q; used[i] = 1; q.push(i);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            seq.push_back(u);
            for (int j = 1; j <= n; j++) {
                if (used[j]) continue;
                if (a[u] % a[j] == 0 || a[j] % a[u] == 0) {
                    used[j] = 1;
                    q.push(j);
                }
            }
        }
        m = -1;
        for (auto x : seq) {
            int cando = 1;
            for (auto y : seq) {
                if (x == y) continue;
                if (a[x] % a[y] == 0) cando = 0;
            }
            if (cando) b[++m] = x;
        }
        memset(f, 0, sizeof(f)); memset(g, 0, sizeof(g));
        vector <int> qwq;
        for (auto j : seq) {
            int cando = 1, st = 0;
            for (int k = 0; k <= m; k++) {
                if (j == b[k]) {
                    cando = 0;
                    break;
                }
                if (a[j] % a[b[k]] == 0) st |= (1 << k);
            }
            if (cando) {
                ++t[st]; qwq.push_back(st);
                for (int k = 0; k < (1 << (m + 1)); k++) {
                    if ((k & st) == st) ++g[k];
                }
            }
        }
        int all = (int)seq.size() - m - 1;
        if (!all) continue;
        f[0] = 1;
        for (int i = 0; i < (1 << (m + 1)); i++) {
            for (auto j : qwq) {
                if ((!i || (i & j)) && (i & j) != j) {
                    f[i | j] = add(f[i | j], mul(f[i], mul(fac[all - g[i] - 1], inv[all - g[i | j]])));
                }
            }
        }
        ans = mul(ans, f[(1 << (m + 1)) - 1]);
        ans = mul(ans, inv[all - 1]); sum += all - 1;
    }
    print(mul(ans, fac[sum]), '\n');
    return 0;
}