#include <iostream>
#include <cstdio>
using namespace std;

const int N = 500005;

int n, r, a[N];
long long k, add[N];

bool chk_ans(long long val)
{
    fill(add, add + N, 0);
    long long cur = 0, ans = k;
    for (int i = 1; i <= r; i++)
        cur += a[i];
    for (int i = 1; i <= n; i++)
    {
        cur += a[min(n + 1, i + r)];
        cur -= add[max(0, i - r - 1)] + a[max(0, i - r - 1)];
        add[min(n, i + r)] += max(0LL, val - cur);
        ans -= max(0LL, val - cur);
        cur += max(0LL, val - cur);
        if (ans < 0)
            return false;
    }
    return true;
}

long long find_ans()
{
    long long l = 0, r = 2E18, m;
    while (l <= r)
    {
        m = (l + r) >> 1;
        if (chk_ans(m))
            l = m + 1;
        else
            r = m - 1;
    }
    return r;
}

int main()
{
    scanf("%d%d%lld", &n, &r, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    printf("%lld", find_ans());
}