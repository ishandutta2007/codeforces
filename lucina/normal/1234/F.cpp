#include<bits/stdc++.h>
using namespace std;
const int maxn = (1 << 20) + 10, N= 20, inf = 1e9;
int n,dp[maxn];
char s[maxn];

int main(){
    scanf("%s" , s+1);
    n = strlen(s + 1);
    for(int i=1;i<= n; i++){
        int msk = 0;
        for(int j = 0 ;j + i <= n; j++){
            if(msk & (1 << (s[i+j] - 'a'))){
                break;
            }
            msk |= (1 << (s[i+j] - 'a'));
            dp[msk] = j + 1 ;
        }
    }
    for(int i=0 ;i < 20 ; i++){
        for(int j = 0 ;j < (1 << 20); j ++){
            if( j & (1 << i)){
                dp[j] = max(dp[j] , dp[j ^ (1 << i)]);
            }
        }
    }
    int ans = 0;
    ///if x and y don't have the same bit
    ///so adding bit to it doesn't change the result
    for(int i=0 ;i < (1 << 20) ;i++){
        ans = max(ans, dp[i] + dp[((1 <<20)-1) ^ i]);
    }
    printf("%d\n",ans);

}