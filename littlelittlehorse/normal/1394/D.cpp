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
} *first[200001], a[400001];
int n, t[200001], h[200001], l, dist[200001], c[200001], fa[200001];
long long f[200001][2], g[200001], v[200001];

inline void makelist(int x, int y) {
    a[++l].where = y;
    a[l].next = first[x];
    first[x] = &a[l];
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &t[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &h[i]);
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
                fa[x->where] = m,
                c[++k] = x->where;
    }
    memset(f, 127, sizeof(f));
    for (int i = n; i; --i) {
        int m = c[i];
        int B = 0, S = 0, E = 0;
        long long res = 0;
        for (node *x = first[m]; x; x = x->next)
            if (dist[x->where] == dist[m] + 1) {
                if (h[x->where] > h[m])
                    ++B, res += f[x->where][0];
                else
                if (h[x->where] < h[m])
                    ++S, res += f[x->where][1];
                else
                    res += f[x->where][0],
                    g[++E] = f[x->where][1] - f[x->where][0];
            }
        sort(g + 1, g + E + 1);
        for (int j = 1; j <= E; j++)
            v[j] = g[j],
            g[j] += g[j - 1];
        for (int j = B; j <= B + E; j++) {
            long long tmp = res;
            tmp += g[E - (j - B)];
            tmp += 1LL * max(j, B + E + S - j) * t[m];
            if (m == 1)
                f[m][0] = min(f[m][0], tmp);
            else { 
                if (h[m] >= h[fa[m]])
                    if (j > B + E + S - j)
                        f[m][0] = min(f[m][0], tmp);
                    else
                        f[m][0] = min(f[m][0], tmp + t[m]);
                if (h[m] <= h[fa[m]]) {
                    if (j < B + E + S - j)
                        f[m][1] = min(f[m][1], tmp);
                    else
                        f[m][1] = min(f[m][1], tmp + t[m]);
                }
            }
        }
        
    }
    printf("%lld\n", f[1][0]);
}