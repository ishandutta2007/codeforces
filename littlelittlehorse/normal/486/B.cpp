#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, a[101][101], v[101][101], r[101], l[101];
bool row[101], line[101];

int main(){
    //freopen("b.in", "r", stdin);
    scanf("%d%d", &n, &m);
    memset(row, false, sizeof(row));
    memset(line, false, sizeof(line));  
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) 
        {
            v[i][j] = 1;
            scanf("%d", &a[i][j]);
            if (!a[i][j]) row[i] = true, line[j] = true;
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (row[i] || line[j]) v[i][j] = 0;
    for (int i = 1; i <= n; i++)
    {
        r[i] = 0;
        for (int j = 1; j <= m; j++) r[i] |= v[i][j];
    }
    for (int j = 1; j <= m; j++)
    {
        l[j] = 0;
        for (int i = 1; i <= n; i++) l[j] |= v[i][j];
    }
    bool ok = true;
    for (int i = 1; i <= n && ok; i++)
        for (int j = 1; j <= m && ok; j++)
            if (a[i][j] != (r[i] | l[j])) ok = false;
    if (!ok) printf("NO\n");
    else
    {
        printf("YES\n");
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                printf("%d", v[i][j]);
                if (j != m) printf(" ");
            }
            printf("\n");
        }
    }
}