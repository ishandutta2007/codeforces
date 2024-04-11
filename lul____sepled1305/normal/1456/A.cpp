
#include<bits/stdc++.h>
#define int long long
using namespace std;
 
void solve()
{
    int n,p,k,i,j,x,y,mini = 2e9;
    cin>>n>>p>>k;
    string s;
    cin>>s>>x>>y;
    int dp[n];
    for(i=n-1;i>=0;i--)
    {
        int mul=0;
        if(s[i] == '0')
            mul = 1;
        
        if(i + k >= n)
            dp[i] = mul*x;
        else
            dp[i] = mul*x + dp[i+k];
    }
    for(i=0;i<n-p+1;i++)
    {
        mini = min(mini,dp[p+i-1] + y*i);
    }
    cout<<mini<<endl;
}
 
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    while(t--)
        solve();
}