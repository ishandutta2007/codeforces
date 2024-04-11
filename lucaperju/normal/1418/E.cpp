#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long lgput (long long a, long long exp)
{
    long long rz=1;
    while(exp)
    {
        if(exp&1LL)
        {
            rz=rz*1LL*a%mod;
            --exp;
        }
        else
        {
            exp>>=1LL;
            a=a*1LL*a%mod;
        }
    }
    return rz;
}
long long sp[200005];
long long v[200005];
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long t,i,j,k,n,q,rz=0,m;
    cin>>n>>q;
    for(i=1;i<=n;++i)
        cin>>v[i];
    sort(v+1,v+n+1);
    for(i=1;i<=n;++i)
        sp[i]=(sp[i-1]+v[i])%mod;
    for(i=1;i<=q;++i)
    {
        rz=0;
        long long a,b;
        cin>>a>>b;
        int pas=1<<20;
        k=0;
        while(pas)
        {
            if(k+pas<=n && v[k+pas]<b)
                k+=pas;
            pas>>=1LL;
        }
        int nrm=n-k;
        if(nrm<a)
        {
            cout<<rz<<'\n';
            continue;
        }
        rz=(rz+(sp[k]*1LL*(nrm-a+1))%mod*1LL*lgput(nrm+1,mod-2)%mod)%mod;
        --nrm;
        if(nrm<a)
        {
            cout<<rz<<'\n';
            continue;
        }
        rz=(rz+((sp[n]-sp[k]+mod)%mod*1LL*(nrm-a+1))%mod*1LL*lgput(nrm+1,mod-2)%mod)%mod;
        cout<<rz<<'\n';
    }
    return 0;
}