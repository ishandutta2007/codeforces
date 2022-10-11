#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define fi first
#define se second
using namespace std;

const int Q = 200005;

int n, k, q, l, r, pt = 0, ind[Q];
long long ans = 0, cnt[Q], sum[Q];
bool chk[Q];
vector<pair<int, int>> ve;

struct SQuery
{
    int c, p, ind;
}   que[Q];

void upd(int cur, bool chk)
{
    for (int u = que[cur].ind; u <= q; u += u & -u)
    {
        cnt[u] += (chk ? 1 : -1) * que[cur].c;
        sum[u] += (chk ? 1LL : -1LL) * que[cur].c * que[cur].p;
    }
}

long long find_ans()
{
    long long tot = 0;
    int cur = 0, idx = 0;
    for (int i = 31 - __builtin_clz(q); i >= 0; i--)
    {
        int nxt = idx + (1 << i);
        if (nxt <= q && cnt[nxt] + cur <= k)
        {
            idx = nxt;
            tot += sum[idx];
            cur += cnt[idx];
        }
    }
    if (idx == q)
        return tot;
    else
    {
        int pos = ind[idx + 1];
        return tot + 1LL * (k - cur) * (que[pos].p);
    }
}

int main()
{
    scanf("%d%d%d", &n, &k, &q);
    for (int i = 1; i <= q; i++)
    {
        scanf("%d%d%d%d", &l, &r, &que[i].c, &que[i].p);
        ind[i] = i;
        ve.push_back(make_pair(l, i));
        ve.push_back(make_pair(r + 1, i));
    }
    sort(ind + 1, ind + q + 1, [](const int &a, const int &b) { return que[a].p < que[b].p; });
    sort(ve.begin(), ve.end());
    for (int i = 1; i <= q; i++)
        que[ind[i]].ind = i;
    for (int i = 1; i <= n; i++)
    {
        for (; pt < ve.size() && ve[pt].fi <= i; pt++)
            upd(ve[pt].se, chk[ve[pt].se] = !chk[ve[pt].se]);
        ans += find_ans();
    }
    printf("%lld", ans);
}