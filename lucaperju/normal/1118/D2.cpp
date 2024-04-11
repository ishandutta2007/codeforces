#include <bits/stdc++.h>

using namespace std;
long long cmmdc (long long a, long long b)
{
    long long r;
    while(b)
    {r=a%b;a=b;b=r;}
    return a;
}
long long v[200005];
long long verif (long long val, long long n)
{
    long long i,j,ad=n%val,x=n/val,cr=0,s=0;
    --x;
    for(i=1;i<=n;++i)
    {
        if(i<=ad)
        {
            s=s+max(0LL,v[i]-x-1);
            continue;
        }
        ++cr;
        if(cr<=val)
            s=s+max(0LL,v[i]-x);
        else
        {
            cr=1,--x;
            s=s+max(0LL,v[i]-x);
        }
    }
    return s;
}
int main()
{
    long long i,j=0,n,pz=0,s=0,x,y,z,a,b,c,m,pr,cnt=0,mx=0,mxx=0,x1,y1,x2,y2,cx=0,cy=0,nr1=0,nr2=0;
    cin>>n>>m;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        s+=v[i];
    }
    sort(v+1,v+n+1);
    if(s<m)
    {
        cout<<-1;
        return 0;
    }
    long long pas=1<<22;
    long long k=0;
    while(pas)
    {
        if(k+pas<=n && verif(k+pas,n)<m)
            k+=pas;
        pas>>=1;
    }
    cout<<k+1;
}