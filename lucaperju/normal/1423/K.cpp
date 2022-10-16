#include <bits/stdc++.h>
using namespace std;
int ciur[1000006];
struct ura
{
    int n,pz,rz;
}v[1000006];
bool cmp (ura a, ura b)
{
    return a.n<b.n;
}
bool cmp1 (ura a, ura b)
{
    return a.pz<b.pz;
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long t,i,j,k=0,n,q,m,ans=0,sx,sy,fx,fy;
    cin>>t;
    ciur[0]=ciur[1]=1;
    for(i=2;i*i<=1000000;++i)
    {
        if(!ciur[i])
        {
            for(j=i*i;j<=1000000;j+=i)
                ciur[j]=1;
        }
    }
    for(i=0;i<=1000000;++i)
    {
        ciur[i]=1-ciur[i];
        if(i)
            ciur[i]+=ciur[i-1];
    }
    for(i=1;i<=t;++i)
    {
        cin>>n;
        v[i].pz=i;
        v[i].n=n;
    }
    sort(v+1,v+t+1,cmp);
    j=1;
    for(i=1;i<=t;++i)
    {
        while(j*j<=v[i].n)
            ++j;
        v[i].rz=ciur[v[i].n]-ciur[j-1]+1;
    }
    sort(v+1,v+t+1,cmp1);
    for(i=1;i<=t;++i)
        cout<<v[i].rz<<'\n';
    return 0;
}