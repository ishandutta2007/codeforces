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
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long q,h,n,k,s=0,t,i,j,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        long long x,y,a,b;
        cin>>a>>b>>x>>y;
        long long cnt=0;
        int da=1,db=1;
        while(1)
        {
            if(x==a || y==b)
                break;
            ++cnt;
            if(a+da>n || a+da<1)
            {
                da=-da;
            }
            if(b+db>m || b+db<1)
                db=-db;
            a+=da;
            b+=db;
        }
        cout<<cnt<<'\n';
    }
}