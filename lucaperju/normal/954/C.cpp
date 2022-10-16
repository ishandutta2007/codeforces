#include <iostream>
#include <cstring>
using namespace std;
long long cmmdc(long long a,long long b)
{
    long long r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
long long lgput (long long cnt, long long mod,long long put)
{
    long long r=1,p=put;
    if(cnt==0)
        return 1;
    while(cnt>1)
    {
        if(!(cnt&1))
        {
            p=p*1LL*p%mod;
            cnt>>=1;
        }
        else
        {
            --cnt;
            r=r*1LL*p%mod;
        }
    }
    p=p*1LL*r;
    return p%mod;
}
/*
for(i=1;i<=n;++i)...
*/
long long v[200005];
int main()
{
    long long n,i,j,a,b=-1,c,x=1000000000,y,mx=-10000000000,ln,cl,lnp,clp;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i];
    for(i=2;i<=n;++i)
    {
        if(v[i]-v[i-1]!=1 && v[i]-v[i-1]!=-1)
        {
            a=v[i]-v[i-1];
            if(a<0)
                a=-a;
            if(a==0)
            {
                cout<<"NO";
                return 0;
            }
            if(b!=-1 && a!=b)
            {
                cout<<"NO";
                return 0;
            }
            if(b==-1)
                b=a;
        }
    }
    if(b==-1)
        b=1;
    for(i=2;i<=n;++i)
    {
        ln=(v[i]-1)/b+1;
        cl=(v[i]-1)%b+1;
        lnp=(v[i-1]-1)/b+1;
        clp=(v[i-1]-1)%b+1;
        if(ln-lnp!=0)
        {
            if(ln-lnp>1 || ln-lnp<-1 || cl-clp!=0)
            {
                cout<<"NO";
                return 0;
            }
        }
        if(cl-clp!=0)
        {
            if(cl-clp>1 || cl-clp<-1 || ln-lnp!=0)
            {
                cout<<"NO";
                return 0;
            }
        }
    }
    cout<<"YES\n"<<x<<' '<<b;
    return 0;
}