#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
ll dp[maxn] , i;
int main()
{
    ll n;
    cin >> n;
    dp[0] = 0;
    dp[1] = 1;
    i = 2;
    while(1)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
        if(dp[i] > n)
        {
            cout << i - 3;
            return 0;
        }
        i++;
    }
}