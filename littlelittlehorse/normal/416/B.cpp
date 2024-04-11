#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int f[50001], n, m, a[50001][6];

int main(){
    //freopen("b.in", "r", stdin);
    //freopen("b.out", "w", stdout);
    scanf("%d%d", &n, &m);
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            f[j] = max(f[j], f[j - 1]) + a[j][i];
    for (int i = 1; i <= n; i++)
    {
        printf("%d", f[i]);
        if (i != n) printf(" ");
        else printf("\n");
    }
}