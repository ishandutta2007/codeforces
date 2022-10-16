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
long long ciur [1000006];
int main()
{
    long long i,j,n,a,b,mx=-9999999999999,mn=9999999999999,k,pas;
    cin>>n;
    ciur[0]=ciur[1]=1;
    for(i=2;i<=1000000;++i)
        if(!ciur[i])
        {
            for(j=i*2;j<=1000000;j+=i)
                ciur[j]=i;
            ciur[i]=1;
        }
    if(ciur[n]==1)
    {
        cout<<n;
        return 0;
    }
    for(i=2;i<=n;++i)
    {
        if(ciur[i]==1 && n%i==0)
            mx=i;
    }
    for(i=n-mx+1;i<n;++i)
    {
        if(i-ciur[i]+1<mn)
            mn=i-ciur[i]+1;
    }
    cout<<mn;
    return 0;
}