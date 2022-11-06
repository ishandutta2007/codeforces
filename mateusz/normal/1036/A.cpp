#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int main() {
    
    long long n, k;
    
    scanf("%lld %lld", &n, &k);
    
    printf("%lld\n", (k + n - 1) / n);

    return 0;
}