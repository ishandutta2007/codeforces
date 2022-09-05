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

const int N = 1e6 + 5;

struct atom {
    int u, v, d;
    atom (int a = 0, int b = 0, int c = 0) : u(a), v(b), d(c) {}
} t[N];

vector <int> adj[N], vec[N];
queue <int> qq;
int tops[N], lg[N * 2], st[N * 2][21], dis[N], dep[N];
int n, q, len, maxn;

void dfs1(int u, int fa) {
    tops[u] = ++len; st[len][0] = dep[u];
    for (auto v : adj[u]) {
        if (v == fa) continue;
        dep[v] = dep[u] + 1; dfs1(v, u);
        ++len; st[len][0] = dep[u];
    }
}

int query(int l, int r) {
    if (l > r) swap(l, r);
    int k = lg[r - l + 1];
    return min(st[l][k], st[r - (1 << k) + 1][k]);
}

int getdis(int u, int v) {
    return dep[u] + dep[v] - 2 * query(tops[u], tops[v]);
}

int main() {
    memset(dis, -1, sizeof(dis));
    read(n);
    for (int i = 2; i <= n; i++) {
        int fa; read(fa);
        adj[fa].push_back(i);
        adj[i].push_back(fa);
    }
    for (int i = 1; i <= n; i++) {
        if ((int)adj[i].size() == 1) {
            dis[i] = 0; qq.push(i);
        }
    }
    while (!qq.empty()) {
        int u = qq.front(); qq.pop();
        for (auto v : adj[u]) {
            if (dis[v] == -1) {
                dis[v] = dis[u] + 1;
                qq.push(v);
            }
        }
    }
    for (int i = 1; i <= n; i++) vec[dis[i]].push_back(i), maxn = max(maxn, dis[i]);
    dfs1(1, 0);
    for (int j = 1; j <= 20; j++) {
        for (int i = 1; i <= len - (1 << j) + 1; i++) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    lg[0] = -1;
    for (int i = 1; i <= len; i++) lg[i] = lg[i >> 1] + 1;
    t[maxn].u = t[maxn].v = vec[maxn][0]; t[maxn].d = 0;
    for (int i = maxn; i >= 0; i--) {
        if (i != maxn) t[i] = t[i + 1];
        for (auto j : vec[i]) {
            int d1 = getdis(t[i].u, j);
            int d2 = getdis(t[i].v, j);
            if (d1 > d2) {
                if (d1 > t[i].d) {
                    t[i].d = d1; t[i].v = j;
                }
            } else {
                if (d2 > t[i].d) {
                    t[i].d = d2; t[i].u = j;
                }
            }
        }
    }
    read(q);
    for (int i = 1; i <= q; i++) {
        int x;
        read(x);
        int ans = 0;
        for (int j = maxn; j >= 0; j--) {
            while (1) {
                int pos = max(0, ans + 1 - x - j);
                if (pos <= maxn && max(max(getdis(t[j].u, t[pos].u), getdis(t[j].u, t[pos].v)), max(getdis(t[j].v, t[pos].u), getdis(t[j].v, t[pos].v))) >= ans + 1) {
                    ++ans;
                } else {
                    break;
                }
            }
        }
        print(ans, i == q ? '\n' : ' ');
    }
    return 0;
}