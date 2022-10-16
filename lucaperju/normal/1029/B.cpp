#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
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
int v[200005];
int main()
{
    long long n,t,i,j=1,ca,cb,mx=-99999999999999LL,mn=999999999999LL,s=0,k,x,y,z,ok=1,cur,cn,cnt=0,q,cj;
    cin>>n>>v[1];
    cur=mx=1;
    for(i=2;i<=n;++i)
    {
        cin>>v[i];
        if(v[i]>2*v[i-1])
            cur=1;
        else
            cur++;
        if(cur>mx)
            mx=cur;
    }
    cout<<mx;
    return 0;
}