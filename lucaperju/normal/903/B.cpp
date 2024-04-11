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
int v[50005];
int main()
{
    long long t,i,j=0,n,a,b,c,dif,ok,rad,s=0,x,k,jdr=1,s1=0,mx,h1,a1,h2,a2,c1;
    cin>>h1>>a1>>c1>>h2>>a2;;
    while(h2>0)
    {
        if(a2>=h1 && a1<h2)
        {
            h1+=c1;
            h1-=a2;
            v[++j]=0;
        }
        else
        {
            h1-=a2;
            h2-=a1;
            v[++j]=1;
        }
    }
    cout<<j<<'\n';
    for(i=1;i<=j;++i)
    {
        if(v[i]==0)
            cout<<"HEAL\n";
        else
            cout<<"STRIKE\n";
    }
    return 0;
}