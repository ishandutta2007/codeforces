#include <bits/stdc++.h>

using namespace std;

int nwd(int a, int b) { return b ? nwd(b, a % b) : a; }

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        long long x, y, p, q;
        scanf("%lld %lld %lld %lld", &x, &y, &p, &q);
        int NWD = nwd(p, q);
        p /= NWD;
        q /= NWD;
        int low = 0;
        int high = 1e9;
        long long res = 1e18;
        long long st = res;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (p * mid - x >= 0 && q * mid - y >= 0 && p * mid - x <= q * mid - y) {
                res = min(res, q * mid - y);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (res == st) {
            printf("-1\n");
        } else {
            printf("%lld\n", res);
        }
    }
    
    return 0;
}