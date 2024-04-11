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
char v[100005],fv[500];
int main()
{
    long long a,b,nrca,nrcb,n,i,j,c,ca,cb,mx=-9999999999,mn=9999999999,s=0,k;
    char val='z'+1,vlm='a'-1;
    cin>>n>>k>>v;
    for(i=0;i<n;++i)
    {
        ++fv[v[i]];
        if(v[i]<val)
            val=v[i];
        if(v[i]>vlm)
            vlm=v[i];
    }
    if(n<k)
    {
        for(i=0;i<n;++i)
            cout<<v[i];
        for(i=1;i<=k-n;++i)
            cout<<val;
        return 0;
    }
    for(i=k-1;i>0;--i)
        if(v[i]!=vlm)
            break;
    for(j=v[i]+1;j<='z';++j)
        if(fv[j])
            break;
    v[i]=j;
    for(++i;i<k;++i)
        v[i]=val;
    for(i=0;i<k;++i)
        cout<<v[i];
    return 0;
}