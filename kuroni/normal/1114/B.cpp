#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 200005;

int n, m, k, cnt = 0, a[N], ind[N];
bool chk[N];
long long ans = 0;

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        ans += a[i];
        ind[i] = i;
    }
    sort(ind + 1, ind + n + 1, [](const int &x, const int &y) {
        return a[x] < a[y];
    });
    for (int i = 1; i <= n - m * k; i++)
    {
        ans -= a[ind[i]];
        chk[ind[i]] = true;
    }
    printf("%lld\n", ans);
    for (int i = 1; i <= n; i++)
        if ((cnt += (!chk[i])) > m)
        {
            printf("%d ", i - 1);
            cnt = 1;
        }
}