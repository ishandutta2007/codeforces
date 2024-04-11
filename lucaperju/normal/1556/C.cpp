#include <bits/stdc++.h>

using namespace std;

/*
long long mod = 1000000007;
long long fct[400005],invfct[400005],inv[400005];
long long put2[400005];
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
long long cmb (long long n, long long k)
{
    if(n<k || k<0 || n<0)
        return 0;
    return fct[n]*1LL*invfct[k]%mod*1LL*invfct[n-k]%mod;
}
void init ()
{
    inv[1]=fct[0]=fct[1]=invfct[0]=invfct[1]=put2[0]=1,put2[1]=2;
    for(long long i=2;i<=400000;++i)
        put2[i]=put2[i-1]*2LL%mod,inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod,fct[i]=i*1LL*fct[i-1]%mod,invfct[i]=inv[i]*1LL*invfct[i-1]%mod;
}
*/
long long v[1003];
long long sp[1003];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,i,j,m,q,k,n;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i];
    for(i=1;i<=n;++i)
        sp[i]=v[i]-sp[i-1];
    unsigned long long ans=0;
    for(i=1;i<=n;i+=2)
    {
        long long sc=0;
        long long need=1;
        for(j=i+1;j<=n;++j)
        {
            if(j%2==0)
            {
                ///a e in [ need , v[i] ]
                ///b e in [ need+sc , v[j] ]
                ans=ans+max(0LL,min(v[i]-need+1,v[j]-need-sc+1));
                sc=sc-v[j];
                need=max(need,-sc);
            }
            else
            {
                sc=sc+v[j];
            }
        }
    }
    cout<<ans;
    return 0;
}