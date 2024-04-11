#include <iostream>
#include <cstring>
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
for(i=1;i<=n;++i)...
*/
int v[100003];
int main()
{
    long long n,i,j=-2,a,b,c,cat=0,cat1=0,mx=-99999999999,mn=99999999999,catmn=0,catmx=0;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        if(v[i]>mx)
            mx=v[i];
        if(v[i]<mn)
            mn=v[i];
    }
    if(mx-mn==0 || mx-mn==1)
    {
        cout<<n<<'\n';
        for(i=1;i<=n;++i)
            cout<<v[i]<<' ';
    }
    else
    {
        for(i=1;i<=n;++i)
        {
            if(v[i]==mx-1)
                ++cat;
            else
            if(v[i]==mn)
                ++catmn;
            else
                ++catmx;
        }
        if(cat<min(catmn,catmx)*2)
        {
            cat=min(catmn,catmx)*2;
            cout<<n-(cat/2)*2<<'\n';
            cat=(cat/2)*2;
            cat1=cat;
            cat/=2;
            cat1/=2;
            for(i=1;i<=n;++i)
            {
                if(v[i]==mx && cat)
                {
                    cout<<mx-1<<' ';
                    --cat;
                }
                else
                if(v[i]==mn && cat1)
                {
                    cout<<mx-1<<' ';
                    --cat1;
                }
                else
                    cout<<v[i]<<' ';
            }
        }
        else
        {
            cout<<n-(cat/2)*2<<'\n';
            cat=cat1=cat/2;
            for(i=1;i<=n;++i)
            {
                if(v[i]==mx-1 && cat)
                {
                    cout<<mn<<' ';
                    --cat;
                }
                else
                if(v[i]==mx-1 && cat1)
                {
                    cout<<mx<<' ';
                    --cat1;
                }
                else
                    cout<<v[i]<<' ';
            }
        }
    }
    return 0;
}