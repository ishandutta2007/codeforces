#include <bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
using namespace std;
const long long INF=100000000000000LL;
const long long mod=1000000007;
long long v[75],d[2][1050000],nri[100005];
bool prim (int val)
{
    if(val==1)
        return false;
    for(int i=2;i*i<=val;++i)
        if(val%i==0)
            return false;
    return true;
}
int mask_cur(int val)
{
    int rz=0,p=1;
    for(int i=2;i<=val;++i)
    {
        if(prim(i))
        {
            int cnt=0;
            while(val%i==0)
            {
                val/=i;
                ++cnt;
            }
            cnt%=2;
            rz=rz+p*cnt;
            p<<=1;
        }
    }
    return rz;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long pz,add=1,t,h,i,j,n,mn=10000030LL*10000030LL,k=0,mx=-999999999999LL,tot,m,obj,cnt=0,cnti=0,b2,a3,b3,a,b,ok=0;
    long long ra,rb,dv=-1,dv1=-1;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        int a;
        cin>>a;
        ++v[a];
    }
    nri[1]=1;
  //  nrp[1]=1;
    for(i=2;i<=100000;++i)
    {
        nri[i]=(nri[i-1]*2LL)%mod;
     //   nrp[i]=nri[i]%mod;
    }
    d[0][0]=1;
   // nrp[0]=1;
    for(i=1;i<=70;++i)
    {
        int mcr=mask_cur(i);
        int i1=i%2,i2=1-i1;
        for(int msk=0;msk<(1<<20);++msk)
        {
            int mpr=msk xor mcr;
            d[i1][msk]=((d[i2][mpr]%mod)*1LL*(nri[v[i]]%mod))%mod;
            if(v[i]!=0)
                d[i1][msk]=(d[i1][msk]+(d[i2][msk]*1LL*nri[v[i]])%mod)%mod;
            else
                d[i1][msk]=(d[i1][msk]+d[i2][msk])%mod;
        }
    }
    cout<<(d[0][0]-1+mod)%mod;
    return 0;
}