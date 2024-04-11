#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

LL GCD(LL a, LL b) {
    return b ? GCD(b, a % b) : a;
}
LL LCM(LL a, LL b) {
    int g = GCD(a, b);
    return a / g * b;
}

struct Problem{

    UL A[100000];
    UL S[100001];
    UL N, K;

    void Solve() {
        UL t; scanf("%d", &t);
        while (t--) {
            scanf("%d%d", &N, &K);
            rep(i, N) scanf("%d", A + i);
            bool ok = false;
            rep(i, N) if (A[i] == K) ok = true;
            if (!ok) { printf("no\n"); continue; }
            if(N == 1) { printf("yes\n"); continue; }

            ok = false;
            rep(i, N) {
                if (A[i] < K) continue;
                if (i > 0) if (A[i - 1] >= K) ok = true;
                if (i > 1) if (A[i - 2] >= K) ok = true;
            }
            printf(ok ? "yes\n" : "no\n");
        }
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    p->Solve();
    return 0;
}