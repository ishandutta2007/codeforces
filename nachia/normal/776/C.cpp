#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;

int main() {
    UL n; LL k; scanf("%d%lld", &n, &k);
    
    set<LL> Pows;
    for (LL i = 0; i < 60; i++) {
        double dbl = pow(k, i);
        if (abs(dbl) > 1e16) break;
        Pows.insert(dbl);
    }
    
    map<LL, LL> PrefixSums; PrefixSums[0]++;
    LL Sum = 0;
    LL ans = 0;
    for (UL i = 0; i < n; i++) {
        LL a; scanf("%lld", &a);
        Sum += a;
        for (LL Pow : Pows) {
            if (PrefixSums.find(Sum - Pow) != PrefixSums.end())
                    ans += PrefixSums[Sum - Pow];
        }
        PrefixSums[Sum]++;
    }

    printf("%lld\n", ans);
    return 0;
}