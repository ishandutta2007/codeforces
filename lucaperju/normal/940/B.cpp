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
    long long a,b,nrca,nrcb,n,i,j,c,ca,cb,mx=-9999999999,mn=9999999999,s=0,k;
    cin>>n>>k>>a>>b;
    if(k==1)
    {
        cout<<(n-1)*1LL*a;
        return 0;
    }
    while(n!=1)
    {
        if(!(n%k))
        {
            s+=min((n-n/k)*1LL*a,b);
            n/=k;
        }
        else
        {
            if(n<k)
            {
                s+=(n-1)*1LL*a;
                break;
            }
            s+=(n%k)*1LL*a;
            n-=n%k;
        }
    }
    cout<<s;
    return 0;
}