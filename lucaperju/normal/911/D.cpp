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
int v[1505];
int main()
{
    long long a,b,nrca,nrcb,n,i,j,c,ca,cb,mx=-9999999999,mn=9999999999,s=0,k,x,y,z,nra,nrb,ok,poz,cur=0,m;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i];
    for(i=1;i<=n;++i)
        for(j=i+1;j<=n;++j)
            if(v[j]<v[i])
                ++cur;
    cur%=2;
    cin>>m;
    for(i=1;i<=m;++i)
    {
        cin>>a>>b;
        a=(b-a+1);
        a=a*1LL*(a-1)/2;
        a=a%2;
        cur+=a;
        cur%=2;
        if(cur==1)
            cout<<"odd"<<'\n';
        else
            cout<<"even"<<'\n';
    }
    return 0;
}