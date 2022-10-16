#include <bits/stdc++.h>

using namespace std;

/*
const long long mod = 998244353;

long long lgput (long long a, long long exp)
{
    long long rz=1;
    while(exp)
        if(exp&1)
            exp^=1,rz=rz*1LL*a%mod;
        else
            exp>>=1,a=a*1LL*a%mod;
    return rz;
}
long long fct[200005],invfct[200005],inv[200005];
long long put2[200005];
long long cmb (long long n, long long k)
{
    if(n<k || k<0 || n<0)
        return 0;
    return fct[n]*1LL*invfct[k]%mod*1LL*invfct[n-k]%mod;
}
void init ()
{
    inv[1]=fct[0]=fct[1]=invfct[0]=invfct[1]=put2[0]=1,put2[1]=2;
    for(long long i=2;i<=200000;++i)
        put2[i]=put2[i-1]*2LL%mod,inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod,fct[i]=i*1LL*fct[i-1]%mod,invfct[i]=inv[i]*1LL*invfct[i-1]%mod;
}
*/
const int K = 500;
vector<int>v[200005];
struct qry
{
    int nod,k,pz,rz;
}qs[200005];
vector<int>qsk[5005];
int sz[200005];
int dp[200005][502];
void dfsinit (int nod, int t)
{
    sz[nod]=1;
    for(int i=0;i<v[nod].size();++i)
    {
        if(v[nod][i]==t)
            continue;
        dfsinit(v[nod][i],nod);
        sz[nod]+=sz[v[nod][i]];
    }
}
void dfsdpc (int nod, int t)
{
    for(int i=0;i<v[nod].size();++i)
    {
        if(v[nod][i]==t)
            continue;
        dfsdpc(v[nod][i],nod);
        for(int j=0;j<=K;++j)
            dp[nod][j]=dp[nod][j]+max(1,dp[v[nod][i]][j]-j);
    }
}
/*void join (int a, int sza, int b)
{
    int i,j,szb=sz[b]/K+1;
    for(i=sza/K+1;i>=0;--i)
    {
        for(j=szb;j>=1;--j)
            dp[a][i+j]=max(dp[a][i+j],dp[a][i]+dp[b][j-1]);
        ++dp[a][i];
    }

    for(i=0;i<=(sza+sz[b])/K+1;++i)
    {
        aux[i]=dp[a][i]+1;
        for(j=0;j<min(i,sz[b]/K+1);++j)
            aux[i]=max(aux[i],dp[a][i-j-1]+dp[b][j]);
    }
    for(i=0;i<=(sza+sz[b])/K+1;++i)
        dp[a][i]=aux[i];

}*/
void dfs (int nod, int t)
{
    int szc=1,szb;
    int i,j,k;
    for(i=0;i<=K;++i)
        dp[nod][i]=0;
    for(i=0;i<v[nod].size();++i)
    {
        if(v[nod][i]==t)
            continue;
        dfs(v[nod][i],nod);
        //join(nod,szc,v[nod][i]);
        szb=sz[v[nod][i]]/K+1;
        for(j=szc/K+1;j>=0;--j)
        {
            for(k=szb;k>=1;--k)
                dp[nod][j+k]=max(dp[nod][j+k],dp[nod][j]+dp[v[nod][i]][k-1]);
            ++dp[nod][j];
        }
        szc+=sz[v[nod][i]];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0); /// nice fking time limit
    long long m,q,t,s=0,n,d,j,i,k;
    cin>>n;
    for(i=1;i<n;++i)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfsinit(1,-1);
    cin>>q;
    dfsdpc(1,-1);
    for(i=1;i<=q;++i)
    {
        cin>>qs[i].nod>>qs[i].k;
        qs[i].pz=i;
        if(qs[i].k<=K)
            qs[i].rz=dp[qs[i].nod][qs[i].k];
    }
    /*for(i=0;i<=K+1;++i)
    {
        //if(qsk[i].size()==0)
        //    continue;
        dfsdpc(1,-1,i);
        for(j=0;j<qsk[i].size();++j)
            qs[qsk[i][j]].rz=dpc[qs[qsk[i][j]].nod];
    }*/
    dfs(1,-1);
    for(i=1;i<=q;++i)
    {
        if(qs[i].k<=K)
        {
            cout<<qs[i].rz<<'\n';
            continue;
        }
        for(int cat=0;cat<=K;++cat)
            qs[i].rz=max(qs[i].rz,dp[qs[i].nod][cat]-cat*qs[i].k);
        cout<<qs[i].rz<<'\n';
    }
    return 0;
}