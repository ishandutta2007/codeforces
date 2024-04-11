#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
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

const int N = 2005, md = 1e9 + 7, base = 19491001, inv2 = (md + 1) >> 1;

inline int add(int x, int y) {
    x += y;
    if (x >= md) x -= md;
    return x;
}

inline void addx(int &x, int y) {
    x += y;
    if (x >= md) x -= md;
}

inline int sub(int x, int y) {
    x -= y;
    if (x < 0) x += md;
    return x;
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

struct hash_t {
    char c[N];
    ull ha[N], pw[N];
    int n, opt;
    
    void ini(int a, int b) {
        n = a; opt = b; pw[0] = 1;
        for (int i = 1; i <= n; i++) {
            pw[i] = pw[i - 1] * base;
            ha[i] = ha[i - 1] * base + c[i] + 233;
        }
    }

    inline ull qry(int l, int r) {
        if (opt) l = n - l + 1, r = n - r + 1;
        // fprintf(stderr, "! l = %d, r = %d\n", l, r);
        return ha[r] - ha[l - 1] * pw[r - l + 1];
    }
} ha[2][2], he;

int f[2][N][2];
char c[2][N], t[N];
int n, m, ans;

void solve() {
    memcpy(he.c, t, sizeof(char) * N); he.ini(m, 0);
    memset(f, 0, sizeof(f));
    for (int i = 1, now = 0, las = 1; i <= n; i++, swap(now, las)) {
        memset(f[now], 0, sizeof(f[now]));
        if (c[0][i] == t[1]) addx(f[now][1][0], 1);
        if (c[1][i] == t[1]) addx(f[now][1][1], 1);
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= 1; k++) {
                if (!f[las][j][k]) continue;
                if (c[k][i] == t[j + 1]) {
                    addx(f[now][j + 1][k], f[las][j][k]);
                    if (c[k ^ 1][i] == t[j + 2]) addx(f[now][j + 2][k ^ 1], f[las][j][k]);
                }
                // fprintf(stderr, "i = %d, j = %d, k = %d, f = %d\n", i - 1, j, k, f[las][j][k]);
            }
        }
        addx(ans, add(f[now][m][0], f[now][m][1]));
        // fprintf(stderr, "i = %d : %d %d\n", i, f[now][m][0], f[now][m][1]);
        for (int j = 1; j <= m / 2; j++) {
            int cando1 = 0, cando2 = 0, cando3 = 0, cando4 = 0;
            if (i >= j && ha[0][1].qry(i, i - j + 1) == he.qry(1, j) && ha[1][0].qry(i - j + 1, i) == he.qry(j + 1, 2 * j)) addx(f[now][j * 2][1], 1), cando1 = 1;
            if (i >= j && ha[1][1].qry(i, i - j + 1) == he.qry(1, j) && ha[0][0].qry(i - j + 1, i) == he.qry(j + 1, 2 * j)) addx(f[now][j * 2][0], 1), cando2 = 1;
            if (j > 1 && i <= n - j + 1 && ha[0][0].qry(i, i + j - 1) == he.qry(m - 2 * j + 1, m - j) && ha[1][1].qry(i + j - 1, i) == he.qry(m - j + 1, m)) addx(ans, f[las][m - 2 * j][0]), cando3 = 1;
            if (j > 1 && i <= n - j + 1 && ha[1][0].qry(i, i + j - 1) == he.qry(m - 2 * j + 1, m - j) && ha[0][1].qry(i + j - 1, i) == he.qry(m - j + 1, m)) addx(ans, f[las][m - 2 * j][1]), cando4 = 1;
            // fprintf(stderr, "i = %d, j = %d : %d %d %d %d\n", i, j, cando1, cando2, cando3, cando4);
            if (j * 2 == m) addx(ans, mul(cando1 + cando2 + cando3 + cando4, inv2));
        }
    }
}

int vis[2][N];
void dfs1(int x, int y, int len) {
    if (c[x][y] != t[len] || vis[x][y]) return;
    if (len == m) {
        ++ans;
        return;
    }
    vis[x][y] = 1;
    if (!x) dfs1(x + 1, y, len + 1);
    else dfs1(x - 1, y, len + 1);
    if (y != 1) dfs1(x, y - 1, len + 1);
    if (y != n) dfs1(x, y + 1, len + 1);
    vis[x][y] = 0;
}

int main() {
    scanf("%s%s%s", c[0] + 1, c[1] + 1, t + 1);
    n = strlen(c[0] + 1); m = strlen(t + 1);
    if (m <= 6) {
        for (int i = 0; i <= 1; i++) {
            for (int j = 1; j <= n; j++) {
                dfs1(i, j, 1);
            }
        }
        print(ans, '\n');
        return 0;
    }
    memcpy(ha[0][0].c, c[0], sizeof(char) * N);
    memcpy(ha[0][1].c, c[0], sizeof(char) * N); reverse(ha[0][1].c + 1, ha[0][1].c + n + 1);
    memcpy(ha[1][0].c, c[1], sizeof(char) * N);
    memcpy(ha[1][1].c, c[1], sizeof(char) * N); reverse(ha[1][1].c + 1, ha[1][1].c + n + 1);
    ha[0][0].ini(n, 0); ha[0][1].ini(n, 1); ha[1][0].ini(n, 0); ha[1][1].ini(n, 1);
    solve(); reverse(t + 1, t + m + 1); solve();
    print(ans, '\n');
    return 0;
}