#include <bits/stdc++.h>
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
    else if(cnt<0)
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
int v[300005];
map <int,int>mp;
int main()
{
    ios_base::sync_with_stdio (0);
    long long l=0,r=0,n,t,i,j=0,ca,cb,mn=999999999999LL,mx=-10000000,mn1=9999999999,s=0,pzx,pzn,k,x,y,z,cur,cn,cnt=0,q,cj,ok=1,ci,m;
    cin>>n>>m;
    if(n>m)
        swap(n,m);
    if(n==1)
    {
        cout<<m-m%6+max((m%6-3)*2,0LL);
    }
    else
    if(n==2)
    {
        if(m==2)
            cout<<0;
        else
        if(m==3)
            cout<<4;
        else
        if(m==7)
            cout<<12;
        else
            cout<<m*2;
    }
    else
    {
        if(n%2==1 && m%2==1)
            cout<<n*1LL*m-1;
        else
            cout<<n*1LL*m;
    }
    return 0;
}