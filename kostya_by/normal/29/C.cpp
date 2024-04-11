#include <iostream>
#include <map>
#include <vector>
#include <cstdio>

using namespace std;

map<int, int> mp;

int num[111111], n, a, b, timer = 1, val[111111];
vector<int> graf[111111];

void dfs(int v, int prev)
{
    printf("%d ", val[v]);
    for (int i = 0; i < graf[v].size(); i++)
    {
        int now = graf[v][i];
        if (now == prev) continue;
        dfs(now, v);
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d",&a,&b);
        int aa = mp[a];
        int bb = mp[b];
        if (aa == 0)
        {
            aa = timer++;
            mp[a] = aa;
            val[aa] = a;
        }
        if (bb == 0)
        {
            bb = timer++;
            mp[b] = bb;
            val[bb] = b;
        }
        num[aa]++;
        num[bb]++;
        graf[aa].push_back(bb);
        graf[bb].push_back(aa);
    }
    for (int i = 1; i <= n; i++)
    {
        if (num[i] == 1)
        {
            dfs(i, -1);
            return 0;
        }
    }
    return 0;
}