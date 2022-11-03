#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 20;
const int mod = 1e9 + 7;
ll sum[maxn];
ll dp[maxn];
int main()
{
int t , k;
cin >> t >> k;
fill(dp,dp + k + 1, 1);
for(int i = k; i < maxn; i++)
{
dp[i] = (dp[i - k] + dp[i - 1]) % mod;
}
sum[1] = dp[1];
for(int i = 2; i < maxn; i++)
sum[i] = (sum[i - 1] + dp[i]) % mod;
for(int i = 0; i < t; i++)
{
int a,b;
cin >> a >> b;
ll c = sum[b] - sum[a - 1];
if(c < 0)
c += mod;
cout << c << endl;
}
}