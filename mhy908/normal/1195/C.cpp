#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
LL arr[4][100010], dp[4][100010];
int main()
{
    scanf("%lld", &n);
    for(int i=1; i<=n; i++){
        scanf("%lld", &arr[1][i]);
    }
    for(int i=1; i<=n; i++){
        scanf("%lld", &arr[2][i]);
    }
    dp[1][1]=arr[1][1];
    dp[2][1]=arr[2][1];
    for(int i=2; i<=n; i++){
        dp[1][i]=arr[1][i]+max(dp[2][i-1], dp[2][i-2]);
        dp[2][i]=arr[2][i]+max(dp[1][i-1], dp[1][i-2]);
    }
    printf("%lld", max(dp[1][n], dp[2][n]));
}