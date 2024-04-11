#include <bits/stdc++.h>

using namespace std;
long long cmmdc (long long a, long long b)
{
    long long r;
    while(b)
    {r=a%b;a=b;b=r;}
    return a;
}
char v[100005];
long long dst (long long x1, long long y1, long long x2, long long y2)
{
    return fabs(x1-x2)+fabs(y1-y2);
}
long long sp[100005][2];
int main()
{
    long long i,j=0,n,pz=-1,s=0,x,y,z,a,b,c,m,pr,cnt=0,mx=0,mxx=0,x1,y1,x2,y2,cx=0,cy=0;
    cin>>x1>>y1>>x2>>y2;
    cin>>n>>ws;
    cin>>v;
    if(x1==x2 && y1==y2)
    {
        cout<<0;
        return 0;
    }
    long long idk=dst(x1,y1,x2,y2);
    long long idkk=0;
    for(i=0;i<n;++i)
    {
        if(idk-idkk<=0)
            break;
        ++idkk;
        if(v[i]=='U')
            ++cy,++sp[i][0];
        if(v[i]=='D')
            --cy,--sp[i][0];
        if(v[i]=='R')
            ++cx,++sp[i][1];
        if(v[i]=='L')
            --cx,--sp[i][1];
        sp[i][0]+=sp[i-1][0];
        sp[i][1]+=sp[i-1][1];
        idk=dst(x1+cx,y1+cy,x2,y2);
    }
    if(idk-idkk<=0)
    {
        cout<<idkk;
        return 0;
    }
    long long init=dst(x1,y1,x2,y2);
    long long sec=dst(x1+cx,y1+cy,x2,y2);
    long long add=init-sec;
    add+=n;
    if(add<=0)
    {
        cout<<-1;
        return 0;
    }
    long long pas=1LL<<50;
    long long k=0,ck;
    while(pas)
    {
        ck=k+pas;
        long long cur=(ck-1)/n;
        long long cx1=x1,cy1=y1;
        cx1+=cx*1LL*cur;
        cy1+=cy*1LL*cur;
        cur=(ck-1)%n;
        cx1+=sp[cur][1];
        cy1+=sp[cur][0];
        if(dst(cx1,cy1,x2,y2)-ck>0)
            k+=pas;
        pas>>=1LL;
    }
    if(k==(1LL<<51)-1)
    {
        cout<<-1;
        return 0;
    }
    cout<<k+1;
   /* long long cur=init/add;
    s=s+cur*1LL*n;
    long long rst=init%add;
    x1=x1+cx*1LL*cur;
    y1=y1+cy*1LL*cur;
    long long curr=dst(x1,y1,x2,y2)-cur*1LL*n;
    long long curi=cur;
    cur=0;
    for(i=0;i<n;++i,++s)
    {
        if(curr-cur<=0)
            break;
        ++cur;
        if(v[i]=='U')
            ++y1;
        if(v[i]=='D')
            --y1;
        if(v[i]=='R')
            ++x1;
        if(v[i]=='L')
            --x1;
        curr=dst(x1,y1,x2,y2)-curi*1LL*n;
    }*/
}