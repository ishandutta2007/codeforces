#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("trapv")
#pragma GCC target ("avx2")

#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int dp[N],ori[N];
 
void solve()
{
    int n,i,j,maxi = 0,a;
    cin>>n; a = n;
    for(i=0;i<N;i++)
        dp[i] = 0, ori[i] = 0;
    while(n--)
    {
        cin>>i;
        ori[i]++;
    }
    for(i=1;i<N;i++)
    {
        for(j=2;i*j<N;j++)
        {
            dp[i*j] = max(dp[i*j],ori[i]+dp[i]);
            maxi = max(maxi,dp[i*j] + ori[i*j]);   
        }
    }
    cout<<a-maxi<<"\n";
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}