#include <iostream>
using namespace std;
/*long long cmmdc(long long a,long long b)
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
}*/
const int mod=998244353;
int v[1000006];
int main()
{
    long long i,s,a,cur,n;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i];
    s=v[n];
    cur=1;
    for(i=n-1;i>=1;--i)
    {
        a=(long long)cur*(n-i);
        cur=cur*2LL%mod;
        a=(a+cur)%mod;
        s+=(long long)(a*v[i])%mod;
    }
    cout<<s%mod;
    return 0;
}