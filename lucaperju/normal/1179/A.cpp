#include <bits/stdc++.h>
using namespace std;
const long long mod=(1e9)+7;
int v[200005];
int rza[100005],rzb[100005];
int main ()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n,m,ta,tb,i,j,nrc=0,nrd=0,s=0,t,ok=0,a,b,c,d,rz=1,q,mx=-1,pz,k=0;
    cin>>n>>q;
    for(i=1;i<=n;++i)
        cin>>v[i];
    for(i=1;i<=n;++i)
    {
        if(v[i]>mx)
            mx=v[i],pz=i;
    }
    i=1;
    j=2;
    while(j<=pz)
    {
        rza[++k]=v[i];
        rzb[k]=v[j];
        if(v[i]>v[j])
            v[n+k]=v[j],++j;
        else
        {
            v[n+k]=v[i];
            i=j;
            ++j;
        }
    }
    while(q--)
    {
        cin>>a;
        if(a<=pz-1)
            cout<<rza[a]<<' '<<rzb[a]<<'\n';
        else
        {
            a-=(pz-1);
            cout<<mx<<' '<<v[(a-1)%(n-1)+1+pz]<<'\n';
        }
    }
    return 0;
}