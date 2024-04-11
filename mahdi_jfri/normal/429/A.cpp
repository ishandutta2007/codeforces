#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
bool a[maxn] , goal[maxn];
vector<int> adj[maxn] , ans;
void dfs(int v , int t = 0 , int x = 0 , int y = 0 , int p = -1)
{
    if(goal[v] != a[v] ^ (t? y : x))
        ans.pb(v + 1);
    for(auto u : adj[v])
    {
        if(u == p)
            continue;
        if(t == 0)
        {
            if(goal[v] == a[v] ^ x)
                dfs(u , !t , x , y , v);
            else
                dfs(u , !t , !x , y , v);
        }
        else
        {
            if(goal[v] == a[v] ^ y)
                dfs(u , !t , x , y , v);
            else
                dfs(u , !t , x , !y , v);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        int a , b;
        cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> goal[i];
    dfs(0);
    cout << ans.size() << endl;
    for(auto u : ans)
        cout << u << "\n";
}