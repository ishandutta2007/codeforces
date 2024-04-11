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
const long long mod = 1000000007;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,i,k,m,j=0,tt,p,n;
    cin>>t;
    while(t--)
    {
        long long a,b,c,x,y,z;
        cin>>a>>b>>c>>x>>y>>z;
        if(y%b!=0)
        {
            cout<<"0\n";
            continue;
        }
        if((x-a)%b!=0)
        {
            cout<<"0\n";
            continue;
        }
        --z;
        --c;
        if(x<a || x+y*1LL*z>a+b*1LL*c)
        {
            cout<<"0\n";
            continue;
        }
        if(x-y<a || x+y*1LL*(z+1LL)>a+b*1LL*c)
        {
            cout<<"-1\n";
            continue;
        }
        long long s=0;
        for(i=1;i*i<=y;++i)
        {
            if(y%i==0LL && i*1LL*b/__gcd(i,b)==y)
            {
                s=(s+(y/i)*1LL*(y/i)%mod)%mod;
            }
            long long ci=i;
            if(i==y/i)
                continue;
            i=y/i;
            if(y%i==0LL && i*1LL*b/__gcd(i,b)==y)
            {
                s=(s+(y/i)*1LL*(y/i)%mod)%mod;
            }
            i=ci;
        }
        cout<<s<<'\n';
    }
    return 0;
}