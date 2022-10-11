#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 100005, Q = 100005, MX = 1 << 20, MOD = 1E9 + 7;

int n, q, u, v, cur = 1, a[N], ans[Q];
bool chk[MX] = {true};
vector<int> upd, ve = {0};
vector<pair<int, int>> que[N];

int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    for (int i = 1; i <= q; i++)
    {
        scanf("%d%d", &u, &v);
        que[u].push_back(make_pair(v, i));
    }
    for (int i = 1; i <= n; i++)
    {
        if (chk[a[i]])
            (cur *= 2) %= MOD;
        else
            for (int &v : ve)
            {
                chk[v ^ a[i]] = true;
                upd.push_back(v ^ a[i]);
            }
        for (int &v : upd)
            ve.push_back(v);
        upd.clear();
        for (pair<int, int> &v : que[i])
            ans[v.second] = (chk[v.first] ? cur : 0);
    }
    for (int i = 1; i <= q; i++)
        printf("%d\n", ans[i]);
}