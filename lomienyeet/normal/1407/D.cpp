// wow! thanks hkoi training for teaching me monotonicity!
// definitely!

#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;
    cin>>n;
    int arr[n+1],dp[n+1];
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=1;i<=n;i++)dp[i]=1e18;
    dp[n]=0;
    stack<int> ms1,ms2;
    ms1.push(n);
    ms2.push(n);
    for(int i=n-1;i>0;i--){
        while(ms1.size()&&arr[ms1.top()]<arr[i]){
            dp[i]=min(dp[i],dp[ms1.top()]+1);
            ms1.pop();
        }
        if(ms1.size())dp[i]=min(dp[i],dp[ms1.top()]+1);
        while(ms1.size()&&arr[ms1.top()]==arr[i])ms1.pop();
        ms1.push(i);
        while(ms2.size()&&arr[ms2.top()]>arr[i]){
            dp[i]=min(dp[i],dp[ms2.top()]+1);
            ms2.pop();
        }
        if(ms2.size())dp[i]=min(dp[i],dp[ms2.top()]+1);
        while(ms2.size()&&arr[ms2.top()]==arr[i])ms2.pop();
        ms2.push(i);
    }
    cout<<dp[1]<<"\n";
}