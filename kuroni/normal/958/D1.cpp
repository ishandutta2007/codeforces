#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 200005;

struct SFrac
{
    int x, y, ind;
} a[N];
vector<int> ve;
int n, x, y, z, ans[N];

int main()
{
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("(%d+%d)/%d\n", &x, &y, &z);
        x += y;
        y = __gcd(x, z);
        a[i].x = x / y;
        a[i].y = z / y;
        a[i].ind = i;
    }
    sort(a + 1, a + n + 1, [](const SFrac &a, const SFrac &b) { return a.x < b.x || (a.x == b.x && a.y < b.y); });
    for (int i = 1; i <= n + 1; i++)
    {
        if (a[i].x != a[i - 1].x || a[i].y != a[i - 1].y)
        {
            for (int v : ve)
                ans[v] = ve.size();
            ve.clear();
        }
        ve.push_back(a[i].ind);
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
}