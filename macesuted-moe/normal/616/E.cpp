#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

int main() {
    long long n, m;
    scanf("%lld%lld", &n, &m);
    long long lim = min(n, m), sum = 0;
    for (long long i = 1, j; i <= lim; i = j + 1) {
        j = min(n / (n / i), lim);
        long long a = i + j, b = j - i + 1;
        (a & 1) ? b /= 2 : a /= 2;
        sum = (sum + ((a % mod) * (b % mod) % mod) * (n / i) % mod) % mod;
    }
    printf("%lld\n", ((n % mod) * (m % mod) % mod - sum + mod) % mod);
    return 0;
}