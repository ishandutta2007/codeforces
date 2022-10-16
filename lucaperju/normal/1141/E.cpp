#include <bits/stdc++.h>
using namespace std;
long long sp[200005],v[200005];
int main()
{
    long long h,n,i,j,m,mn=999999999,pz,s=0,y,k=0,mx=0,cnt=0,val=0,st,dr,nr0=0,nr1=0,put=1,idk=0;
    cin>>h>>n;
    for(i=1;i<=n;++i)
    {
        long long a;
        cin>>a;
        v[i]=a;
        sp[i]=sp[i-1]+a;
        if(h+sp[i]<=0)
        {
            cout<<i;
            return 0;
        }
        mn=min(mn,sp[i]);
    }
    if(sp[n]>=0)
    {
        cout<<-1;
        return 0;
    }
    long long ch=h+mn;
    val=n*1LL*(ch/(-sp[n])-1LL);
    long long hc=(val/n)*1LL*sp[n]+h;
    i=1;
    while(hc>=1)
    {
        hc+=v[i];
        ++i;
        ++val;
        if(i==n+1)
            i=1;
    }
    cout<<val;
    return 0;
}