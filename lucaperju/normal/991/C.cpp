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
bool verif (long long k, long long n)
{
    if(k>n/2LL)
        return true;
    long long cnt=0,cn=n;
    while(n>0)
    {
        cnt+=min(n,k);
        n-=k;
        n-=n/10LL;
    }
    if(cnt>=cn-cnt)
        return true;
    return false;
}
int main()
{
    long long n,pas=1LL<<55,k=0;
    cin>>n;
    while(pas)
    {
        if(!verif(k+pas,n))
            k+=pas;
        pas>>=1LL;
    }
    cout<<k+1;
    return 0;
}