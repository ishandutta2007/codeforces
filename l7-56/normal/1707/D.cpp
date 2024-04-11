#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef vector <int> vi;
#define fir first
#define sec second
template <typename __Tp> void read(__Tp &x) {
    int f = 0; x = 0; char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 1;
    for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
    if (f) x = -x;
}
template <typename __Tp1, typename ...__Tp2> void read(__Tp1 &x, __Tp2 &...y) { read(x), read(y...); }
template <typename __Tp> void write(__Tp x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar(x % 10 + 48);
}
void write(char ch) { putchar(ch); }
template <typename __Tp1, typename ...__Tp2> void write(__Tp1 x, __Tp2 ...y) { write(x), write(y...); }

const int maxn = 2010;
int n, mod, f[maxn][maxn], s[maxn][maxn], pre[maxn][maxn], suf[maxn][maxn], C[maxn][maxn];
vi e[maxn];
void dfs(int u, int fa) {
    int c = 0;
    for (int v : e[u]) if (v != fa) dfs(v, u);
    for (int v : e[u]) if (v != fa) {
        ++c;
        for (int j = 0; j <= n; ++j)
            pre[c][j] = suf[c][j] = s[v][j];
    }
    if (!c) {
        for (int j = 1; j <= n; ++j) f[u][j] = 1, s[u][j] = j;
        return;
    }
    for (int j = 0; j <= n; ++j) {
        for (int i = 1; i <= c; ++i)
            pre[i][j] = (ll) pre[i][j] * pre[i - 1][j] % mod;
        for (int i = c; i >= 1; --i)
            suf[i][j] = (ll) suf[i][j] * suf[i + 1][j] % mod;
    }
    for (int i = 1; i <= n; ++i) f[u][i] = pre[c][i];
    if (u != 1) {
        c = 0;
        for (int v : e[u]) if (v != fa) {
            int sum = 0;
            ++c;
            for (int i = 1; i <= n; ++i)
                f[u][i] = (f[u][i] + (ll) sum * f[v][i] % mod) % mod,
                sum = (sum + (ll) pre[c - 1][i] * suf[c + 1][i] % mod) % mod;
        }
    }
    for (int i = 1; i <= c; ++i)
        for (int j = 0; j <= n; ++j)
            pre[i][j] = suf[i][j] = 1;
    for (int i = 1; i <= n; ++i)
        s[u][i] = (f[u][i] + s[u][i - 1]) % mod;
}

int main() {
    read(n, mod);
    for (int i = 1; i < n; ++i) {
        int x, y; read(x, y);
        e[x].push_back(y), e[y].push_back(x);
    }

    for (int i = 0; i <= maxn; ++i) fill(pre[i], pre[i] + maxn, 1), fill(suf[i], suf[i] + maxn, 1);
    dfs(1, 0);
    C[0][0] = 1;
    for (int i = 1; i < maxn; ++i) {
        C[i][0] = 1;
        for (int j = 1; j < maxn; ++j)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    }
    for (int i = 1; i < n; ++i) {
        int ans = 0;
        for (int j = 1; j <= i; ++j)
            ans = (ans + (ll) ((i - j) & 1 ? -1 : 1) * C[i][j] * f[1][j] % mod) % mod;
        ans = (ans % mod + mod) % mod;
        write(ans, " \n"[i == n - 1]);
    }
 	return 0;
}