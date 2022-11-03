#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
int h[maxn] , e;
vector<pair<int , int> > adj[maxn];
vector<pair< pair<int , int> , pair<int , int> > > ans;
bool visited[maxn] , evisited[maxn];
void dfs(int v)
{
    e += adj[v].size();
    visited[v] = 1;
    for(auto u : adj[v])
        if(!visited[u.first])
            h[u.first] = h[v] + 1 , dfs(u.first);
    vector<pair<int , int> > backedge , down , p;
    for(auto u : adj[v])
    {
        if(evisited[u.second])
            continue;
        if(h[u.first] > h[v])
            down.pb(u);
        else if(h[u.first] == h[v] - 1)
            p.pb(u);
        else
            backedge.pb(u);
    }
    if(down.size())
    {
        for(int i = (int)down.size() - 2; i > -1; i -= 2)
        {
            pair<int, int> a = down[i] , b = down[i + 1];
            down.pop_back();
            down.pop_back();
            ans.pb({{a.first , v} , {v , b.first}});
            evisited[a.second] = evisited[b.second] = 1;
        }
        if(down.size())
        {
            if(backedge.size())
            {
                pair<int, int> a = backedge.back() , b = down.back();
                ans.pb({{a.first , v} , {v , b.first}});
                evisited[a.second] = evisited[b.second] = 1;
                backedge.pop_back();
                down.pop_back();
            }
            else if(p.size())
            {
                pair<int, int> a = p.back() , b = down.back();
                ans.pb({{a.first , v} , {v , b.first}});
                evisited[a.second] = evisited[b.second] = 1;
                p.pop_back();
                down.pop_back();
            }
        }
    }
    while(backedge.size() > 1)
    {
        pair<int , int> a = backedge.back();
        backedge.pop_back();
        pair<int , int> b = backedge.back();
        backedge.pop_back();
        evisited[a.second] = evisited[b.second] = 1;
        ans.pb({{a.first , v} , {v , b.first}});
    }
    if(backedge.size())
    {
        pair<int, int> a = backedge.back() , b = p.back();
        ans.pb({{a.first , v} , {v , b.first}});
        evisited[a.second] = evisited[b.second] = 1;
        p.pop_back();
        backedge.pop_back();
    }
}
int main()
{
    int n , m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a , b;
        cin >> a >> b;
        adj[--a].pb({--b , i});
        adj[b].pb({a , i});
    }
    for(int i = 0; i < n; i++)
        if(!visited[i])
        {
            e = 0;
            dfs(i);
            e /= 2;
            if(e & 1)
            {
                cout << "No solution\n";
                return 0;
            }
        }
    for(auto u : ans)
        cout << u.first.first + 1 << " " << u.first.second + 1 << " " << u.second.second + 1 << endl;
}