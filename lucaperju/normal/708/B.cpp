#include <bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
using namespace std;
const long long INF=100000000000000LL;
int v[200003];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long pz,add=1,t,i,j,mn=10000030LL*10000030LL,k=0,mx=-999999999999LL,tot,n,m,obj,cnt=0,cnti=0,b2,a3,b3,ok=0,rz=0,val;
    long long ra,rb,dv=-1,dv1=-1;
    long long a00,a01,a10,a11;
    cin>>a00>>a01>>a10>>a11;
    long long nr0=-1,nr1=-1,nrt=-1;
    for(i=1;i<=200000;++i)
    {
        if(i*1LL*(i-1)/2LL==a00)
            nr0=i;
        if(i*1LL*(i-1)/2LL==a11)
            nr1=i;
        if(i*1LL*(i-1)/2LL==a00+a01+a10+a11)
            nrt=i;
    }
    if(a00==0 && a01==0 && a10==0)
    {
        if(nr1!=-1)
        {
            for(i=1;i<=nr1;++i)
                cout<<1;
        }
        else
            cout<<"Impossible";
        return 0;
    }
    if(a11==0 && a01==0 && a10==0)
    {
        if(nr0!=-1)
        {
            for(i=1;i<=nr0;++i)
                cout<<0;
        }
        else
            cout<<"Impossible";
        return 0;
    }
    if(nr1==-1 || nr0==-1 || nrt==-1 || nr0+nr1!=nrt)
    {
        cout<<"Impossible";
        return 0;
    }
    for(i=1;i<=nr0;++i)
        v[i]=0;
    n=nrt;
    for(;i<=n;++i)
        v[i]=1;
    pz=nr0+1;
    while(a10)
    {
        if(a10>=nr0)
        {
            v[pz++]=-1;
            ++cnt;
            a10-=nr0;
            continue;
        }
        v[nr0+cnt+1]=v[nr0];
        --a10;
        for(i=nr0-1;i>=1 && a10;--i,--a10)
            v[i+1]=v[i];
        v[i+1]=1;
    }
    for(i=1;i<=cnt;++i)
        cout<<1;
    for(i=1;i<=n;++i)
    {
        if(v[i]!=-1)
            cout<<v[i];
    }
    return 0;
}