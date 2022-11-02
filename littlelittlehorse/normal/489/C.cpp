#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, a[101];

int main(){
    scanf("%d%d", &n, &m);
    if (n == 1 && !m)
    {
        printf("0 0\n");
        return 0;
    }
    int Min = 1, Max = n * 9;
    if (m < Min || m > Max) 
    {
        printf("-1 -1\n");
        return 0;
    }
    memset(a, 0, sizeof(a));
    if (m >= (n - 1) * 9 + 1)
    {
        for (int i = 2; i <= n; i++) a[i] = 9;
        a[1] = m - (n - 1) * 9;
    }
    else
    {
        a[1] = 1;
        for (int i = n, j = m - 1; j > 0; j -= 9, --i)
            a[i] = min(j, 9);
    }
    for (int i = 1; i <= n; i++) printf("%d", a[i]); printf(" ");
    memset(a, 0, sizeof(a));
    for (int i = 1, j = m; j > 0; j -= 9, ++i)
        a[i] = min(j, 9);
    for (int i = 1; i <= n; i++) printf("%d", a[i]);
    printf("\n");
}