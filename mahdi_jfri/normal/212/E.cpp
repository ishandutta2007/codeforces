#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 5e3 + 20;
ll sum[maxn] , p[maxn];
vector<int> adj[maxn];
set<pair<int , int> > st;
set<int> ans[maxn];
void dfs(int v)
{
    sum[v] = 1;
    for(auto u : adj[v])
    {
        if(u != p[v])
        {
            p[u] = v;
            dfs(u);
            sum[v] += sum[u];
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
    p[0] = -1;
    dfs(0);
    for(int i = 0; i < n; i++)
    {
        vector<int> x;
        for(auto u : adj[i])
            if(i == p[u])
            {
                x.pb(sum[u]);
              //  if(i == 5)
                //    cout << u + 1 << " " << sum[u] << endl;
            }
        x.pb(n - sum[i]);
        ans[i].insert(0);
        for(auto a : x)
        {
            set<int> ans2;
            for(auto m : ans[i])
                ans2.insert(m) , ans2.insert(m + a);
            ans2.swap(ans[i]);
        }
    }
    for(int i = 1; i <= n - 2; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(ans[j].find(i) != ans[j].end())
            {
              //  cout << i << " " << j + 1 << endl;
                st.insert({min(i , n - 1 - i) , max(i , n - 1 - i)});
                st.insert({max(i , n - 1 - i) , min(i , n - 1 - i)});
                break;
            }
        }
    }
    cout << st.size() << endl;
    for(auto x : st)
        cout << x.first << " " << x.second << endl;
}