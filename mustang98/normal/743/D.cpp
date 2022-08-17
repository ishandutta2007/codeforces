#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200005;
const ll inf = 1e18 + 8;

int d[max_n];
int n;
/*struct node
{
    ll sum;
    ll maxxsum = -inf;
};*/
ll sum[max_n];
ll maxsum[max_n];

vector<int> v[max_n];

bool isbambuk = true;
ll ans = -inf;

void dfs(int cur, int pr)
{
    // leaf
    if (v[cur].size() == 1 && v[cur][0] == pr)
    {
        sum[cur] = d[cur];
        maxsum[cur] = d[cur];
        return;
    }
    sum[cur] = d[cur];
    maxsum[cur] = -inf;
    for (int i = 0; i < v[cur].size(); i++)
    {
        if (v[cur][i] == pr) continue;
        dfs(v[cur][i], cur);
        sum[cur] += sum[v[cur][i]];
        maxsum[cur] = max(maxsum[cur], maxsum[v[cur][i]]);
    }
    maxsum[cur] = max(maxsum[cur], sum[cur]);
}

void dfs2(int cur, int pr)
{
    for (int i = 0; i < v[cur].size(); i++)
    {
        if (v[cur][i] == pr) continue;
        dfs2(v[cur][i], cur);
    }
    if (cur == 0)
    {
        if (v[cur].size() <= 1)
        {
            return;
        }
    }
    if (cur && v[cur].size() <= 2)
    {
        return;
    }
    isbambuk = false;
    ll maxs1 = -inf, maxs2 = -inf;
    for (int i = 0; i < v[cur].size(); i++)
    {
        int to = v[cur][i];
        if (to == pr) continue;
        if (maxsum[to] >= maxs1)
        {
            maxs2 = maxs1;
            maxs1 = maxsum[to];
            continue;
        }
        if (maxsum[to] >= maxs2)
        {
            maxs2 = maxsum[to];
        }
    }
    ans = max(ans, maxs2 + maxs1);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", d + i);
    }
    int a, b;

    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d%d", &a, &b);
        a--;
        b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(0, -1);
   // for (int i = 0; i < n; i++) cout << maxsum[i] << ' ';
    dfs2(0, -1);
    if (isbambuk)
    {
        cout << "Impossible";
    }
    else
    {
        cout << ans;
    }
    return 0;
}