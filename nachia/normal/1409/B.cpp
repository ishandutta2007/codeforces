#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

LL solve(LL a, LL b, LL x, LL y, LL n) {
    LL t = min(a - x, n);
    a -= t; n -= t;
    t = min(b - y, n);
    b -= t; n -= t;
    return a * b;
}

void loop() {
    LL a, b, x, y, n; scanf("%lld%lld%lld%lld%lld", &a, &b, &x, &y, &n);
    if (a < b) { swap(a, b); swap(x, y); }
    printf("%lld\n", min(solve(a, b, x, y, n), solve(b, a, y, x, n)));
}

int main() {
    int t; scanf("%d", &t);
    while (t--) loop();

    return 0;
}