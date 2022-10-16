#include <bits/stdc++.h>
using namespace std;
int v[100005];
int calc(int st, int dr)
{
    if(st==dr)
        return 0;
    int bit=0,ok=0;
    for(int i=0;i<=30;++i)
    {
        if((1<<i)&v[dr])
            bit=(1<<i);
    }
    for(int i=st+1;i<=dr;++i)
    {
        if(v[i]!=v[i-1])
        {
            ok=1;
            break;
        }
    }
    if(!ok)
        return 0;
    if(v[st]<bit)
    {
        int pz=st,i;
        for(i=st;i<=dr;++i)
            if(v[i]>=bit)
                break;
        for(int j=i;j<=dr;++j)
            v[j]-=bit;
        return bit+min(calc(st,i-1),calc(i,dr));
    }
    for(int i=st;i<=dr;++i)
        v[i]-=bit;
    return calc(st,dr);
}
int main()
{
    ios_base::sync_with_stdio(false);
    long long a,b,x,y,rz=0,n,root,m,w,i,j=0,k=0,pas=1<<15,sc=0,cnt=0,mn=0,nr1=0,nr2=0,mx=0,catc=0;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i];
    sort(v+1,v+n+1);
    for(i=1;i<=n;++i)
        if(i==1 || v[i]!=v[i-1])
            v[++j]=v[i];
    n=j;
    cout<<calc(1,n);
    return 0;
}