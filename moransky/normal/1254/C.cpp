#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long LL;

const int N = 1e3 + 5;

int n, p[N], len, a[N];

LL h[N];

void inline cl() {
    fflush(stdout);
}

LL inline ask1(int i, int j, int k) {
    printf("1 %d %d %d\n", i, j, k);
    cl();
    LL x; scanf("%lld", &x);
    return x;
}

int inline ask2(int i, int j, int k) {
    printf("2 %d %d %d\n", i, j, k);
    cl();
    int x; scanf("%d", &x);
    return x;
}

bool inline cmp(int x, int y) {
    if (a[x] != a[y]) return a[x] < a[y];
    if (a[x] == -1) {
        return h[x] < h[y];
    }
    if (a[x] == 1) {
        return h[x] > h[y];
    }
}

int main() {
    scanf("%d", &n);
    int t = 2;
    for (int i = 3; i <= n; i++) {
        if (ask2(1, t, i) == -1) t = i;
    }
    p[1] = 1;
    p[2] = t;
    len = 2;
    LL v = -1e9; int u;
    for (int i = 2; i <= n; i++) {
        if (i == t) continue;
        p[++len] = i;
        h[i] = ask1(1, t, i);
        if (h[i] > v) v = h[i], u = i;
    }
    for (int i = 2; i <= n; i++) {
        if (i == t || i == u) continue;
        a[i] = ask2(1, u, i);
    }
    sort(p + 3, p + 1 + n, cmp);
    printf("0");
    for (int i = 1; i <= n; i++) printf(" %d", p[i]);
    cl();
    return 0;
}