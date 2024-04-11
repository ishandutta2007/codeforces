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
} *first[100001], a[1000001];
int n, l, w[100001], c[100001];
const int p = 1000000007;
long long f[100001][2], g[2];

inline void makelist(int x, int y){
    a[++l].where = y;
    a[l].next = first[x];
    first[x] = &a[l];
}

int main(){
    //freopen("a.in", "r", stdin);
    scanf("%d", &n);
    memset(first, 0, sizeof(first));
    l = 0;
    for (int i = 2; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        ++x;
        makelist(x, i);
    }
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
    memset(f, 0, sizeof(f));
    for (int i = n; i; --i)
    {
        if (w[i]) 
        {
            f[i][0] = 0;
            f[i][1] = 1;
            for (node *x = first[i]; x; x = x->next)
                f[i][1] *= (f[x->where][0] + f[x->where][1]) % p,
                f[i][1] %= p;
        }
        else 
        {
            f[i][0] = 1; g[0] = 1; g[1] = 0;
            for (node *x = first[i]; x; x = x->next)
            {
                f[i][0] *= (f[x->where][0] + f[x->where][1]) % p,
                f[i][0] %= p;
                g[1] = g[0] * f[x->where][1] % p + g[1] * (f[x->where][0] + f[x->where][1]) % p; g[1] %= p;
                g[0] *= (f[x->where][0] + f[x->where][1]); g[0] %= p;
            }
            f[i][1] = g[1];
        }
        //printf("%d %I64d %I64d\n", i, f[i][0], f[i][1]);
    }
    cout << f[1][1] << endl;
}