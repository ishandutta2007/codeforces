#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

struct TSave
{
    int t, i;
    bool o;
}   a[400005];
int n, i;
set <int> cnt;
bool chk[200005];

inline bool operator < (const TSave &a, const TSave &b)
{
    return (a.t < b.t);
}

int main()
{
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d%d", &a[2 * i - 1].t, &a[2 * i].t);
        a[2 * i].t++;
        a[2 * i - 1].i = a[2 * i].i = i;
        a[2 * i - 1].o = true; a[2 * i].o = false;
        chk[i] = true;
    }
    sort(a + 1, a + 2 * n + 1);
    i = 1;
    while (i <= 2 * n)
    {
        while (a[i].t == a[i + 1].t)
        {
            if (a[i].o)
                cnt.insert(a[i].i);
            else cnt.erase(a[i].i);
            ++i;
        }
        if (a[i].o)
            cnt.insert(a[i].i);
        else cnt.erase(a[i].i);
        ++i;
        if (cnt.size() == 1)
            chk[*(cnt.begin())] = false;
    }
    for (i = 1; i <= n; i++)
        if (chk[i])
        {
            printf("%d", i);
            return 0;
        }
    printf("-1");
    return 0;
}