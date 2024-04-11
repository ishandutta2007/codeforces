#include <bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
using namespace std;
const long long mod=4910294125910LL;
long long cmmdc (long long a, long long b)
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
double codif (long long x1, long long y1, long long x2, long long y2)
{
    long long catx=x2-x1,caty=y2-y1,rx1,rx2,ry1,ry2;
    long long val=cmmdc(catx,caty);
    double rez;
    if(caty==0)
        rez=-6182093;
    else
    rez=(double)catx/caty;
    return rez;
}
long long codif1 (long long x1, long long y1, long long x2, long long y2)
{
    long long catx=x2-x1,caty=y2-y1,rx1,rx2,ry1,ry2;
    long long val=cmmdc(catx,caty);
    catx/=val;
    caty/=val;
    long long pas=1<<14;
    rx1=x1;
    ry1=y1;
    while(pas)
    {
        if(fabs(rx1+catx*1LL*pas)<=10000 && fabs(ry1+caty*1LL*pas)<=10000)
            rx1+=catx*1LL*pas,ry1+=caty*1LL*pas;
        pas>>=1;
    }
    rx2=x2;
    ry2=y2;
    pas=1<<14;
    while(pas)
    {
        if(fabs(rx2-catx*1LL*pas)<=10000 && fabs(ry2-caty*1LL*pas)<=10000)
            rx2-=catx*1LL*pas,ry2-=caty*1LL*pas;
        pas>>=1;
    }
    if(rx1>rx2 || rx1==rx2 && ry1>ry2)
    {
        swap(rx1,rx2);
        swap(ry1,ry2);
    }
    rx1+=10002LL;
    rx2+=10002LL;
    ry1+=10002LL;
    ry2+=10002LL;
    long long rez=rx1;
    rez=rez*7522LL;
    rez%=mod;
    rez=rez+ry1;
    rez=rez*9253LL;
    rez%=mod;
    rez=rez+rx2;
    rez=rez*1520LL;
    rez=rez+ry2;
    rez%=mod;
    return rez;
}
map <double,long long>mp;
map <long long,long long>mp1;
long long a[1003],b[1003];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long m,pz=1,k,add=1,i,j,cnt=0,cnti=0,s=0,n,cnt2=0,cn=0;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>a[i]>>b[i];
    for(i=1;i<=n;++i)
    {
        for(j=i+1;j<=n;++j)
        {
            double x=codif(a[i],b[i],a[j],b[j]);
            long long xx=codif1(a[i],b[i],a[j],b[j]);
            if(!mp1[xx])
                cnt=cnt+mp[x];
            if(!mp1[xx])
                ++cn;
            if(!mp1[xx])
                mp[x]++;
            ++mp1[xx];
        }
    }
    s=s+cn*1LL*(cn-1LL)/2LL;
    cout<<max(s-cnt,0LL);
    return 0;
}