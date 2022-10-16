#include <bits/stdc++.h>
using namespace std;
long long v[3][100005],na,nb,nc,sz[3];
long long get (long long tip, long long val)
{
    long long pas=1<<17,k=0;
    while(pas)
    {
        if(k+pas<=sz[tip] && v[tip][k+pas]<val)
            k+=pas;
        pas>>=1LL;
    }
    return v[tip][min(sz[tip],k+1)];
}
long long get1 (long long tip, long long val)
{
    long long pas=1<<17,k=0;
    while(pas)
    {
        if(k+pas<=sz[tip] && v[tip][k+pas]<val)
            k+=pas;
        pas>>=1LL;
    }
    return v[tip][max(k,1LL)];
}
unsigned long long getsum (long long x,long long y,long long z)
{
    return (x-y)*(x-y)+(y-z)*(y-z)+(x-z)*(x-z);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long i,j,mx=0,s=0,ok,n;
    long long k=0,t,d;
    cin>>t;
    while(t--)
    {
        cin>>na>>nb>>nc;
        sz[0]=na;
        sz[1]=nb;
        sz[2]=nc;
        for(i=1;i<=na;++i)
            cin>>v[0][i];
        for(i=1;i<=nb;++i)
            cin>>v[1][i];
        for(i=1;i<=nc;++i)
            cin>>v[2][i];
        sort(v[0]+1,v[0]+na+1);
        sort(v[1]+1,v[1]+nb+1);
        sort(v[2]+1,v[2]+nc+1);
        unsigned long long rz=1LL<<63;
        for(i=1;i<=na;++i)
        {
            rz=min(rz,getsum(v[0][i],get(1,v[0][i]),get(2,v[0][i])));
            rz=min(rz,getsum(v[0][i],get1(1,v[0][i]),get(2,v[0][i])));
            rz=min(rz,getsum(v[0][i],get(1,v[0][i]),get1(2,v[0][i])));
            rz=min(rz,getsum(v[0][i],get1(1,v[0][i]),get1(2,v[0][i])));
        }
        for(i=1;i<=nb;++i)
        {
            rz=min(rz,getsum(v[1][i],get(0,v[1][i]),get(2,v[1][i])));
            rz=min(rz,getsum(v[1][i],get1(0,v[1][i]),get(2,v[1][i])));
            rz=min(rz,getsum(v[1][i],get(0,v[1][i]),get1(2,v[1][i])));
            rz=min(rz,getsum(v[1][i],get1(0,v[1][i]),get1(2,v[1][i])));
        }
        for(i=1;i<=nc;++i)
        {
            rz=min(rz,getsum(v[2][i],get(1,v[2][i]),get(0,v[2][i])));
            rz=min(rz,getsum(v[2][i],get1(1,v[2][i]),get(0,v[2][i])));
            rz=min(rz,getsum(v[2][i],get(1,v[2][i]),get1(0,v[2][i])));
            rz=min(rz,getsum(v[2][i],get1(1,v[2][i]),get1(0,v[2][i])));
        }
        cout<<rz<<'\n';
    }
    return 0;
}