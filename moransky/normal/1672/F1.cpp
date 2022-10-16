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

int n, a[N], c[N], d[N], t, b[N];

vector<int> p[N];

bool inline cmp1(int x, int y) {
    return c[x] < c[y];
}

void inline wk() {
    t = 0;
    for (int i = 1; i <= n; i++)
        if (c[i]) d[++t] = i;
    sort(d + 1, d + 1 + t, cmp1);
    for (int i = 1; i < t; i++) {
        int u = d[i], v = d[i + 1];
        int o = c[u];
        while (o--) {
            b[p[v].back()] = u;
            p[v].pop_back();
        }
    }
    for (int i = 1; i <= t; i++) {
        int u = d[i];
        while (p[u].size()) {
            b[p[u].back()] = d[t];
            p[u].pop_back();
        }
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", b[i]);
    puts("");
}

int main() {
    int T; read(T);
    while (T--) {
    	read(n);
        for (int i = 1; i <= n; i++) read(a[i]), p[a[i]].pb(i), c[a[i]]++;
        wk();
        for (int i = 1; i <= n; i++) p[i].clear(), c[a[i]] = 0;
    }
    return 0;
}