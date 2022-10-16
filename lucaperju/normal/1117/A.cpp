#include <bits/stdc++.h>

using namespace std;
long long cmmdc (long long a, long long b)
{
    long long r;
    while(b)
    {r=a%b;a=b;b=r;}
    return a;
}
long long v[100005];
int main()
{
    long long i,j=0,n,k=0,pz=-1,s=0,x,y,z,a,b,c,m,pr,cnt=0,mx=0,mxx=0;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        mxx=max(mxx,v[i]);
    }
    for(i=1;i<=n;++i)
    {
        if(v[i]==v[i-1])
            ++cnt;
        else
            cnt=1;
        if(v[i]==mxx)
        mx=max(mx,cnt);
    }
    cout<<mx;
}