#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int n, m;
vector<pii> e[1000010];
int dep[1000010];
pii fa[1000010], pr[1000010];
int ans[1000010];
bool vis[1000010];

void dfs(int x) 
{
    vis[x] = true;
    for (auto &t : e[x]) 
        if (!vis[t.first]) 
        {
            dep[t.first] = dep[x] + 1;
            fa[t.first] = pii(x, t.second);
            dfs(t.first);
        }
}

int main() 
{
    int T;
    scanf("%d",&T);
    while(T --) 
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i ++) 
        {
            e[i].clear();
            vis[i] = false;
        }
        for (int i = 1; i <= m; i ++) 
            ans[i] = 0;
        for (int i = 1; i <= m; i ++) 
        {
            int u, v;
            scanf("%d%d", &u, &v);
            e[u].emplace_back(v, i);
            e[v].emplace_back(u, i);
            if (u > v) swap(u, v);
            pr[i] = pii(u, v);
        }
        fa[1] = pii(0, 0);
        dep[1] = 1;
        dfs(1);
        for (int i = 2; i <= n; i ++) 
            ans[fa[i].second] = 1;
        
        if (m == n + 2) 
        {
            set<int> p;
            set<int> ee;
            for (int i = 1; i <= m; i ++) 
                if (!ans[i]) 
                {
                    p.insert(pr[i].first);
                    p.insert(pr[i].second);
                    ee.insert(i);
                }
            
            if (p.size() == 3) 
            {
                int d = 0;
                for (auto &t : p) 
                    if (dep[t] > dep[d]) 
                        d = t;
                ans[fa[d].second] = 0;
                for (auto &t : ee) 
                    if (pr[t].first == d || pr[t].second == d)
                    {
                        ans[t] = 1;
                        break;
                    }
            }
        }
        for (int i = 1; i <= m; i ++) 
            printf("%d", ans[i]);
        
        puts("");
    }    
}