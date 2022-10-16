#include <iostream>
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
    else
    if(cnt<0)
        return 0;
    while(cnt>1)
    {
        if(!(cnt&1))
        {
            p=p*1LL*p%mod;
            cnt>>=1LL;
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
int dist (int a, int b)
{
    if(a>b)
        return a-b;
    return b-a;
}
int main()
{
    long long a,b,nrca,nrcb,n,i,j,c,ca,cb,mx=-9999999999,mn=9999999999,s=0,sa=0,cur=0,cc,y,k,ok=0,pz;
    cin>>n>>k;
    for(i=1;i<=n;++i)
    {
        cin>>a;
        if(k%a==0)
        {
            if(k/a<mn)
                mn=k/a;
        }
    }
    cout<<mn;
    return 0;
}