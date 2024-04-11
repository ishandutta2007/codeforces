#include <iostream>
#include <cstdio>
#include <vector>
#define fi first
#define se second
using namespace std;

const int N = 500005, Q = 500005, LG = 20;

int n, q, l, r, a[N], ans[Q];
pair<int, int> f[LG];
vector<pair<int, int>> que[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        scanf("%d%d", &l, &r);
        que[r].push_back(make_pair(l, i));
    }
    for (int i = 1; i <= n; i++)
    {
        pair<int, int> cur = {a[i], i};
        for (int j = LG - 1; j >= 0; j--)
            if (cur.fi >> j & 1)
            {
                if (f[j].fi == 0)
                {
                    f[j] = cur;
                    break;
                }
                else if (f[j].se < cur.se)
                    swap(f[j], cur);
                cur.fi ^= f[j].fi;
            }
        for (pair<int, int> &v : que[i])
            for (int j = LG - 1; j >= 0; j--)
                if (f[j].se >= v.fi)
                    ans[v.se] = max(ans[v.se], ans[v.se] ^ f[j].fi);
    }
    for (int i = 1; i <= q; i++)
        printf("%d\n", ans[i]);
}