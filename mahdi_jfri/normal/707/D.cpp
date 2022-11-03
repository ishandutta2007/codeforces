#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e3 + 20;
const int qmax = 1e5 + 20;
int ans[qmax] , id , x[qmax] , y[qmax] , before , a[qmax] , m[maxn][maxn] , z;
vector<int> adj[qmax];
void dfs(int v)
{
    for(auto u : adj[v])
    {
        ans[u] = ans[v];
        if(a[u] == 1)
        {
            if(!m[x[u]][y[u]])
            {
                m[x[u]][y[u]] = 1;
                ans[u]++;
                dfs(u);
                m[x[u]][y[u]] = 0;
                continue;
            }
            else
                dfs(u);
        }
        if(a[u] == 2)
        {
            if(m[x[u]][y[u]])
            {
                m[x[u]][y[u]] = 0;
                ans[u]--;
                dfs(u);
                m[x[u]][y[u]] = 1;
                continue;
            }
            else
                dfs(u);
        }
        if(a[u] == 3)
        {
            for(int i = 1; i <= z; i++)
            {
                if(m[x[u]][i])
                    ans[u]--;
                else
                    ans[u]++;
                m[x[u]][i] = !m[x[u]][i];
            }
            dfs(u);
            for(int i = 1; i <= z; i++)
                m[x[u]][i] = !m[x[u]][i];
        }
        if(a[u] == 4)
            dfs(u);
    }
}
int main()
{
    int n , q;
    cin >> n >> z >> q;
    for(int i = 1; i <= q; i++)
    {
        cin >> a[i];
        if(a[i] == 1 || a[i] == 2)
            cin >> x[i] >> y[i];
        if(a[i] == 3)
            cin >> x[i];
        if(a[i] == 4)
        {
            int k;
            cin >> k;
            adj[k].pb(i);
            continue;
        }
        adj[i - 1].pb(i);
    }
    dfs(0);
    for(int i = 1; i <= q; i++)
        cout << ans[i] << endl;
}