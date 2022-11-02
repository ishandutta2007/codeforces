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
} *first[100001], a[200001];

int U, n, m, l, d[200001], c[1000001][2], cnt, father[100001];

inline void makelist(int x, int y) {
    a[++l].where = y;
    a[l].next = first[x];
    first[x] = &a[l];
}

inline void soso(int cur, int y) {
    c[++cnt][0] = cur; c[cnt][1] = y; int z = y;
    for (node *x = first[cur]; x; x = x->next)
        if (father[cur] != x->where && x->where != 1) {
            father[x->where] = cur;
            --d[x->where]; --d[cur];
            if (y != U) {
                soso(x->where, y + 1);
                c[++cnt][0] = cur;
                c[cnt][1] = ++y;
            } else {
                y = z - 1 - (d[cur] + 1);
                c[++cnt][0] = cur;
                c[cnt][1] = y;
                soso(x->where, y + 1);
                c[++cnt][0] = cur;
                c[cnt][1] = ++y;
            }
        }
    if (z && y != z - 1)
        c[++cnt][0] = cur, c[cnt][1] = z - 1;
        
}
            
int main() {
    scanf("%d", &n);
    memset(first, 0, sizeof(first)); l = 0;
    for (int i = 1; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        makelist(x, y);
        makelist(y, x);
        ++d[x];
        ++d[y];
    }
    U = 0;
    for (int i = 1; i <= n; i++)
        U = max(U, d[i]);
    soso(1, 0);
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; i++)
        printf("%d %d\n", c[i][0], c[i][1]);
}