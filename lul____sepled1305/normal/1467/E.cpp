#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using piii = pair<int,pii>;
const int N = 2e5+10;
 
map<int,int> mp;
vector<int> G[N];
set<piii> st;
int color[N];
int mask[N];
int dp[N];
int son[N];
 
void dfs(int node, int par, int depth)
{
    st.insert({color[node],{depth,node}});
    auto it = st.lower_bound({color[node],{depth,node}});
    if(it != st.begin())
    {
        it--;
        piii cur = *it;
        if(cur.first == color[node])
        {
            mask[0] ++;
            mask[son[cur.second.second]] --;
            mask[node] ++;
            mp[color[node]] --;
        }
    }
    for(auto it: G[node])
    {
        if(it != par)
        {
            son[node] = it;
            dfs(it,node,depth + 1);
        }
    }
    st.erase({color[node],{depth,node}});
}
 
void update(int par, int node)
{
    dp[node] = dp[par] + mask[node];
    for(auto it: G[node])
    {
        if(it != par)
            update(node,it);
    }
}
 
void solve()
{
    int n,i,ans = 0;
    cin>>n;
    for(i=0; i<n; i++)
        cin>>color[i], mp[color[i]]++;
    for(i=0; i<n-1; i++)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0,0,0);
    for(i=0;i<n;i++)
    {
        if(mp[color[i]] > 1)
            mask[i]++;
    }
    update(0,0);
    for(i=0;i<n;i++)
    {
        if(dp[i] == 0)
            ans++;
    }
    cout<<ans;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    return 0;
}