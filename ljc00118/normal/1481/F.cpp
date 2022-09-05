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

const int N = 1e5 + 5;

vector <int> adj[N], id[N];
pii pre[N];
int dep[N], cnt[N], cc[N], dp[N], las[N], ans[N];
int n, m, mx;

void dfs1(int u) {
    ++cnt[dep[u]]; mx = max(mx, dep[u]);
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        dep[v] = dep[u] + 1; dfs1(v);
    }
}

int main() {
    read(n); read(m);
    for (int i = 2; i <= n; i++) {
        int fa; read(fa);
        adj[fa].push_back(i);
    }
    dep[1] = 1; dfs1(1);
    for (int i = 1; i <= mx; i++) ++cc[cnt[i]], id[cnt[i]].push_back(i);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (!cc[i]) continue;
        for (int j = 0; j < i; j++) las[j] = -1;
        for (int j = 0; j <= n; j++) {
            if (dp[j]) {
                las[j % i] = j;
            } else if (las[j % i] != -1 && (j - las[j % i]) / i <= cc[i]) {
                dp[j] = 1;
                pre[j] = make_pair(las[j % i], i);
            }
        }
    }
    if (dp[m]) {
        print(mx, '\n');
        while (m) {
            int cnt = (m - pre[m].first) / pre[m].second;
            for (int j = 0; j < cnt; j++) ans[id[pre[m].second][j]] = 1;
            m = pre[m].first;
        }
        for (int i = 1; i <= n; i++) {
            if (ans[dep[i]]) putchar('a');
            else putchar('b');
        }
        putchar('\n');
    } else {
        print(mx + 1, '\n');
        int las = 0;
        for (int i = 1; i <= mx; i++) {
            if (m >= cnt[i]) {
                m -= cnt[i];
                ans[i] = 1;
            } else las = i;
        }
        for (int i = 1; i <= n; i++) {
            if (dep[i] != las || adj[i].size() || !m) {
                if (ans[dep[i]]) putchar('a');
                else putchar('b');
            } else {
                putchar('a');
                --m;
            }
        }
        putchar('\n');
    }
    return 0;
}