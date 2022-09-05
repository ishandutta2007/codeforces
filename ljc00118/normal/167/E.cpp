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

const int N = 605;

vector <int> adj[N];
queue <int> q;
int in[N], a[N][N], id[N], seq[N], f[N];
int n, m, md, len, tot;

inline int add(int x, int y) {
    x += y;
    if (x >= md) x -= md;
    return x;
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

int det(int n) {
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        int pos = 0;
        for (int j = i; j <= n; j++) {
            if (a[j][i]) {
                pos = j;
                break;
            }
        }
        if (!pos) return 0;
        if (pos != i) {
            for (int k = 1; k <= n; k++) swap(a[i][k], a[pos][k]);
            ans = md - ans;
        }
        int inv = fpow(a[i][i], md - 2);
        for (int j = i + 1; j <= n; j++) {
            int tmp = mul(a[j][i], inv);
            for (int k = i; k <= n; k++) a[j][k] = sub(a[j][k], mul(a[i][k], tmp));
        }
    }
    for (int i = 1; i <= n; i++) ans = mul(ans, a[i][i]);
    return ans;
}

int main() {
    read(n); read(m); read(md);
    for (int i = 1; i <= m; i++) {
        int u, v;
        read(u); read(v);
        adj[u].push_back(v); ++in[v];
    }
    for (int i = 1; i <= n; i++) {
        if (!in[i]) {
            id[i] = ++tot;
            q.push(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        int u = q.front(); q.pop(); seq[i] = u;
        for (int j = 0; j < (int)adj[u].size(); j++) {
            int v = adj[u][j];
            --in[v];
            if (!in[v]) q.push(v);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (id[i]) {
            tot = 0;
            memset(f, 0, sizeof(f));
            f[i] = 1;
            for (int j = 1; j <= n; j++) {
                int u = seq[j];
                for (int k = 0; k < (int)adj[u].size(); k++) {
                    int v = adj[u][k];
                    f[v] = add(f[v], f[u]);
                }
            }
            for (int j = 1; j <= n; j++) {
                if (adj[j].size() == 0) {
                    ++tot;
                    a[id[i]][tot] = f[j];
                }
            }
        }
    }
    // for (int i = 1; i <= tot; i++) {
    //     for (int j = 1; j <= tot; j++) {
    //         printf("%d%c", a[i][j], j == tot ? '\n' : ' ');
    //     }
    // }
    printf("%d\n", det(tot));
    return 0;
}