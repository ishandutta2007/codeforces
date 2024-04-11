#include <bits/stdc++.h>

using namespace std;
long long cmmdc (long long a, long long b)
{
    long long r;
    while(b)
    {r=a%b;a=b;b=r;}
    return a;
}
int main()
{
    long long i,j=0,n,pz=0,s=0,x,y,z,a,b,c,m,pr,cnt=0,mx=0,mxx=0,x1,y1,x2,y2,cx=0,cy=0,nr1=0,nr2=0;
    cin>>n>>m;
    if(n>m*1LL*(m-1))
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    a=1;
    b=2;
    for(i=1;i<=n;++i)
    {
        cout<<a<<' '<<b<<'\n';
        ++i;
        if(i>n)
            break;
        cout<<b<<' '<<a<<'\n';
        ++b;
        if(b>m)
        {
            b=a+1;
            a=b+1;
            swap(a,b);
        }
    }
}