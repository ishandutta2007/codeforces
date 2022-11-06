#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, xo, yo, x[N], y[N];
int main()
{
    scanf("%d %d %d", &n, &xo, &yo);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d %d", &x[i], &y[i]);
        x[i] -= xo;
        y[i] -= yo;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans++;
        for(int j = n; j > i; j--)
        {
            if(x[i] * y[j] - x[j] * y[i] == 0)
            {
                swap(x[j], x[n]);
                swap(y[j], y[n]);
                n--;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}