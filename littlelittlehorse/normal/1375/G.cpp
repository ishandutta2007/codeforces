#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int test, n, m, size[200001], dist[200001], c[200001], l;
long long f[200001], g[200001], ff[200001], gg[200001];
bool b[1001];

struct node {
    node *next;
    int where;
} *first[200001], a[400001];

inline void makelist(int x, int y) {
    a[++l].where = y;
    a[l].next = first[x];
    first[x] = &a[l];
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        makelist(x, y);
        makelist(y, x);
    }
    c[1] = 1; dist[1] = 1;
    for (int k = 1, l = 1; l <= k; l++) {
        int m = c[l]; 
        for (node *x = first[m]; x; x = x->next)
            if (!dist[x->where])
                dist[x->where] = dist[m] + 1,
                c[++k] = x->where;
    }
    for (int i = n; i; --i) {
        int m = c[i]; size[m] = 1;
        f[m] = 0; g[m] = 0;
        for (node *x = first[m]; x; x = x->next)
            if (dist[x->where] == dist[m] + 1) {
                size[m] += size[x->where];
                f[m] += min(f[x->where] + size[x->where] - 1, g[x->where]);
                g[m] += f[x->where] + 1;
            }
        //printf("%d %lld %lld\n", m, f[m], g[m]);
    }
    
    long long ans = 1LL << 62LL;
    for (int i = 1; i <= n; i++) {
        int m = c[i];
        long long fff = f[m] + min(ff[m] + n - size[m] - 1, gg[m]);
        long long ggg = g[m] + ff[m] + 1;
        if (m == 1)
            ++fff, --ggg;
        ans = min(ans, fff);
        for (node *x = first[m]; x; x = x->next)
            if (dist[x->where] == dist[m] + 1) {
                ff[x->where] = fff - min(f[x->where] + size[x->where] - 1, g[x->where]);
                gg[x->where] = ggg - f[x->where] - 1;
            }
        //printf("%d %lld %lld %lld %lld\n", m, ff[m], gg[m], fff, ggg);
    }
    printf("%lld\n", ans);
}