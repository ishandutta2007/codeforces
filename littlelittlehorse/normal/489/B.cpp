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
} *first[101], a[100001];
int n, e[101], ans, m, r[101], l, v[101];
bool b[101];

inline void makelist(int x, int y){
    a[++l].where = y; a[l].next = first[x]; first[x] = &a[l];
}

bool work(int now){
    b[now] = true;
    for (node *x = first[now]; x; x = x->next)
        if (!v[x->where] || (!b[v[x->where]] && work(v[x->where])))
        {
            v[x->where] = now;
            return true;
        }
    return false;
}

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &e[i]);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) scanf("%d", &r[i]);
    memset(first, 0, sizeof(first)); l = 0;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++)
            if (abs(e[i] - r[j]) <= 1) makelist(i, j);
    memset(v, 0, sizeof(v)); ans = 0;
    for (int i = 1; i <= n; i++)
    {
        memset(b, false, sizeof(b));
        if (work(i)) ++ans;
    }
    printf("%d\n", ans);
}