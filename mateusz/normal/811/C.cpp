#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

int n;
int tab[N];
int dp[N];
int cnt[N], totalCnt[N];

int main() {
    
    scanf("%d", &n);
    
    int mxCode = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
        totalCnt[tab[i]]++;
        mxCode = max(mxCode, tab[i]);
    }
    
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        int badIntervals = 0;
        int curXor = 0;
        for (int j = 0; j <= mxCode; j++) {
            cnt[j] = 0;
        }
        for (int j = i; j >= 1; j--) {
            cnt[tab[j]]++;
            if (cnt[tab[j]] == 1) {
                badIntervals++;
                curXor ^= tab[j];
            }
            if (cnt[tab[j]] == totalCnt[tab[j]]) {
                badIntervals--;
            }
            if (badIntervals == 0) {
                dp[i] = max(dp[i], curXor + dp[j - 1]);
            }
        }
    }
    
    printf("%d\n", dp[n]);
    
    return 0;
}