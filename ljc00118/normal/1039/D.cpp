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

const int N = 1e5 + 5, B = 1000;

vector <int> adj[N], son[N];
int seq[N], f[N], ans[N];
int n, k, ret, len;

void dfs1(int u, int fa) {
    seq[++len] = u;
    for (auto v : adj[u]) {
        if (v == fa) continue;
        dfs1(v, u); son[u].push_back(v);
    }
}

int calc(int x) {
    k = x; ret = 0;
    for (int _ = n; _ >= 1; _--) {
        int u = seq[_];
        int maxn = 0, flag = 0;
        for (auto v : son[u]) {
            if (f[v] + maxn + 1 >= k) flag = 1;
            maxn = max(maxn, f[v]);
        }
        if (flag) ++ret, f[u] = 0;
        else f[u] = maxn + 1;
    }
    return ret;
}

int main() {
    read(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        read(u); read(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1, 0);
    ans[1] = n;
    for (int i = 2; i <= min(n, B); i++) ans[i] = calc(i);
    if (n > B) {
        int now = B + 1;
        for (int i = ans[B]; i >= 1; i--) {
            int l = now, r = n / i, ret = now - 1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (calc(mid) == i) ret = mid, l = mid + 1;
                else r = mid - 1;
            }
            while (now <= ret) {
                ans[now] = i; ++now;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        print(ans[i], '\n');
    }
    return 0;
}