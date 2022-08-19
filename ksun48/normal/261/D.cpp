#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    int k, n, maxb, t;
    scanf("%d%d%d%d", &k, &n, &maxb, &t);
    t = min(t, maxb);
    int a[n];

    int dp[maxb + 1];
    while(k--){
        for(int i = 0; i <= maxb + 1; i++){
            dp[i] = 0;
        }
        for(int j = 0; j < n; j++){
            scanf("%d", &a[j]);
        }
        for(int v = 0; v < t; v++){
            for(int j = 0; j < n; j++){
                dp[a[j]] = max(dp[a[j]], dp[a[j]-1] + 1);
                int c = a[j] + 1;
                while(c <= maxb && dp[c] < dp[c-1]){
                    dp[c] = dp[c-1];
                    c++;
                }
            }
        }
        printf("%d\n", dp[maxb]);
    }
}