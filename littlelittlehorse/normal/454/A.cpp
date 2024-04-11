#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, a[201][201];

int main(){
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n / 2 + 1; i++)
        for (int j = 1, k = n, l = 1; l <= (n - 2 * i + 1) / 2; j++, k--, l++)
            a[i][j] = a[i][k] = a[n - i + 1][j] = a[n - i + 1][k] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            if (a[i][j]) printf("*");
            else printf("D");
        printf("\n");
    }
}