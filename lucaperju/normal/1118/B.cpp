#include <bits/stdc++.h>

using namespace std;
long long cmmdc (long long a, long long b)
{
    long long r;
    while(b)
    {r=a%b;a=b;b=r;}
    return a;
}
int v[200005];
int sp[200005],sp1[200005];
int main()
{
    long long i,j=0,n,pz=-1,s=0,x,y,z,a,b,c,m,pr,cnt=0,mx=0,mxx=0,x1,y1,x2,y2,cx=0,cy=0,t;
    cin>>n;
    if(n==1)
    {
        cout<<1;
        return 0;
    }
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        if(i==1)
            sp[i]=v[i];
        else
            sp[i]=v[i]+sp[i-2];
    }
    for(i=n;i>=1;--i)
        sp1[i]=v[i]+sp1[i+2];
    if(sp1[2]==sp1[3])
        ++s;
    if(sp[n-1]==sp[n-2])
        ++s;
    for(i=2;i<n;++i)
    {
        if(sp[i-1]+sp1[i+2]==sp[i-2]+sp1[i+1])
            ++s;
    }
    cout<<s;
}