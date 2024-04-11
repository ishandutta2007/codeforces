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
bool ciur[100005];
void makeciur ()
{
    int i,j;
    ciur[1]=ciur[0]=1;
    for(i=2; i<=100000; ++i)
        if(!ciur[i])
            for(j=i*i; j<=100000; ++j)
                ciur[j]=1;
}
bool vn_patrat (int n, int m)
{
    int i,j,s=0;
    for(i=1; i<=n; ++i)
        for(j=i+1; j<=n; ++j)
            if(cmmdc(i,j)==1)
            {
                ++s;
                if(s>=m)
                    return true;
            }
    return false;
}
bool verif (int n, int m)
{
    if(m<n-1)
        return false;
    if(n<=1000)
        if(vn_patrat(n,m))
            return true;
        else
            return false;
    return true;
}
void rzn2 (int n, int m)
{
    int i,j,s=0;
    for(i=2; i<=n; ++i)
        for(j=i+1; j<=n; ++j)
            if(cmmdc(i,j)==1)
            {
                ++s;
                if(s>m)
                    return;
                cout<<i<<' '<<j<<'\n';
            }
}
void rez (int n, int m)
{
    int i,j;
    cout<<"Possible\n";
    for(i=2; i<=n; ++i)
        cout<<1<<' '<<i<<'\n';
    m-=(n-1);
    rzn2(n,m);
    return;
    j=2;
    while(j<=100000 && m)
    {
        for(i=2; i<=n; ++i)
        {
            if(m)
                if(!i%j)
                {
                    cout<<j<<' '<<i<<'\n';
                    --m;
                }
                else
                    return;
        }
        ++j;
        while(ciur[j])
            ++j;
    }
    if(m)
    {
        for(i=2; i<=n; ++i)
            for(j=i+1; j<=n; ++j)
                if(cmmdc(i,j)==1 && ciur[i] && ciur[j])
                {
                    if(!m)
                        return;
                    cout<<i<<' '<<j<<'\n';
                }
    }
}
int main()
{
    long long t,i,j=0,c,dif,ok,rad,s=0,x,k,jdr=1,s1=0,mx=0,d,a,b,y,m,cur,n,poz;
    cin>>n>>m;
    makeciur(); /// bulaneala incoming
    if(verif(n,m))
        rez(n,m);
    else
        cout<<"Impossible";
    return 0;
}