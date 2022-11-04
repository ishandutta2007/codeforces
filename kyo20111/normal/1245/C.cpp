#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[101010];
int dp[101010],i,mod=1e9+7;
int main(){
    scanf("%s",s+1);
    dp[0] = 1;
    for(i=1;s[i];i++){
        if(s[i] == 'm' || s[i] == 'w') return !printf("0");

        dp[i] = dp[i-1] % mod;
        if(s[i] == 'u' || s[i] == 'n'){
            if(s[i] == s[i-1]) (dp[i] += dp[i-2]) %= mod;
        }
    }
    printf("%d",dp[i-1]);
}