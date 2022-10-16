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
long long v[200005],fvx[200005];
int main()
{
    long long a,b,nrca,nrcb,n,i,j,ca,cb,mx=9999999999,mn=9999999999,s=0,k,x,y,z,nr0=0,nrb,ok=0,poz,cur=0,m,cn,cnt=0;
    cin>>n;
    if(n<=10)
    {
        if(n<=5)
            cout<<0;
        else
            cout<<10;
        return 0;
    }
    if(n%10<=5)
        cout<<n/10<<0;
    else
        cout<<(n/10)+1<<0;
    return 0;
}