#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42,LIM=1<<21;
int n;
long long t;
vector< pair<int/*node*/,int/*cost*/> > adj[nmax];
int cookies[nmax];
int required[nmax];
pair<long long/*time*/,long long/*cookies*/> tree[LIM];
long long value[nmax],dp[nmax];
long long query(int node,int l,int r,long long tim)
{
    //cout<<"query "<<node<<" "<<l<<" "<<r<<" "<<tim<<" "<<tree[node].first<<" "<<tree[node].second<<endl;
    if(tim<=0)return 0;
    if(tim>=tree[node].first)return tree[node].second;
    if(l==r)return tim/l;
    int av=(l+r)/2;
    if(tim>=tree[node*2].first)return tree[node*2].second+query(node*2+1,av+1,r,tim-tree[node*2].first);
    return query(node*2,l,av,tim);
}
void update(int node,int l,int r,int pos,int add)
{
    if(l==r)
    {
        tree[node].second+=add;
        tree[node].first=1LL*tree[node].second*l;
        return;
    }
    int av=(l+r)/2;
    if(pos<=av)update(node*2,l,av,pos,add);
    else update(node*2+1,av+1,r,pos,add);
    tree[node]={tree[node*2].first+tree[node*2+1].first,tree[node*2].second+tree[node*2+1].second};
}
void dfs(int node,long long substract,int parent)
{
    update(1,1,1e6,required[node],cookies[node]);
    value[node]=query(1,1,1e6,t-substract);
    //cout<<node<<" -> "<<value[node]<<" "<<t-substract<<" "<<parent<<endl;
    for(auto k:adj[node])
        if(parent!=k.first)
        dfs(k.first,substract+2*k.second,node);
    update(1,1,1e6,required[node],-cookies[node]);
}
long long rec(int node,int parent)
{
    //cout<<node<<" "<<parent<<endl;
    if(dp[node]!=-1)return dp[node];
    vector<long long> vals={};
    for(auto k:adj[node])
        if(k.first!=parent)
        vals.push_back(rec(k.first,node));
    sort(vals.begin(),vals.end());
    dp[node]=value[node];
    if(vals.size()>=2)dp[node]=max(dp[node],vals[vals.size()-2]);
    if(vals.size()&&node==1)dp[node]=max(dp[node],vals[vals.size()-1]);
    //cout<<node<<" -> "<<dp[node]<<endl;
    return dp[node];
}
int main()
{
cin>>n>>t;
for(int i=1;i<=n;i++)cin>>cookies[i];
for(int i=1;i<=n;i++)cin>>required[i];
int p,l;
for(int i=2;i<=n;i++)
{
    cin>>p>>l;
    adj[p].push_back({i,l});
    adj[i].push_back({p,l});
}
dfs(1,0,1);
memset(dp,-1,sizeof(dp));
cout<<rec(1,1)<<endl;
return 0;
}