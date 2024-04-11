#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
int n,m,s;
vector< pair<int/*where*/,int/*cost*/> > adj[nmax],trav[nmax],fin[nmax];
stack<int> st;
bool been[nmax];
void dfs(int node)
{
    if(been[node])return;
    been[node]=1;
    for(auto k:adj[node])
        dfs(k.first);
    st.push(node);
}
int co=0,comp[nmax];
void dfs_other(int node)
{
    if(been[node])return;
    been[node]=1;
    comp[node]=co;
    for(auto k:trav[node])
        dfs_other(k.first);
}
long long mush(int x)
{
    int ok=0,not_ok=45000;
    while(not_ok-ok>1)
    {
        int av=(ok+not_ok)/2;
        if(x-av*(av+1)/2>=0)ok=av;
        else not_ok=av;
    }
    return 1LL*(ok+1)*x-1LL*ok*(ok+1)*(ok+2)/6;
}
long long add[nmax];
long long dp[nmax];
long long rec(int node)
{
    if(dp[node]!=-1)return dp[node];
    long long ans=0;
    for(auto k:fin[node])
        ans=max(ans,k.second+rec(k.first));
    ans=ans+add[node];
    dp[node]=ans;
    return ans;
}
int main()
{
memset(dp,-1,sizeof(dp));
scanf("%i%i",&n,&m);
int x,y,c;
for(int i=1;i<=m;i++)
{
    scanf("%i%i%i",&x,&y,&c);
    adj[x].push_back({y,c});
    trav[y].push_back({x,c});
}
scanf("%i",&s);
for(int i=1;i<=n;i++)
    dfs(i);
memset(been,0,sizeof(been));
while(st.size())
{
    int nod=st.top();
    st.pop();
    if(comp[nod])continue;
    co++;
    dfs_other(nod);
}

for(int i=1;i<=n;i++)
    for(auto k:adj[i])
    if(comp[i]==comp[k.first])add[comp[i]]+=mush(k.second);
    else fin[comp[i]].push_back({comp[k.first],k.second});

printf("%lld",rec(comp[s]));
return 0;
}