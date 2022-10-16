#include <bits/stdc++.h>
using namespace std;
long long s[500003];
long long v[500003];
long long dpst[500003];
long long dpdr[500003];
long long rz[500003];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long i,j,t,n,m,l,k,p,cnt=0;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i];
    k=0;
    for(i=1;i<=n;++i)
    {
        while(k>0 && v[s[k]]>=v[i])
            --k;
        dpst[i]=v[i]*1LL*(i-s[k])+dpst[s[k]];
        s[++k]=i;
    }
  //  for(i=1;i<=n;++i)
  //      cout<<dpst[i]<<' ';
    k=0;
    s[0]=n+1;
    for(i=n;i>=1;--i)
    {
        while(k>0 && v[s[k]]>=v[i])
            --k;
        dpdr[i]=v[i]*1LL*(s[k]-i)+dpdr[s[k]];
        s[++k]=i;
    }
    long long mx=0,pzmx=1;
    for(i=1;i<n;++i)
    {
        if(dpst[i]+dpdr[i+1]>mx)
        {
            mx=dpst[i]+dpdr[i+1];
            if(v[i+1]>v[i])
                pzmx=i+1;
            else
                pzmx=i;
        }
    }
    rz[pzmx]=v[pzmx];
    for(i=pzmx-1;i>=1;--i)
        rz[i]=min(v[i],rz[i+1]);
    for(i=pzmx+1;i<=n;++i)
        rz[i]=min(v[i],rz[i-1]);
    for(i=1;i<=n;++i)
        cout<<rz[i]<<' ';
    return 0;
}