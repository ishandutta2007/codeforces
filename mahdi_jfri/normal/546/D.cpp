#include <bits/stdc++.h>
#define ll long long
const int maxn = 5e6+100; 
ll isp[maxn];
 using namespace std; 
ll dp[maxn] , sum[maxn];
int main()
{ 
    int t;
    cin >> t;
    for(ll i=2;i < maxn;i++) 
        {
        if(isp[i]==0) 
            { 
            dp[i] = 1;
            for(long long j=i*i; j<maxn; j+=i)
             { 
                isp[j] = i; 
             } 
            } 
        else
        dp[i] = dp[i / isp[i]] + 1;
        sum[i] = sum[i - 1] + dp[i];
        }
    ll a,b;
    while(t--)
    {
       scanf("%I64d%I64d",&a,&b);
       ll c = sum[a] - sum[b];
       printf("%I64d \n",c);
    }
}