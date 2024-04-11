#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int N = 30010;
int dp[N];
int w[110], c[110];
int main() 
{
    int n, k;
    scanf("%d%d", &n, &k);
    memset(dp, -inf, sizeof(dp));
    dp[10000] = 0;
    for (int i = 1; i <= n; ++i) 
        scanf("%d", &w[i]);        
    for (int i = 1; i <= n; ++i) 
    {
            scanf("%d", &c[i]);
            c[i] = w[i] - k * c[i];
        }
        for (int i = 1; i <= n; ++i) 
            if (c[i] >= 0) 
            {
                for (int j = 20000; j >= c[i]; --j) 
                    if (dp[j - c[i]] != -inf) 
                        dp[j] = max(dp[j], dp[j - c[i]] + w[i]);
            }
            else 
            {
                for (int j = 0; j <= 20000; ++j) 
                    if (dp[j - c[i]] != -inf) 
                        dp[j] = max(dp[j], dp[j - c[i]] + w[i]);
            }
        
        if (dp[10000] == 0) dp[10000] = -1;
        printf("%d\n", dp[10000]);
    
    return 0;
}