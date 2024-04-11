#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

struct node {
    node *next;
    int where;
} *first[200001], a[200001];

int l, n, m, c[200001], v[200001], r[200001], f[200001], g[200001];

inline void makelist(int x, int y) {
    a[++l].where = y;
    a[l].next = first[x];
    first[x] = &a[l];
}

int main() {
    scanf("%d%d", &n, &m);
    memset(first, 0, sizeof(first)); l = 0;
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        makelist(x, y);
        ++v[y]; 
    }
    int k = 0;
    for (int i = 1; i <= n; i++)
        if (!v[i])
            c[++k] = i;
    for (int l = 1; l <= k; l++) {
        int m = c[l];
        for (node *x = first[m]; x; x = x->next)
            if (!--v[x->where])
                c[++k] = x->where;
    }
    if (k != n) {
        printf("-1\n");
        return 0;
    }
    
    for (int i = 1; i <= n; i++)
        f[i] = i, g[i] = i;
    
    for (int i = 1; i <= n; i++) {
        int m = c[i];
        for (node *x = first[m]; x; x = x->next)
            f[x->where] = min(f[x->where], f[m]);
    }
    
    for (int i = n; i; i--) {
        int m = c[i];
        for (node *x = first[m]; x; x = x->next)
            g[m] = min(g[x->where], g[m]);
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (min(f[i], g[i]) == i)
            ++ans;
    
    printf("%d\n", ans);
    for (int i = 1; i <= n; i++)
        if (min(f[i], g[i]) == i)
            printf("A");
        else
            printf("E");
    printf("\n");
}