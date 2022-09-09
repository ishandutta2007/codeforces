#include <bits/stdc++.h>
using namespace std;

long long k, d, t;

int main() {
    scanf("%lld %lld %lld", &k, &d, &t);
    long long n = (d - k % d) % d;
    t <<= 1;
    long long p = (2 * k + n);
    double res = t / p * (k + n);
    if (t % p <= (k << 1)) res += t % p / 2.0;
    else res += k + (t % p - (k << 1));
    printf("%.1lf\n", res);
    return 0;
}