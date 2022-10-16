#include <bits/stdc++.h>

using namespace std;

/*
const long long mod = 1000000007;

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
vector<int>v[200003];
long long h[200003],mxsub[200003],dp[200003];
void dfsinit (int pz, int t)
{
    for(int i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]==t)
            continue;
        dfsinit(v[pz][i],pz);
        mxsub[pz]=max(mxsub[pz],max(h[v[pz][i]],mxsub[v[pz][i]]));
        dp[pz]+=dp[v[pz][i]];
    }
    dp[pz]+=max(0LL,h[pz]-mxsub[pz]);
    //mxsub[i]=max(mxsub[i],h[i]);
}
long long ans=0;
void dfs (int pz, int t)
{
    ans=min(ans,dp[pz]+max(mxsub[pz],h[pz]));
    int mx1=-1,mx2=-1;
    long long s=0;
    for(int i=0;i<v[pz].size();++i)
    {
        if(mx1==-1 || max(h[v[pz][i]],mxsub[v[pz][i]])>max(h[v[pz][mx1]],mxsub[v[pz][mx1]]))
        {
            mx2=mx1;
            mx1=i;
        }
        else if(mx2==-1 || max(h[v[pz][i]],mxsub[v[pz][i]])>max(h[v[pz][mx2]],mxsub[v[pz][mx2]]))
        {
            mx2=i;
        }
        s+=dp[v[pz][i]];
    }
    if(mx1==-1)
        ++mx1;
    if(mx2==-1)
        ++mx2;
    for(int i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]==t)
            continue;

        int fiu=v[pz][i];
        long long cmpz=mxsub[pz];
        long long cmf=mxsub[fiu];
        long long cdpz=dp[pz];
        long long cdf=dp[fiu];


        if(i==mx1 && v[pz].size()>1)
            mxsub[pz]=max(h[v[pz][mx2]],mxsub[v[pz][mx2]]);
        else if(v[pz].size()>1)
            mxsub[pz]=max(h[v[pz][mx1]],mxsub[v[pz][mx1]]);
        else
            mxsub[pz]=0;

        mxsub[fiu]=max(mxsub[fiu],max(mxsub[pz],h[pz]));

        dp[pz]=s-dp[fiu]+max(0LL,h[pz]-mxsub[pz]);

        dp[fiu]=dp[fiu]-max(0LL,h[fiu]-cmf)+dp[pz]+max(0LL,h[fiu]-mxsub[fiu]);

        dfs(fiu,pz);

        mxsub[pz]=cmpz;
        mxsub[fiu]=cmf;
        dp[pz]=cdpz;
        dp[fiu]=cdf;

    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,q,i,k,m,j=0,n,s=0,tt;
    t=1; /// finally no t
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>h[i];
        for(i=1;i<n;++i)
        {
            int a,b;
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        dfsinit(1,-1);
        ans=dp[1]+max(mxsub[1],h[1]);
        dfs(1,-1);
        cout<<ans;
    }
    return 0;
}