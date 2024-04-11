#include <bits/stdc++.h>
using namespace std;
int cmmdc (int a, int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int va[1003],vb[1003],v[1003],cv[1003];
int main ()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n,m,ta,tb,i,j,nrc=0,nrd=0,s=0,t,a,b,c,rz=0,q,pz=-1,k1=0,k2=0,k=0,cnt=0,pas,idk=99999999;
    cin>>n>>m;
    for(i=1;i<=m;++i)
    {
        cin>>c>>a>>b;
        if(c==1)
            ++v[a],--v[b];
        else
            va[++k]=a,vb[k]=b;
    }
    for(i=1;i<n;++i)
        v[i]+=v[i-1];
    for(i=1;i<n;++i)
        if(v[i])
            v[i]=1;
    for(i=1;i<n;++i)
        cv[i]=cv[i-1]+v[i];
    for(i=1;i<=k;++i)
    {
        if(vb[i]-va[i]==cv[vb[i]-1]-cv[va[i]-1])
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES\n";
    for(i=1;i<n;++i)
    {
        if(v[i]==0)
        {
            cout<<idk<<' ';
            --idk;
        }
        else
            cout<<1<<' ';
    }
    if(i==n)
    cout<<1;
    return 0;
}