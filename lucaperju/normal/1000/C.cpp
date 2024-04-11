#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
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
struct pct
{
    long long crd,ok;
}v[4000005];
long long rez[2000005];
bool cmp (pct a, pct b)
{
    if(a.crd<b.crd)
        return true;
    if(a.crd>b.crd)
        return false;
    if(a.ok<b.ok)
        return true;
    return false;
}
int main()
{
    long long n,m,i,j=0,a,b,c,cat=0,cat1=0,mx=-99999999999,mn=99999999999,nrm=0,nrs=0,nrl=0,nrxs=0,nrxl=0,nrxxs=0,nrxxl=0,nrxxxs=0,nrxxxl=0;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>a>>b;
        v[++j].ok=0;
        v[j].crd=a;
        v[++j].ok=1;
        v[j].crd=b;
    }
    sort(v+1,v+n*2+1,cmp);
    cat=1;
    for(i=2;i<=2*n;++i)
    {
        rez[cat]+=v[i].crd-1LL-v[i-1].crd;
    /*    while(v[i].crd==v[i+1].crd && i<=2*n && v[i].ok==0)
        {
            ++i;
            ++cat;
        }
        if(v[i].crd==v[i-1].crd)
            rez[cat]++;
        while(v[i].crd==v[i+1].crd && i<=2*n && v[i].ok==1)
        {
            ++i;
            --cat;
        }*/
        if(v[i].ok==0)
            cat+=1LL,++rez[cat];
        else if(v[i].ok==1)
            cat-=1LL,++rez[cat+1LL];
    }
    rez[1]++;
    for(i=1;i<=n;++i)
        cout<<rez[i]<<' ';
    return 0;
}