#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
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
for(i=1;i<=n;++i)
*/
int main()
{
    long long i,j,n,a,b,mx=-9999999999999,mn=9999999999999,k=9,s=0;
    cin>>n;
    if(n<5)
    {
        cout<<n*(n-1)/2;
        return 0;
    }
    a=5;
    while(n>=a)
        a*=10,k=k*10+9;
    k/=10;
    a/=5;
    for(i=0;i<9;++i)
    {
        b=a*1LL*i+k;
        if(n>b)
            s+=b/2;
        else if(n>=b/2)
            s+=min(n-b/2,b/2);
        else
            break;
    }
    cout<<s;
    return 0;
}