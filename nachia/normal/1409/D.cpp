#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

LL digsum(LL x) {
    LL ans = 0;
    while (x) { ans += x % 10; x /= 10; }
    return ans;
}

void loop() {
    LL N; int S; scanf("%lld%d", &N, &S);
    LL d = digsum(N);
    LL x = 1;
    LL ans = 0;
    while (d > S) {
        LL t = 0;
        if (N % 10 != 0) {
            t = 10 - N % 10;
            ans += t * x;
            N += t;
            d = digsum(N);
        }
        N /= 10; x *= 10;
    }
    printf("%lld\n", ans);
}

int main() {
    int t; scanf("%d", &t);
    while (t--) loop();

    return 0;
}