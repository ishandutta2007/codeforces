#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

const int p = 1000000007;

struct node{
    int where;
    node *next;
} *first[2001], a[10001];

struct point{
    int value, pos;
    bool operator < (const point &A) const{
        return value < A.value;
    }
} v[2001];

int ans, limit, r[2001], n, m, l, dist[2001], c[2001];
long long f[2001];

inline void makelist(int x, int y){
    a[++l].where = y; a[l].next = first[x]; first[x] = &a[l];
}

int main(){
    //freopen("d.in", "r", stdin);
    scanf("%d%d", &limit, &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &v[i].value), v[i].pos = i;
    sort(v + 1, v + n + 1);
    for (int i = 1; i <= n; i++)
        r[v[i].pos] = i;
    memset(first, 0, sizeof(first)); l = 0;
    for (int i = 1; i < n; i++)
    {
        int x, y; scanf("%d%d", &x, &y);
        makelist(x, y); makelist(y, x);
    }
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        memset(dist, 0, sizeof(dist));
        dist[v[i].pos] = 1; c[1] = v[i].pos; int k = 1;
        for (int l = 1; l <= k; l++)
        {
            int m = c[l]; 
            for (node *x = first[m]; x; x = x->next)
            {
                if (!dist[x->where] && r[x->where] > i && v[r[x->where]].value - v[i].value <= limit)
                    dist[x->where] = dist[m] + 1, c[++k] = x->where;
            }
        }
        for (int j = k; j; --j)
        {
            int m = c[j];
            f[m] = 1;
            for (node *x = first[m]; x; x = x->next)
                if (dist[x->where] == dist[m] + 1) f[m] *= f[x->where] + 1, f[m] %= p;
        }
        ans += f[v[i].pos]; ans %= p;
    }
    printf("%d\n", ans);
}