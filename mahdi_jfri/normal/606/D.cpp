#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
pair<int , int> ans[maxn];
pair< pair<int , int> , int> edge[maxn];
int t, tah , g[maxn];
vector<int> dsu[maxn];
set<pair<int , int> > sizes;
set<int> adj[maxn];
void merg(int x , int y)
{
    t += dsu[x].size() * dsu[y].size();
    if(dsu[x].size() < dsu[y].size())
    {
        while(!dsu[x].empty())
        {
            dsu[y].pb(dsu[x].back());
            g[dsu[x].back()] = y;
            dsu[x].pop_back();
        }
    }
    else
    {
        while(!dsu[y].empty())
        {
            dsu[x].pb(dsu[y].back());
            g[dsu[y].back()] = x;
            dsu[y].pop_back();
        }
    }
}
bool camp(pair<pair<int , int> , int> a , pair<pair<int , int> , int> b)
{
    return (a.first.first == b.first.first && a.first.second > b.first.second) || a.first.first < b.first.first;
}
int main()
{
    int n , m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        dsu[i].pb(i) , sizes.insert({1 , i}) , g[i] = i;
    for(int i = 0; i < m; i++)
        scanf("%d%d", &edge[i].first.first, &edge[i].first.second) , edge[i].second = i;
    sort(edge , edge + m , camp);
    for(int i = 0; i < m; i++)
    {
        if(edge[i].first.second == 0 && !t)
        {
            cout << -1;
            return 0;
        }
        else if(!edge[i].first.second && t)
        {
            t--;
            tah = rand() % n;
            while(adj[tah].size() == dsu[g[tah]].size() - 1)
                tah++ , tah %= n;
            for(int j : dsu[g[tah]])
                if(j != tah && adj[tah].find(j) == adj[tah].end())
                {
                    adj[tah].insert(j);
                    adj[j].insert(tah);
                    ans[edge[i].second] = {j , tah};
                    break;
                }
        }
        else
        {
            int k = sizes.rbegin()->second;
            sizes.erase(*sizes.rbegin());
            int k1 = sizes.rbegin()->second;
            sizes.erase(*sizes.rbegin());
            int v = dsu[k][0] , u = dsu[k1][0];
            ans[edge[i].second] = {v , u};
            adj[v].insert(u);
            adj[u].insert(v);
            if(dsu[k].size() < dsu[k1].size())
                sizes.insert({dsu[k].size() + dsu[k1].size() , k1});
            else
                sizes.insert({dsu[k].size() + dsu[k1].size() , k});
            t--;
            merg(k , k1);
        }
    }
    for(int i = 0; i < m; i++)
        printf("%d %d\n" , ans[i].first + 1 , ans[i].second + 1);
}