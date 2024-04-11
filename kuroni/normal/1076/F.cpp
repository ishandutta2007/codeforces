#include <iostream>
#include <cstdio>
using namespace std;

const int N = 300005;

int n, k, a[N][2];
long long f[N][2];

int main()
{
    scanf("%d%d", &n, &k);
    for (int j = 0; j < 2; j++)
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i][j]);
    for (int j = 0; j < 2; j++)
        for (int i = 1; i <= n; i++)
            if ((f[i][j] = max(0LL, f[i - 1][j] + a[i][j] - 1LL * k * a[i][j ^ 1])) > k)
                return !printf("NO\n");
    printf("YES\n");
}