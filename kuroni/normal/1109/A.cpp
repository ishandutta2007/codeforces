#include <iostream>
#include <cstdio>
using namespace std;

const int MX = 1 << 20;

int n, u, cur = 0, f[MX][2];
long long ans = 0;

int main()
{
    f[0][0] = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &u);
        cur ^= u;
        ans += f[cur][i & 1];
        f[cur][i & 1]++;
    }
    printf("%lld", ans);
}