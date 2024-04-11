#include <iostream>
using namespace std;

long long q[505][505], a[505][505];
long long x[505];

long long ans[505];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%I64d", &q[i][j] );
    for (int i = 0; i < n; i++)
	{
        scanf("%I64d", &x[n - i - 1] );
        x[n - i - 1] --;
	}
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j]  = q[x[i] ][x[j] ];

    for (int k = 0; k < n; k++)
	{
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                a[i][j] = min(a[i][j], a[i][k] + a[k][j] );
        long long cur = 0;
        for (int i = 0; i <= k; i++)
            for (int j = 0; j <= k; j++)
                cur += a[i][j];
        ans[k] = cur;
	}
    for (int i = n - 1; i >= 0; i--)
        printf("%I64d ", ans[i] );



    return 0;
}