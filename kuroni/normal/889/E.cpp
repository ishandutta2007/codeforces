#include <iostream>
#include <cstdio>
#include <map>
#define fi first
#define se second
using namespace std;

int n;
long long u;
map<long long, long long> ma;

int main()
{
    scanf("%d%lld", &n, &u);
    ma[u - 1] = 0;
    for (int i = 1; i < n; i++)
    {
        scanf("%lld", &u);
        while (ma.rbegin()->fi >= u)
        {
            pair<long long, long long> cur = *ma.rbegin();
            ma.erase(cur.fi);
            long long lst = cur.fi / u * u;
            ma[cur.fi - lst] = max(ma[cur.fi - lst], lst * i + cur.se);
            ma[u - 1] = max(ma[u - 1], (lst - u) * i + cur.se);
        }
    }
    long long ans = 0;
    for (const pair<long long, long long> &u : ma)
        ans = max(ans, u.fi * n + u.se);
    printf("%lld", ans);
}