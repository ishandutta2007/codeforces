#include <iostream>
#include <cstdio>
#include <algorithm>
#define fi first
#define se second
using namespace std;

const int N = 100005;

int n, ans[N];
pair<int, int> a[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i].fi);
        a[i].se = i;
    }
    sort(a + 1, a + n + 1);
    for (int pt = 1, i = 1; i <= n; pt++)
    {
        int cur = n - a[i].fi;
        for (int j = 0; j < cur; j++)
        {
            if (n - a[i].fi != cur)
                return printf("Impossible"), 0;
            ans[a[i++].se] = pt;
        }
    }
    printf("Possible\n");
    for (int i = 1; i <= n; i++)
        printf("%d " , ans[i]);
}