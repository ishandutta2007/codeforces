#include <iostream>
#include <cstdio>
using namespace std;

int a[100005], n, k;

void solve(int L, int R, int l, int r, int k)
{
    if (k == 1)
    {
        for (int i = l; i <= r; i++)
            a[i] = L - l + i;
        return;
    }
    solve((L + R) / 2 + 1, R, l, (l + r - 1) / 2, k / 2 - (k % 4 == 1));
    solve(L, (L + R) / 2, (l + r - 1) / 2 + 1, r, k / 2 + (k % 4 == 1));
}

int main()
{
    scanf("%d%d", &n, &k);
    if (k % 2 == 0 || k >= 2 * n)
    {
        printf("-1");
        return 0;
    }
    solve(1, n, 1, n, k);
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
}