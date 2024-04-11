#include <bits/stdc++.h>

using namespace std;

int n, k, A, B;

int main() {
    
    scanf("%d %d %d %d", &n, &k, &A, &B);
    
    long long cost = 0;
    
    if (k == 1) {
        printf("%lld\n", (long long)A * (n - 1));
        return 0;
    }
    
    while (n != 1) {
        int floor = (n / k) * k;
        if (floor == 0) {
            cost += (long long)A * (n - 1);
            break;
        }
        cost += (long long)A * (n - floor);
        n = floor;
        int newN = floor / k;
        if (B > (long long)A * (n - newN)) {
            cost += (long long)A * (n - newN);
        } else {
            cost += B;
        }
        n = newN;
    }
    
    printf("%lld\n", cost);
    
    return 0;
}