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
int main()
{
    long long i,j=0,n,k=0,pz=-1,s=0,x,y,z,a,b,c,m,pr,cnt=0,mx=0;
    cin>>n>>m>>k;
    for(i=1;i<=n;++i)
        cin>>v[i];
    sort(v+1,v+n+1);
    ++k;
    s=v[n-1]*1LL*(m/k);
    m-=m/k;
    s+=v[n]*1LL*m;
    cout<<s;
}