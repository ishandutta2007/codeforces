#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e5+5;

ll n, ans = 0, p[N], par[N], depth[N];
ll used[N], color[N];
void dfs(ll v, ll dep, ll col)
{
    used[v] = 1;
    depth[v] = dep;
    color[v] = col;
    if (used[p[v]])
        ans += dep*(dep-1) + dep;
    else
        dfs(p[v], dep+1, col);
}
int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int k = -1;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        if (p[i] == i)
            k = i;
    }
    for (int i = 1; i <= n; i++)
        if (!used[i])
            dfs(i, 1, i);
//cout << ans;
        int pma = 0;
        for (int i = 1; i <= n; i++)
            if (depth[i] > depth[pma])
                pma = i;
        ans -= depth[pma]*(depth[pma]-1);
        ans -= depth[pma];
        int pm = 0;
        for (int i = 1; i <= n; i++)
            if (depth[i] > depth[pm] && color[i] != color[pma])
                pm = i;
        //cout << pma << ' ' << pm << endl;
        ans -= depth[pm]*(depth[pm]-1);
        ans -= depth[pm];
//cout << ans << ' '<< depth[pma] << ' ' << depth[pm] << endl;

        depth[pma] += depth[pm];
        ans += depth[pma]*(depth[pma]-1);
        ans += depth[pma];

        cout << ans;
    return 0;
}