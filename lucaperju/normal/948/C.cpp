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
long long  v[100005],s[100005],rez[100005],smn[100005];
int main()
{
    long long i,j,n,a,b,mx=-9999999999999,mn=9999999999999,k,pas;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i];
    for(i=1;i<=n;++i)
    {
        cin>>s[i];
        s[i]+=s[i-1];
    }
    for(i=1;i<=n;++i)
    {
        k=i-1;
        pas=1<<16;
        while(pas)
        {
            if(k+pas<=n && s[k+pas]-s[i-1]<=v[i])
                k+=pas;
            pas>>=1;
        }
        ++smn[i];
        --smn[k+1];
        rez[k+1]+=v[i]-(s[k]-s[i-1]);
    }
    for(i=1;i<=n;++i)
    {
        smn[i]+=smn[i-1];
        rez[i]+=smn[i]*(s[i]-s[i-1]);
        cout<<rez[i]<<' ';
    }
    return 0;
}