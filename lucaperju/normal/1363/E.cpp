#include <bits/stdc++.h>

using namespace std;
long long cst[200005],x[200005],y[200005];
vector <int> v[200005];
long long dp[200005];
void dfsinit (int pz, int t)
{
    if(t!=-1)
        cst[pz]=min(cst[pz],cst[t]);
    for(int i=0;i<v[pz].size();++i)
        if(v[pz][i]!=t)
            dfsinit(v[pz][i],pz);
}
int dfs (int pz, int t)
{
    int s=0;
    int spoz=0;
    if(x[pz]==1 && y[pz]==0)
    {
        int a=1;
        if(a>0)
            spoz+=a;
        s+=a;
    }
    if(x[pz]==0 && y[pz]==1)
    {
        int a=-1;
        if(a>0)
            spoz+=a;
        s+=a;
    }
    for(int i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]!=t)
        {
            int a=dfs(v[pz][i],pz);
            if(a>0)
                spoz+=a;
            s+=a;
            dp[pz]+=dp[v[pz][i]];
        }
    }
    int nrop=spoz-max(s,0);
    dp[pz]+=nrop*2LL*cst[pz];
    return s;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n,k,t,i,j,mx,p,mxx=0,s,q,nr1=0,nr2=0,nr3=0;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>cst[i]>>x[i]>>y[i];
    for(i=1;i<n;++i)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfsinit(1,-1);
    int a=dfs(1,-1);
    if(a!=0)
        cout<<-1;
    else
        cout<<dp[1];
    return 0;
}