#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

struct node {
    node *next;
    int where;
} *first[100001], a[200001];
int n, x, y, l, test, dist[100001], c[100001], ff[100001], f1[100001], fff[100001], father[100001], f[100001], v[100001], g[100001], xx[100001];
bool b[100001], en[100001], mo[100001];

inline void makelist(int x, int y) {
    a[++l].where = y;
    a[l].next = first[x];
    first[x] = &a[l];
}

int main() {
    scanf("%d", &test);
    for (; test--; ) {
        scanf("%d%d%d", &n, &x, &y);
        //printf("%d\n", n);
        memset(first, 0, sizeof(first));
        l = 0;
        for (int i = 1; i < n; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            makelist(x, y);
            makelist(y, x);
        }
        memset(father, 0, sizeof(father));
        memset(dist, 0, sizeof(dist));
        dist[x] = 1; c[1] = x;
        for (int k = 1, l = 1; l <= k; l++) {
            int m = c[l];
            for (node *x = first[m]; x; x = x->next)
                if (!dist[x->where])
                    dist[x->where] = dist[m] + 1,
                    father[x->where] = m,
                    c[++k] = x->where;
        }
        int len = 0;
        memset(b, false, sizeof(b));
        for (int i = y; i != x; i = father[i])
            ++len, b[i] = true, v[len] = i;
        v[++len] = x;
        b[x] = true;
        for (int i = n; i; --i) {
            int m = c[i]; fff[m] = 0;
            for (node *x = first[m]; x; x = x->next)
                if (dist[x->where] == dist[m] + 1)
                    fff[m] = max(fff[m], fff[x->where]);
            fff[m]++;
            
            f[m] = 0;
            for (node *x = first[m]; x; x = x->next)
                if (dist[x->where] == dist[m] + 1 && !b[x->where])
                    f[m] = max(f[m], f[x->where]);
            ++f[m];
        }
        
        memset(ff, 0, sizeof(ff));
        memset(f1, 0, sizeof(f1));
        for (int i = 1; i <= n; i++) {
            int m = c[i];
            
            int m1 = ff[m], m2 = 0;
            for (node *x = first[m]; x; x = x->next)
                if (dist[x->where] == dist[m] + 1) {
                    if (fff[x->where] > m1)
                        m2 = m1, m1 = fff[x->where];
                    else
                        m2 = max(m2, fff[x->where]);
                }
            for (node *x = first[m]; x; x = x->next)
                if (dist[x->where] == dist[m] + 1) {
                    if (fff[x->where] == m1)
                        ff[x->where] = m2 + 1;
                    else
                        ff[x->where] = m1 + 1;
                }
           //if (!b[father[m]])
            f1[m] = max(ff[m] + 1, f[m]);
           //else
           // f1[m] = f[m];
        }
        
        //for (int i = 1; i <= n; i++)
        //    printf("%d %d\n", i, fff[i]);
        
        memset(en, 0, sizeof(en));
       // printf("%d\n", len);
        for (int i = 1; i <= n; i++) {
            int cnt = 0, m = i;
            if (ff[m] >= len - 1)
                ++cnt;
            for (node *x = first[m]; x; x = x->next)
                if (dist[x->where] == dist[m] + 1 && fff[x->where] >= len - 1)
                    ++cnt;
            if (cnt >= 3)
                en[m] = true;
           // printf("%d %d %d %d\n", m, fff[m], cnt, en[m]);
        }
        
        for (int i = n; i; --i) {
            int m = c[i]; 
            for (node *x = first[m]; x; x = x->next)
                if (dist[x->where] == dist[m] + 1 && !b[x->where])
                    if (en[x->where])
                        en[m] = true;
        }
        
        for (int i = 1, j = len; i < j; i++, j--)
            swap(v[i], v[j]);
        
        xx[0] = 0;
        for (int i = len; i; i--) {
            int m = v[i];
            xx[len - i + 1] = max(xx[len - i], f[m] + i);
        }
        
        /*for (int i = 1; i <= n; i++)
           printf("%d %d\n", i, en[i]);
        
        for (int i = 1; i <= len; i++)
            printf("%d ", xx[i]);
        printf("\n");*/
        
        memset(g, 0, sizeof(g));
        g[1] = min(len, f[x]);
        //printf("%d\n", g[1]);
        if (en[x]) {
            printf("YES\n");
            continue;
        }
        bool ok = false;
        for (int i = 2; i <= len; i++) {
            if (xx[g[i - 1]] - len >= i || g[i - 1] + i - 1 >= len) {
                g[i] = g[i - 1];
                g[i] = max(g[i], min(len, f1[v[i]] - i + 1));
                //printf("alive %d %d %d\n", i, v[i], g[i]);
                if (en[v[i]]) {
                    printf("YES\n");
                    ok = true;
                    break;
                }
            } else
                break;
        }
        if (!ok) {
            printf("NO\n");
        }
    }
}