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
vector<int>v[200005];
vector<int>cst[200005];
long long dep[200005],stramos[20][200005],sum[20][200005],smn[200005],val[200005];
long long tt[200005];
void dfsinit (int pz, int t)
{
    stramos[0][pz]=t;
    sum[0][pz]=dep[pz]-dep[t];
    for(int i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]==t)
            continue;
        dep[v[pz][i]]=cst[pz][i]+dep[pz];
        dfsinit(v[pz][i],pz);
    }
}
void dfsfinal (int pz)
{
    for(int i=0;i<v[pz].size();++i)
        dfsfinal(v[pz][i]);
    smn[tt[pz]]+=smn[pz];
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,q,i,k,m,j=0,n,p,z;
    //cin>>t;
    t=1;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>val[i];
        for(i=2;i<=n;++i)
        {
            int a,b;
            cin>>a>>b;
            tt[i]=a;
            v[a].push_back(i);
            cst[a].push_back(b);
        }
        dfsinit(1,1);
        for(int put=1;put<=18;++put)
        {
            for(i=1;i<=n;++i)
            {
                stramos[put][i]=stramos[put-1][stramos[put-1][i]];
                sum[put][i]=sum[put-1][i]+sum[put-1][stramos[put-1][i]];
            }
        }
        for(i=1;i<=n;++i)
        {
            long long nc=i,sc=0;
            for(int put=18;put>=0;--put)
            {
                if(sc+sum[put][nc]<=val[i])
                {
                    sc+=sum[put][nc];
                    nc=stramos[put][nc];
                }
            }
            ++smn[tt[i]];
            --smn[tt[nc]];
        }
        dfsfinal(1);
        for(i=1;i<=n;++i)
            cout<<smn[i]<<' ';
    }
    return 0;
}