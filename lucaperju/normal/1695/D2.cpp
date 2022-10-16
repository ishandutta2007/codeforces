#include <bits/stdc++.h>

using namespace std;
vector<int>v[200005];
int dp[200005],can[200005];
void dfs (int pz, int t)
{
    int ok=0;
    for(int i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]==t)
            continue;
        dfs(v[pz][i],pz);
        dp[pz]+=dp[v[pz][i]];
        if(can[v[pz][i]])
            ok=1;
    }
    if(ok && (int)v[pz].size()==2 || (int)v[pz].size()==1)
        can[pz]=1;
    if(v[pz].size()==1)
    {
        dp[pz]=1;
        return;
    }
    if(!can[pz] && ok)
        --dp[pz];
}
int main()
{
    ios_base::sync_with_stdio(false);
    int k=0,t,i,j,n,a,b,m,x,y,ok=1;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n==1)
        {
            cout<<"0\n";
            continue;
        }
        for(i=1;i<=n;++i)
        {
            can[i]=dp[i]=0;
            v[i].clear();
        }
        int ok=0;
        for(i=1;i<n;++i)
        {
            int a,b;
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
            if((int)v[a].size()>=3 || (int)v[b].size()>=3)
                ok=1;
        }
        if(ok==0)
        {
            cout<<"1\n";
            continue;
        }
        int r=1;
        for(i=1;i<=n;++i)
            if((int)v[i].size()>=3)
                r=i;
        dfs(r,0);
        cout<<dp[r]<<'\n';
    }
    return 0;
}