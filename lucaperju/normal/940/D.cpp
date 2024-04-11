#include <iostream>
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
int dist (int a, int b)
{
    if(a>b)
        return a-b;
    return b-a;
}
int v[100005];
char vc[100005]; ///mai bine il numeam wc
int main()
{
    long long a,b,nrca,nrcb,n,i,j,c,ca,cb,mx=-9999999999,mn=9999999999,s=0,sa=0,cur=0,cc,y,k,ok=0,pz,l=-1000000000LL,r=1000000000LL;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i];
    cin>>(vc+1);
    for(i=2;i<=n;++i)
    {
        if(vc[i]!=vc[i-1])
        {
            if(vc[i]=='1')
            {
                mx=-999999999999LL;
                for(j=i;j>=i-4;--j)
                    if(v[j]>mx)
                        mx=v[j];
                l=max(mx+1,l);
            }
            else
            {
                mx=999999999999LL;
                for(j=i;j>=i-4;--j)
                    if(v[j]<mx)
                        mx=v[j];
                r=min(mx-1,r);
            }
        }
    }
    cout<<l<<' '<<r;
    return 0;
}