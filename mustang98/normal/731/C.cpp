#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
typedef long long ll;

const int max_n = 200008;

vector<int> v[max_n];
int n, m, k;
int col[max_n];
bool vis[max_n];
int kkol[max_n];

vector<int> usedcol;
int num;

int dfs1(int cur)
{
    num++;
    vis[cur] = true;
    kkol[col[cur]]++;
    usedcol.push_back(col[cur]);
    for(int i = 0; i < v[cur].size(); i++)
    {
        if (!vis[v[cur][i]])
        {
            dfs1(v[cur][i]);
        }
    }
}

int main()
{
    int a, b;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++)
    {
        cin >> col[i];
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &a, &b);
        a--;
        b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i] && v[i].size())
        {
            num = 0;
            dfs1(i);
            int maxcol = 0;
            for (int j = 0; j < usedcol.size(); j++)
            {
                int cc = usedcol[j];
                maxcol = max(maxcol, kkol[cc]);
                kkol[cc] = 0;
            }
            ans += num - maxcol;
            usedcol.clear();
        }
    }
    cout << ans;
    return 0;
}