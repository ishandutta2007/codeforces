#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

    ULL F(ULL a) {
        ULL ans = a, md = 9, Md = 1;
        while (a) {
            md = min(md, a % 10);
            Md = max(Md, a % 10);
            a /= 10;
        }
        return ans + md * Md;
    }

    void Solve() {
        UL t; cin >> t;
        while (t--) {
            ULL N, K; scanf("%lld%lld", &N, &K);
            rep(i, K - 1) {
                ULL b = F(N);
                if (b == N) break;
                N = b;
            }
            printf("%lld\n", N);
        }
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    p->Solve();
    return 0;
}