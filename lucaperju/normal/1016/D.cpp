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
long long a[105],b[105],v[105][105];
int main()
{
    long long n,m,t,nrca,nrcb,i,j=1,ca,cb,mx=-99999999999999LL,mn=9999999999,s=0,k,x,y,z,nr0=0,nrb,ok=1,cur,cn,cnt=0,q,pred=0,oka=0,okb=0;
    cin>>n>>m;
    for(i=1;i<=n;++i)
        cin>>a[i];
    for(i=1;i<=m;++i)
        cin>>b[i];
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=m;++j)
        {
            v[i][j]=(long long)(a[i]&b[j]);
            a[i]-=(long long)v[i][j];
            b[j]-=(long long)v[i][j];
        }
    }
    ok=0;
    for(i=1;i<=n;++i)
    {
        if(a[i])
        {
            ++ok;
            oka=1;
            break;
        }
    }
    for(i=1;i<=m;++i)
    {
        if(b[i])
        {
            ++ok;
            okb=1;
            break;
        }
    }
 /*   if(ok==2)
    {
        cout<<"NO";
        return 0;
    }*/
    if(ok==0)
    {
        cout<<"YES\n";
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=m;++j)
                cout<<v[i][j]<<' ';
            cout<<'\n';
        }
        return 0;
    }
    if(oka)
    {
        for(i=1;i<=n;++i)
            s=(long long)(s xor a[i]);
        if(s==0)
            oka=0;
        else
        {
            cout<<"NO";
            return 0;
        }
        for(i=1;i<=n;++i)
            v[i][2]+=(long long)a[i];
        if(okb==0)
            cout<<"YES\n";
        if(okb==0)
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=m;++j)
                cout<<v[i][j]<<' ';
            cout<<'\n';
        }
    }
    if(okb)
    {
        for(i=1;i<=m;++i)
            s=(long long)(s xor b[i]);
        if(s==0 && oka==0)
            cout<<"YES\n";
        else
        {
            cout<<"NO";
            return 0;
        }
        for(i=1;i<=m;++i)
            v[2][i]+=(long long)b[i];
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=m;++j)
                cout<<v[i][j]<<' ';
            cout<<'\n';
        }
    }
    return 0;
}