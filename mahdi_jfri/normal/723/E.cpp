#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
vector<pair<int , int> > adj[maxn];
vector<int> ans;
map<int , int> mp[maxn];
bool visited[maxn];
void eueler_dfs(int v)
{
    for(int i = adj[v].size() - 1; i > -1; i--)
    {
        int u = adj[v][i].first , k = adj[v][i].second;
        adj[v].pop_back();
        if(!visited[k])
            visited[k] = 1 , eueler_dfs(u);
    }
    ans.pb(v);
}
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n , m , mm;
        cin >> n >> m;
        mm = m;
        for(int i = 0; i < m; i++)
        {
            int a , b;
            cin >> a >> b;
            adj[--a].pb({--b , i});
            adj[b].pb({a , i});
            mp[a][b] = mp[b][a] = i + 1;
        }
        int last = -1 , t = 0;
        for(int i = 0; i < n; i++)
            if(adj[i].size() & 1)
            {
                t++;
                if(last == -1)
                    last = i;
                else
                {
                    adj[last].pb({i , mm + 1});
                    adj[i].pb({last , mm + 1});
                    last = -1;
                    mm++;
                }
            }
        cout << n - t << endl;
        for(int i = 0; i < n; i++)
        {
            if(adj[i].size())
            {
                eueler_dfs(i);
                for(int i = 1; i < ans.size(); i++)
                    if(mp[ans[i]][ans[i - 1]])
                        cout << ans[i - 1] + 1 << " " << ans[i] + 1 << endl , mp[ans[i]][ans[i - 1]] = mp[ans[i - 1]][ans[i]] = 0;
                ans.clear();
            }
        }
        for(int i = 0; i < n; i++)
            adj[i].clear() , mp[i].clear();
        fill(visited , visited + maxn , 0);
    }
}