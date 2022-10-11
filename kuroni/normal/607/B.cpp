#include <iostream>
#include <string.h>

using namespace std;

int n, i, j, a[505];
long long count[505][505];

long long find_ans(int l, int r)
{
    if (r <= l)
        return 1;
    if (count[l][r] != 0)
        return count[l][r];
    if (a[l] == a[r])
        count[l][r] = find_ans(l + 1, r - 1);
    else count[l][r] = 2000000000;
    for (int i = l; i < r; i++)
        count[l][r] = min(count[l][r], find_ans(l, i) + find_ans(i + 1, r));
    return count[l][r];
}

int main()
{
    memset(count, 0, sizeof(count));
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d", a + i);
    printf("%lld", find_ans(1, n));
}