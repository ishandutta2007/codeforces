#include <cstdio>
#include <algorithm>
using namespace std;

struct save
{
    int val, ind;
} a[100005];
int n, s, i, mid, k = 0, t = 0;

inline bool cmp(const save &a, const save &b)
{
    return a.val + mid * a.ind < b.val + mid * b.ind;
}

void BS()
{
    int l = 1, r = min(n, 2000), sum;
    while (l <= r)
    {
        mid = (l + r) / 2;
        sum = 0;
        sort(a + 1, a + n + 1, cmp);
        for (i = 1; i <= mid; i++)
            sum += a[i].val + a[i].ind * mid;
        if (sum <= s)
        {
            k = mid;
            t = sum;
            l = mid + 1;
        }
        else r = mid - 1;
    }
}

int main()
{
    scanf("%d%d", &n, &s);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &a[i].val);
        a[i].ind = i;
    }
    BS();
    printf("%d %d", k, t);
}