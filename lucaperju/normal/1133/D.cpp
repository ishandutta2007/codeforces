#include <bits/stdc++.h>

using namespace std;
long double a[200005],b[200005];
long double rz[200005];
int main()
{
    long long n,i,j,m,mn=9999999,pz,s=0,x,y,k,cnt=0,cnt1=0;
    long long mx=0;
    char c;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    j=0;
    for(i=1;i<=n;++i)
    {
        cin>>b[i];
        if(a[i]==0 && b[i])
            continue;
        else
        if(a[i]==0)
        {
            ++cnt1;
            continue;
        }
        rz[++j]=(long double)(-b[i])/a[i];
    }
    sort(rz+1,rz+j+1);
    cnt=1;
    mx=0;
    for(i=2;i<=j;++i)
    {
        if(rz[i]==rz[i-1])
        {
            ++cnt;
        }
        else
            cnt=1;
        mx=max(mx,cnt);
    }
    if(j==1)
        mx=1;
    if(j==0)
        mx=0;
    cout<<mx+cnt1;
    return 0;
}