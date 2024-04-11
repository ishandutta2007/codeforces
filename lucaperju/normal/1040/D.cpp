#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <time.h>
#include <stdlib.h>
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
int main()
{
    long long l,r,a,b,n,t,i,j=1,ca,cb,mx=-99999999999999LL,mn=999999999999LL,mx1=-10000000,mn1=9999999999,s=0,pzx,pzn,k,x,y,z,ok=1,cur,cn,cnt=0,q,cj;
    char cc;
    cin>>n>>k;
    l=1;
    r=n;
    srand(time(NULL));//-
    while(1)
    {
        while(r-l+1>k*4+3)
        {
            cout<<l<<' '<<(l+r)/2<<'\n';
            cout.flush();
            cin>>cc;
            if(cc=='N')
            {
                cin>>cc;
                l=(l+r)/2-k;
                r+=k;
            }
            else if (cc=='Y')
            {
                cin>>cc;
                cin>>cc;
                r=(l+r)/2+k;
                l-=k;
            }
      //      else if(cc=='B')
      //          return 0;
            r=min(r,n);
            l=max(1LL,l);
        }
        a=rand()%(r-l+1);
        cout<<l+a<<' '<<l+a<<'\n';
        cout.flush();
        cin>>cc;
        if(cc=='N')
        {
            cin>>cc;
            l-=k;
            r+=k;
        }
        else if (cc=='Y')
        {
            cin>>cc;
            cin>>cc;
            return 0;
        }
     //   else if(cc=='B')
     //       return 0
        r=min(r,n);
        l=max(1LL,l);
    }
    return 0;
}