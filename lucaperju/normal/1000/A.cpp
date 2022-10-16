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
char v[15];
int main()
{
    long long n,i,j=-2,a,b,c,cat=0,cat1=0,mx=-99999999999,mn=99999999999,nrm=0,nrs=0,nrl=0,nrxs=0,nrxl=0,nrxxs=0,nrxxl=0,nrxxxs=0,nrxxxl=0;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>v;
        if(v[0]=='M')
            ++nrm;
        else
        if(v[0]=='S')
            ++nrs;
        else
        if(v[0]=='L')
            ++nrl;
        else
        if(v[1]=='S')
            nrxs++;
        else
        if(v[1]=='L')
            ++nrxl;
        else
        if(v[2]=='S')
            ++nrxxs;
        else
        if(v[2]=='L')
            ++nrxxl;
        else
        if(v[3]=='S')
            ++nrxxxs;
        else
        if(v[3]=='L')
            ++nrxxxl;
    }
    for(i=1;i<=n;++i)
    {
        cin>>v;
        if(v[0]=='M')
            --nrm;
        else
        if(v[0]=='S')
            --nrs;
        else
        if(v[0]=='L')
            --nrl;
        else
        if(v[1]=='S')
            nrxs--;
        else
        if(v[1]=='L')
            --nrxl;
        else
        if(v[2]=='S')
            --nrxxs;
        else
        if(v[2]=='L')
            --nrxxl;
        else
        if(v[3]=='S')
            --nrxxxs;
        else
        if(v[3]=='L')
            --nrxxxl;
    }
    if(nrm>0)
//        cat-=nrm;
//    else
        cat+=nrm;
    if(nrs>0)
 //       cat-=nrs;
 //   else
        cat+=nrs;
    if(nrl>0)
  //      cat-=nrl;
 //   else
        cat+=nrl;
    if(nrxs>0)
  //      cat-=nrxs;
  //  else
        cat+=nrxs;
    if(nrxl>0)
 //       cat-=nrxl;
 //   else
        cat+=nrxl;
    if(nrxxs>0)
  //      cat-=nrxxs;
  //  else
        cat+=nrxxs;
    if(nrxxl>0)
 //       cat-=nrxxl;
 //   else
        cat+=nrxxl;
    if(nrxxxs>0)
 //       cat-=nrxxxs;
  //  else
        cat+=nrxxxs;
    if(nrxxxl>0)
 //       cat-=nrxxxl;
 //   else
        cat+=nrxxxl;
    cout<<cat;
    return 0;
}