#include <iostream>
#include <cstring>
#include <cmath>
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
bool a[1000006],b[1000006];
int main()
{
    long long n,m,t,i,j=1,ca,cb,mx=-99999999999999LL,mn=999999999999LL,s=0,k,x,y,z,ok=1,cur,cn,cnt=0,q;
    char c;
    cin>>n>>ws;
    for(i=1;i<=n;++i)
    {
        cin>>c;
        a[i]=c-'0';
    }
    for(i=1;i<=n;++i)
    {
        cin>>c;
        b[i]=c-'0';
    }
    for(i=1;i<=n;++i)
    {
        if(a[i]!=b[i])
        {
            ++cnt;
            if(a[i]==b[i+1] && b[i]==a[i+1])
                a[i+1]=b[i+1];
        }
    }
    cout<<cnt;
    return 0;
}