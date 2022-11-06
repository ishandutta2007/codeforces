#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int x, y;

        scanf("%d %d", &x, &y);
        long long sum = 0;
        for (int res = 1; res * res <= x; res++) {
            int minK = max(2, x / (res + 1) + 1);
            int maxK = min(y + 1, x / res);
            sum += (long long)res * max(0, (maxK - minK + 1));
        }
        for (int k = 1; k <= y; k++) {
            int res = x / (k + 1);
            if ((long long)res * res <= x) { 
                sum -= res;
            }
            sum += min(res, k - 1);
            if (k - 1 > res) break;
        }
        printf("%lld\n", sum);
    }
    
}