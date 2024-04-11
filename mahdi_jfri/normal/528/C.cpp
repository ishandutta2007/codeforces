#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push
#define mp make_pair
const int maxn = 3e5 + 100;
stack<pair<int , int> > adj[maxn];
vector<int> vertex , ans;
bool visited[maxn];
int tmp = -1 , a, b;
map<pair<int , int> , int> ind;
void dfs(int v)
{
    if(!adj[v].size())
        return;
    while(!adj[v].empty())
    {
        pair<int , int> e = adj[v].top();
        adj[v].pop();
        if(!visited[e.second])
        {
            visited[e.second] = 1;
            dfs(e.first);
        }
    }
    ans.push_back(v);
}
int main()
{
    int n , m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d", &a, &b);
        adj[--a].pb(mp(--b , i));
        adj[b].pb(mp(a , i));
    }
    for(int i = 0; i < n; i++)
        if(adj[i].size() & 1)
        {
            if(tmp == -1)
                tmp = i;
            else
            {
                adj[i].pb({tmp , m});
                adj[tmp].pb({i , m});
                tmp = -1;
                m++;
            }
        }
    if(m & 1)
    {
        adj[0].pb(mp(0 , m));
        m++;
    }
    dfs(0);
    printf("%d\n", m);
    for(int i = 1; i < ans.size(); i++)
    {
        if(i & 1)
            printf("%d %d\n", ans[i] + 1 , ans[i - 1] + 1);
        else
            printf("%d %d\n", ans[i - 1] + 1 , ans[i] + 1);
    }
}