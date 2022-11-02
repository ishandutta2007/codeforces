#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

struct node{
       node *next;
       int where;
} *first[100001];
int n, a[100001], c[100001], dist[100001], 
f[100001][2], aim[100001], father[100001], w[100001];

inline void makelist(int x, int y){
       node *now = new node;
       now->where = y;
       now->next = first[x];
       first[x] = now;
}

int main(){
  //  freopen("a.in", "r", stdin);
  //  freopen("a.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        makelist(x, y);
        makelist(y, x);
    }
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &aim[i]);
    memset(dist, 0, sizeof(dist));
    memset(father, 0, sizeof(father));
    dist[1] = 1; c[1] = 1;
    for (int k = 1, l = 1; l <= k; l++)
    {
        int m = c[l];
        for (node *x = first[m]; x; x = x->next)
            if (!dist[x->where]) dist[x->where] = dist[m] + 1, c[++k] = x->where, 
            father[x->where] = m;
    }
    memset(f, 0, sizeof(f));
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int m = c[i];
        f[m][0] = f[father[m]][1];
        f[m][1] = f[father[m]][0];
        if (f[m][0] ^ a[m] != aim[m])
           w[++ans] = m, f[m][0] ^= 1;
    }
    printf("%d\n", ans);
    for (int i = 1; i <= ans; i++) printf("%d\n", w[i]);
}