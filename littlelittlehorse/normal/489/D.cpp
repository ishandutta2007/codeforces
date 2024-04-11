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
} *first[3001], a[30001];
int n, m, l;
bool b[3001][3001];

inline void makelist(int x, int y){
    a[++l].where = y; a[l].next = first[x]; first[x] = &a[l];
}

int main(){
    scanf("%d%d", &n, &m);
    memset(b, false, sizeof(b));
    memset(first, 0, sizeof(first)); l = 0;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        makelist(x, y); b[x][y] = true;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j)
            {
                int num = 0;
                for (node *x = first[i]; x; x = x->next)
                    if (x->where != j && b[x->where][j]) ++num;
                ans += num * (num - 1) / 2;
            }
    printf("%I64d\n", ans);
}