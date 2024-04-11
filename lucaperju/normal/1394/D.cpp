#include <bits/stdc++.h>
using namespace std;
vector<int> v[200005];
int h[200005],cst[200005];
long long dp[200005][2]; /// 0 : pz -> t | 1 : t -> pz
vector<long long>vc;
const long long INF = 10000000000000LL;
void dfs (int pz, int t)
{
    int cnt=v[pz].size();
    long long s=0;
    if(t!=-1)
        --cnt;
    if(cnt==0)
    {
        dp[pz][0]=dp[pz][1]=INF;
        if(h[pz]<=h[t])
            dp[pz][0]=cst[pz];
        if(h[pz]>=h[t])
            dp[pz][1]=cst[pz];
    }
    for(int i=0;i<v[pz].size();++i)
        if(v[pz][i]!=t)
            dfs(v[pz][i],pz);
    vc.clear();
    for(int i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]==t)
            continue;
        int f=v[pz][i];
        vc.push_back(dp[f][1]-dp[f][0]);
        s+=dp[f][0];
    }
    sort(vc.begin(),vc.end());
    for(int i=1;i<vc.size();++i)
        vc[i]+=vc[i-1];
    dp[pz][0]=dp[pz][1]=INF;
    if(pz==7)
    {
        ++cnt;
        --cnt;
    }
    /// 0 : pz -> t
    if(t!=-1 && h[t]>=h[pz])
    {
        for(int i=0;i<=cnt;++i)
        {
            long long sc=cst[pz]*1LL*max((int)v[pz].size()-(i+1),i+1);
            sc+=s;
            if(i)
                sc+=vc[i-1];
            dp[pz][0]=min(dp[pz][0],sc);
        }
    }
    /// 1 : t -> pz
    if(t!=-1 && h[t]<=h[pz] || t==-1)
    {
        for(int i=0;i<=cnt;++i)
        {
            long long sc=cst[pz]*1LL*max((int)v[pz].size()-i,i);
            sc+=s;
            if(i)
                sc+=vc[i-1];
            dp[pz][1]=min(dp[pz][1],sc);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n,m,d,i,j,t;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>cst[i];
    for(i=1;i<=n;++i)
        cin>>h[i];
    for(i=1;i<n;++i)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1,-1);
    cout<<dp[1][1];
    return 0;
}