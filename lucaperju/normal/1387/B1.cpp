#include <bits/stdc++.h>
using namespace std;
vector<long long>v[100005];
long long dp[100005][2],fin[100005];
long long cat[100005][2];
long long cine[100005];
//long long towhere[100005];
int fel[100005];
struct ura
{
    long long d0,d1,pz;
};
vector<ura>vc;
bool cmp (ura a, ura b)
{
    return a.d1-a.d0<b.d1-b.d0;
}
void dfs1(int pz, int t)
{
    int felc=fel[pz];
    int catc=cat[pz][felc];
    vc.clear();
    for(long long i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]==t)
            continue;
        long long nn=v[pz][i];
        vc.push_back({dp[nn][0],dp[nn][1],nn});
    }
    sort(vc.begin(),vc.end(),cmp);
    for(int i=0;i<catc;++i)
        fel[vc[i].pz]=1;
    for(long long i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]==t)
            continue;
        dfs1(v[pz][i],pz);
    }
    vc.clear();
    for(long long i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]==t)
            continue;
        long long nn=v[pz][i];
        vc.push_back({dp[nn][0],dp[nn][1],nn});
    }
    sort(vc.begin(),vc.end(),cmp);
    if(felc==1)
    {
        if(catc)
        {
            cine[pz]=cine[vc[0].pz];
            fin[vc[catc-1].pz]=pz;
            for(int i=catc-2;i>=0;--i)
                fin[vc[i].pz]=cine[vc[i+1].pz];
        }
        else
            cine[pz]=pz;
    }
    else
    {
        fin[pz]=cine[vc[0].pz];
        fin[vc[catc-1].pz]=pz;
        for(int i=catc-2;i>=0;--i)
            fin[vc[i].pz]=cine[vc[i+1].pz];
    }
}
void dfs (long long pz, long long t)
{
    dp[pz][0]=dp[pz][1]=999999999;
    for(long long i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]==t)
            continue;
        dfs(v[pz][i],pz);
    }
    vc.clear();
    for(long long i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]==t)
            continue;
        long long nn=v[pz][i];
        vc.push_back({dp[nn][0],dp[nn][1],nn});
    }
    sort(vc.begin(),vc.end(),cmp);
    long long sc=0;
    for(int i=0;i<vc.size();++i)
        sc+=vc[i].d0;
    if(vc.size()==0)
    {
        dp[pz][0]=999999999;
        dp[pz][1]=0;
        return;
    }
    dp[pz][1]=sc;
    cine[pz]=pz;
    for(int i=0;i<vc.size();++i)
    {
        sc+=vc[i].d1-vc[i].d0;
        long long vlc=sc+(i+1)*2LL;
        if(vlc<dp[pz][0])
        {
            dp[pz][0]=vlc;
            cat[pz][0]=i+1;
        }
        if(vlc<dp[pz][1])
        {
            dp[pz][1]=vlc;
            cat[pz][1]=i+1;
            cine[pz]=vc[0].pz;
        }
    }
}
int main()
{
    long long n,m,i,j,x,y,k,t,l,r;
    cin>>n;
    for(i=1;i<n;++i)
    {
        long long a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1,-1);
    cout<<dp[1][0]<<'\n';
    dfs1(1,-1);
    for(i=1;i<=n;++i)
        cout<<fin[i]<<' ';
    return 0;
}