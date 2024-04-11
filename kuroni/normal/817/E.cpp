#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int n, p, q, i, t;
map <int, int> a[31];

void upd(int x, int y)
{
    int i, tmp = 0;
    for (i = 30; i >= 0; i--)
    {
        tmp += (((x >> i) & 1) << i);
        a[i][tmp] += y;
    }
}

int que(int p, int q)
{
    int cur = 0, tmp, i, ans = 0;
    for (i = 30; i >= 0; i--)
    {
        if ((q >> i) & 1)
        {
            tmp = cur + ((((p >> i) & 1) ^ 0) << i);
            ans += a[i][tmp];
        }
        cur += ((((p >> i) & 1) ^ ((q >> i) & 1)) << i);
    }
    return ans;
}

int main()
{
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d%d", &t, &p);
        if (t == 1)
            upd(p, 1);
        else if (t == 2)
            upd(p, -1);
        else
        {
            scanf("%d", &q);
            printf("%d\n", que(p, q));
        }
    }
}