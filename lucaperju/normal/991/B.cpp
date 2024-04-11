#include <iostream>
#include <algorithm>
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
long long v[105];
int main()
{
    long long n,s=0,cnt=0;
    double rez;
    cin>>n;
    rez=(double)4.5*n;
    for(int i=1;i<=n;++i)
        cin>>v[i],s+=v[i];
    sort(v+1,v+n+1);
    for(int i=1;i<=n;++i)
    {
        if(s>=rez)
            break;
        else
        {
            s+=5-v[i];
            ++cnt;
        }
    }
    cout<<cnt;
    return 0;
}