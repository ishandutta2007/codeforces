#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n,k,i;
    cin>>n;
    int a[n+1],b[n+1],c[n+1],dp[n+1];
    for(i=0;i<n;i++)
        cin>>c[i];
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n;i++)
        cin>>b[i];
    for(i=0;i<n;i++)
        if(a[i] > b[i])
            swap(a[i],b[i]);
    dp[n] = 0, a[n] = 0, b[n] = 0, c[n] = -1;
    for(i=n-1;i>0;i--)
    {
        if(a[i+1] != b[i+1])
            dp[i] = max(dp[i+1] + a[i+1] + c[i] - b[i+1] +1,c[i]-1);
        else
            dp[i] = c[i]-1;
    }
    int maxi = 0;
    for(i=0;i<n-1;i++)
        maxi = max(maxi,dp[i+1]+b[i+1]-a[i+1]+2);
    cout<<maxi<<endl;
    //I hate this...
}

main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
}