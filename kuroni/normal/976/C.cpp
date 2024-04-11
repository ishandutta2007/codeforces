#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 300005;

struct SLine
{
    int l, r, ind;
} a[N];
int n;
pair<int, int> cur = make_pair(0, 0);

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &a[i].l, &a[i].r);
        a[i].ind = i;
    }
    sort(a + 1, a + n + 1, [](const SLine &a, const SLine &b) { return a.l < b.l || (a.l == b.l && a.r > b.r); });
    for (int i = 1; i <= n; i++)
        if (a[i].r <= cur.first)
        {
            printf("%d %d\n", a[i].ind, cur.second);
            return 0;
        }
        else
            cur = max(cur, make_pair(a[i].r, a[i].ind));
    printf("-1 -1");
}