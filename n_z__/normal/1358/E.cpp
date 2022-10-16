#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500001],sum[500001];
main()
{
    int n;
    cin>>n;
    for(int x=1;x<=(n+1)/2;x++)
    cin>>a[x],sum[x]=sum[x-1]+a[x];
    int k;
    cin>>k;
    for(int x=(n+3)/2;x<=n;x++)
    a[x]=k,sum[x]=sum[x-1]+k;
    int now=sum[n];
    for(int l=n;l>n/2;l--)
    {
        if(now>0){cout<<l<<endl;return 0;}
        now-=k;
        now=min(now,sum[n]-sum[n-l+1]);
    }
    cout<<-1<<endl;
}