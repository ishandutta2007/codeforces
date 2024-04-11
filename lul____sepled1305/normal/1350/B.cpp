#include<bits/stdc++.h>
using namespace std;
int t;

int main()
{
    cin>>t;
    while(t--)
    {
        int n,i,j,maxi = 0;
        cin>>n;
        int arr[n+1];
        int dp[n+1];
        for(i=1;i<=n;i++)
            cin>>arr[i];
        for(i=1;i<=n;i++)
            dp[i] = 1;
        for(i=1;i<=n;i++)
        {
            for(j=1;j*j<=i;j++)
            {
                if(i%j==0)
                {
                    if(dp[j] +1 > dp[i] && arr[j]<arr[i])
                        dp[i] = dp[j]+1;
                    if(dp[i/j]+1>dp[i] && arr[i/j]<arr[i])
                        dp[i] = dp[i/j]+1;
                }
            }
            if(dp[i]>maxi)
                maxi = dp[i];
        }
        cout<<maxi<<"\n";
    }
}