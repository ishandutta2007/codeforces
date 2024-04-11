#include <bits/stdc++.h>
using namespace std;
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
long long fct[600005],invfct[600005],inv[600005];
long long put2[600005];
long long cmb (long long n, long long k)
{
    if(n<k || k<0 || n<0)
        return 0;
    return fct[n]*1LL*invfct[k]%mod*1LL*invfct[n-k]%mod;
}
void init ()
{
    inv[1]=fct[0]=fct[1]=invfct[0]=invfct[1]=put2[0]=1,put2[1]=2;
    for(long long i=2;i<=600000;++i)
        put2[i]=put2[i-1]*2LL%mod,inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod,fct[i]=i*1LL*fct[i-1]%mod,invfct[i]=inv[i]*1LL*invfct[i-1]%mod;
}
int v[600005];
int main()
{
    ios_base::sync_with_stdio(false);
    long long i,j,m,k=0,q,n;
    init();
    cin>>n>>m;
    for(i=1;i<=n;++i)
        cin>>v[i];
    long long s=0;
    for(i=1;i<=n;++i)
        s+=v[i];
    for(i=1;i<=n;++i)
        v[i+n]=v[i];
    if(s%2==1)
    {
        cout<<lgput(m,n);
        return 0;
    }
    s/=2;
    long long sc=0;
    j=0;
    int cnt=0;
    for(i=1;i<=n;++i)
    {
        while(sc<s)
            sc+=v[++j];
        if(sc==s)
            ++cnt;
        sc-=v[i];
    }
    cnt/=2;
    s=0;
    for(i=0;i<=cnt;++i)
    {
        long long a,b,c,d,e;
        a=cmb(cnt,i);
        b=cmb(m,i);
        c=fct[i];
        d=lgput((cmb(m-i,2)*2LL)%mod,cnt-i);
        e=lgput(n-cnt-cnt,m-i);
        s=(s+cmb(cnt,i)*1LL*cmb(m,i)%mod*1LL*fct[i]%mod*1LL*lgput((cmb(m-i,2)*2LL)%mod,cnt-i)%mod*1LL*lgput(m-i,n-cnt-cnt)%mod)%mod;
    }
    cout<<s;
    return 0;
}