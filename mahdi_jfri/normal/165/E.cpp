#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define bit(a , b) (((a) >> (b))&1)
const int maxn = 5e6 + 20;
ll dp[maxn] , a[maxn];
int main()
{
    int n;
    cin >> n;
    fill(dp , dp + maxn , -1);
    for(int i = 0; i < n; i++)
    {
        scanf("%I64d" , &a[i]);
        dp[(1 << 22) - a[i] - 1] = a[i];
    }
    for(int i = (1 << 22); i > -1; i--)
    {
        if(dp[i] == -1)
            continue;
        for(int j = 0; j < 23; j++)
            if(bit(i , j))
                dp[i ^ (1 << j)] = dp[i];
    }
    for(int i = 0; i < n; i++)
        cout << dp[a[i]] << " ";
}