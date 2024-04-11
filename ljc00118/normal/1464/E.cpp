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

const int N = 1e5 + 5, md = 998244353;

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

queue <int> q;
vector <int> adj[N], radj[N];
int sg[N], tax[N], in[N], a[1 << 18];
int n, m, ans;

void fwt(int *a, int base) {
    int n = 1 << base;
    for (int mid = 1; mid < n; mid <<= 1) {
        for (int i = 0; i < n; i += (mid << 1)) {
            for (int j = 0; j < mid; j++) {
                int x = a[i + j], y = a[i + j + mid];
                a[i + j] = add(x, y); a[i + j + mid] = sub(x, y);
            }
        }
    }
}

int main() {
    read(n); read(m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        read(u); read(v);
        adj[u].push_back(v);
        radj[v].push_back(u); ++in[u];
    }
    for (int i = 1; i <= n; i++) {
        if (!in[i]) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < (int)adj[u].size(); i++) {
            int v = adj[u][i];
            tax[sg[v]] = 1;
        }
        while (tax[sg[u]]) ++sg[u];
        for (int i = 0; i < (int)adj[u].size(); i++) {
            int v = adj[u][i];
            tax[sg[v]] = 0;
        }
        for (int i = 0; i < (int)radj[u].size(); i++) {
            int v = radj[u][i];
            --in[v];
            if (!in[v]) q.push(v);
        }
    }
    for (int i = 1; i <= n; i++) a[sg[i]] = add(a[sg[i]], fpow(n, md - 2));
    fwt(a, 18);
    for (int i = 0; i < (1 << 18); i++) {
        int x = mul(mul(n, fpow(n + 1, md - 2)), a[i]);
        ans = add(ans, fpow(sub(1, x), md - 2));
    }
    ans = mul(ans, mul(fpow(n + 1, md - 2), fpow(1 << 18, md - 2)));
    print(sub(1, ans), '\n');
    return 0;
}