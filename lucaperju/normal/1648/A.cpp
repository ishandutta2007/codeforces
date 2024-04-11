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
vector<int>v[100003];
long long idk[100003],cnt[100003];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,q,x,i,y,k,m,j=0,n,tt,p,s=0;
   // cin>>t;
    t=1;
    while(t--)
    {
        cin>>n>>m;
        for(i=1;i<=n;++i)
        {
            v[i].resize(m+2);
            for(j=1;j<=m;++j)
                cin>>v[i][j];
        }
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=m;++j)
            {
                s=s+cnt[v[i][j]]*1LL*i-idk[v[i][j]];
            }
            for(j=1;j<=m;++j)
            {
                ++cnt[v[i][j]];
                idk[v[i][j]]+=i;
            }
        }
        for(i=1;i<=100000;++i)
            idk[i]=cnt[i]=0;
        for(j=1;j<=m;++j)
        {
            for(i=1;i<=n;++i)
            {
                s=s+cnt[v[i][j]]*1LL*j-idk[v[i][j]];
            }
            for(i=1;i<=n;++i)
            {
                ++cnt[v[i][j]];
                idk[v[i][j]]+=j;
            }
        }
        cout<<s;
    }
    return 0;
}