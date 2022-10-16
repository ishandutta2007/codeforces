// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 2e5 + 5;

int n, m, a[N], b[N], L[N], R[N], f[N], d[N];

LL sa[N], sb[N];

vector<int> e[N];

int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}

bool vis[N];

void link(int x) {
    if (vis[x]) return;
    vis[x] = 1;
    f[x] = x + 1;
    for (int i: e[x]) {
        if (--d[i] == 0) {
            int p = find(L[i]);
            while (p <= R[i]) {
                link(p);
                p = find(p);
            }
        }
    }
}

bool inline chk() {
    for (int i = 0; i <= n + 1; i++) f[i] = i;
    for (int i = 0; i <= n; i++) {
        if (sa[i] == sb[i]) link(i);
    }
    for (int i = 0; i <= n; i++) vis[i] = 0;
    return find(0) == find(n + 1);
}

int main() {
    int T; read(T);
    while (T--) {
        read(n), read(m);
        for (int i = 1; i <= n; i++) read(a[i]), sa[i] = sa[i - 1] + a[i];
        for (int i = 1; i <= n; i++) read(b[i]), sb[i] = sb[i - 1] + b[i];
        for (int i = 1; i <= m; i++) read(L[i]), read(R[i]), --L[i], d[i] = 2, e[L[i]].pb(i), e[R[i]].pb(i);
        puts(chk() ? "YES" : "NO");
        for (int i = 0; i <= n; i++) e[i].clear();
    }
    return 0;
}