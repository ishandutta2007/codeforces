#include <bits/stdc++.h>

using namespace std;

const int N = 35;

int n, L;
long long cost[N];

int main() {
    
    scanf("%d %d", &n, &L);
    
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &cost[i]);
    }
    for (int i = n + 1; i <= 31; i++) {
        cost[i] = 1e18;
    }
    
    for (int i = 1; i <= 31; i++) {
        cost[i + 1] = min(cost[i + 1], 2 * cost[i]);
    }
    
    long long total = 0;
    long long ans = 1e18;
    while (L > 0) {
        long long curMin = cost[31];
        for (int i = 30; i >= 1; i--) {
            if (L >= (1<<(i-1))) {
                ans = min(ans, total + curMin);
                total += cost[i];
                L -= (1<<(i-1));
                break;
            } else {
                curMin = min(curMin, cost[i]);
            }
        }
    }
    
    printf("%lld\n", min(total, ans));

    return 0;
}