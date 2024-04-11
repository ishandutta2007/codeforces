#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10;
int n,a[maxn];
long long dp[2][maxn],base,ans;

int main(){
    scanf("%d",&n);
    base = (1LL*(n) * (n+1))/2LL;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    if(a[1] < 0)
        dp[0][1] = 1,ans++;
    else
        dp[1][1] = 1;
    for(int i=2;i<= n; i++){
        if(a[i] > 0){
            dp[0][i] = dp[0][i-1];
            dp[1][i] = dp[1][i-1];
            dp[1][i] ++;
        }
        else{
            dp[0][i] = dp[1][i-1];
            dp[1][i] = dp[0][i-1];
            dp[0][i] ++;
        }
        ans += dp[0][i];
    }
    printf("%lld %lld\n",ans, base -ans);
}
/*
    Good Luck
        -Lucina
*/