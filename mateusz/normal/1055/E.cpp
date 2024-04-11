#include <bits/stdc++.h>

using namespace std;

const int N = 1505;

int n, segments, m, k;
int best[N];
int pref[N];
int dp[N][N];
int from[N], to[N];
int a[N];

bool good(int val) {
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + (a[i] <= val ? 1 : 0);
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j > 0 && best[i] <= i) {
                dp[i][j] = max(dp[i][j], pref[i] - pref[best[i] - 1] + dp[best[i] - 1][j - 1]);
            }
        }
    }
    
    return (dp[n][m] >= k);
}

int main() {
    
    scanf("%d %d %d %d", &n, &segments, &m, &k);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        best[i] = i + 1;
    }
    
    for (int i = 1; i <= segments; i++) {
        scanf("%d %d", &from[i], &to[i]);
        for (int j = from[i]; j <= to[i]; j++) {
            best[j] = min(best[j], from[i]);
        }
    } 
    
    int low = 1;
    int high = 1e9;
    int res = -1;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        if (good(mid)) {
            res = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    printf("%d\n", res);

    return 0;
}