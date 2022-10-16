#include <bits/stdc++.h>
using namespace std;
vector<int>v[200005];
int val[200005];
vector<int>rz;
long long dp[200005];
long long rzf;
long long dfs (int pz)
{
    dp[pz]=val[pz];
    for(int i=0;i<v[pz].size();++i)
        dp[pz]+=max(0LL,dfs(v[pz][i]));
    rzf+=dp[pz];
    return dp[pz];
}
long long dfs1 (int pz)
{
    int i;
    for(i=0;i<v[pz].size();++i)
    {
        if(dp[v[pz][i]]>0)
            dfs1(v[pz][i]);
    }
    rz.push_back(pz);
    for(i=0;i<v[pz].size();++i)
    {
        if(dp[v[pz][i]]<=0)
            dfs1(v[pz][i]);
    }
}
int a[200005];
int main()
{
    long long n,m,i,j,x,y,k,t,l,r;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>val[i];
    }
    for(i=1;i<=n;++i)
    {
        cin>>a[i];
        if(a[i]!=-1)
            v[a[i]].push_back(i);
    }
    for(i=1;i<=n;++i)
    {
        if(a[i]==-1)
            dfs(i);
    }
    for(i=1;i<=n;++i)
    {
        if(a[i]==-1)
            dfs1(i);
    }
    cout<<rzf<<'\n';
    for(i=0;i<n;++i)
        cout<<rz[i]<<' ';
    return 0;
}