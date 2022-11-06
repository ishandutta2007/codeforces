#include <bits/stdc++.h>

using namespace std;

int main() {

    int k2, k3, k5, k6;
    scanf("%d %d %d %d", &k2, &k3, &k5, &k6);

    int v256 = min(k2, min(k5, k6));
    k2 -= v256;
    
    int v32 = min(k2, k3);
    printf("%lld\n", (long long)v256 * 256 + (long long)32 * v32);

    return 0;
}