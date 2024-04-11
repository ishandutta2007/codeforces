#include <iostream>
#include <cstdio>
#include <set>
#define fi first
#define se second
using namespace std;

const int N = 1005;

int n;
pair<int, int> a[N], b[N];
set<pair<int, int>> se;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &a[i].fi, &a[i].se);
        se.insert(a[i]);
    }
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &b[i].fi, &b[i].se);
    for (int i = 1; i <= n; i++)
    {
        int x = a[i].fi + b[1].fi, y = a[i].se + b[1].se;
        bool chk = true;
        for (int j = 1; j <= n; j++)
            if (se.find(make_pair(x - b[j].fi, y - b[j].se)) == se.end())
            {
                chk = false;
                break;
            }
        if (chk)
            return printf("%d %d\n", x, y), 0;
    }
}