#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iomanip>
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
//long long v[100005];
int main()
{
    long long t,i,j=0,c,dif,ok,rad,s=0,x,k,jdr=1,s1=0,mx=0,d,a,b,y,m,cur,n,poz;
    double rez;
    cin>>n>>m;
    for(i=1;i<=m;++i)
    {
        cin>>a>>b;
        s+=a*1LL*n;
        if(b<0)
        {
            b=-b;
            cur=n/2;
            cur=cur*1LL*(cur+1)/2;
            s-=cur*1LL*b;
            cur=(n-1)/2;
            cur=cur*1LL*(cur+1)/2;
            s-=cur*1LL*b;
        }
        else
        {
            cur=n-1;
            cur=cur*1LL*(cur+1)/2;
            s+=cur*1LL*b;
        }
    }
    rez=s;
    cout<<setprecision(8)<<(double)rez/n;
    return 0;
}