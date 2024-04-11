#include <cstdio>
using namespace std;

const int mod = 1e9 + 7;
int i, p, n, f[1005], sum[1005];

int main()
{
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &p);
        f[i] = ((sum[i - 1] - sum[p - 1] + 2) % mod + mod) % mod;
        sum[i] = (sum[i - 1] + f[i]) % mod;
    }
    printf("%d", sum[n]);
}