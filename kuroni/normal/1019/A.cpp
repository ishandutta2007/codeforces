#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int M = 3005;
const long long INF = 1E18 + 7;

int cnt = 0, n, m, p, c;
long long ans = INF;
vector<pair<int, int>> tot, ve[M];
bool chk[M];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &p, &c);
        if (p == 1)
            cnt++;
        else
        {
            tot.push_back(make_pair(c, i));
            ve[p].push_back(make_pair(c, i));
        }
    }
    for (int i = 2; i <= m; i++)
        sort(ve[i].begin(), ve[i].end());
    sort(tot.begin(), tot.end());
    for (int i = max(1, cnt); i <= n; i++)
    {
        fill(chk, chk + M, false);
        int tmp = cnt;
        long long cur = 0;
        for (int j = 2; j <= m; j++)
            for (int k = 0; k <= ((int)ve[j].size()) - i; k++)
            {
                chk[ve[j][k].second] = true;
                ++tmp;
                cur += ve[j][k].first;
            }
        for (int j = 0; j < tot.size() && tmp < i; j++)
            if (!chk[tot[j].second])
            {
                chk[tot[j].second] = true;
                ++tmp;
                cur += tot[j].first;
            }
        if (tmp >= i)
            ans = min(ans, cur);
    }
    printf("%lld", ans);
}