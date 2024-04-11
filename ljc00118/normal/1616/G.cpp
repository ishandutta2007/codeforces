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

const int N = 150005;

vector <int> go[N], fr[N];
int nxt[N], pre[N], l[N], r[N], f[N][2], g[N][2];
int T, n, m;

int main() {
    read(T);
    while (T--) {
        memset(nxt, 0, sizeof(nxt));
        memset(pre, 0, sizeof(pre));
        read(n); read(m); n += 2;
        for (int i = 1; i <= n; i++) go[i].clear(), fr[i].clear();
        for (int i = 1; i <= m; i++) {
            int u, v;
            read(u); read(v); ++u; ++v;
            if (u + 1 == v) nxt[u] = pre[v] = 1;
            go[u].push_back(v);
            fr[v].push_back(u);
        }
        nxt[1] = pre[2] = nxt[n - 1] = pre[n] = 1;
        for (int i = 2; i <= n - 1; i++) {
            go[1].push_back(i); fr[i].push_back(1);
            go[i].push_back(n); fr[n].push_back(i);
        }
        for (int i = 1; i <= n; i++) {
            l[i] = i;
            if (pre[i]) l[i] = l[i - 1];
        }
        for (int i = n; i >= 1; i--) {
            r[i] = i;
            if (nxt[i]) r[i] = r[i + 1];
        }
        if (r[1] == n) {
            print(1ll * (n - 3) * (n - 2) / 2, '\n');
            continue;
        }
        int pos = 0;
        for (int i = 1; i <= n; i++) {
            if (!nxt[i]) {
                pos = i;
                break;
            }
        }
        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));
        f[pos + 1][1] = 1;
        for (int i = pos + 1; i >= 1; i--) {
            for (int j = 0; j <= 1; j++) {
                if (!f[i][j]) continue;
                for (auto v : fr[i]) {
                    if (v != i - 1 && l[i - 1] <= v + 1) f[v + 1][j ^ 1] = 1;
                }
            }
        }
        g[pos][0] = 1;
        for (int i = pos; i <= n; i++) {
            for (int j = 0; j <= 1; j++) {
                if (!g[i][j]) continue;
                for (auto v : go[i]) {
                    if (v != i + 1 && r[i + 1] >= v - 1) g[v - 1][j ^ 1] = 1;
                }
            }
        }
        int cf[3] = {0, 0, 0}, cg[3] = {0, 0, 0};
        for (int i = 2; i <= pos + 1; i++) {
            if (l[i - 1] != 1) continue;
            if (f[i][0]) ++cf[0];
            if (f[i][1]) ++cf[1];
            if (f[i][0] && f[i][1]) ++cf[2];
        }
        for (int i = pos; i <= n - 1; i++) {
            if (r[i + 1] != n) continue;
            if (g[i][0]) ++cg[0];
            if (g[i][1]) ++cg[1];
            if (g[i][0] && g[i][1]) ++cg[2];
        }
        ll ans = 1ll * cf[0] * cg[1] + 1ll * cf[1] * cg[0] - 1ll * cf[2] * cg[2];
        if (l[pos] == 1 && r[pos + 1] == n) --ans;
        print(ans, '\n');
    }
    return 0;
}