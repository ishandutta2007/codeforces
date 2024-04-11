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

    int N;
    LL A[100000];
    LL GL[100000];
    LL GR[100000];

    void Solve() {
        scanf("%d", &N);
        rep(i, N) scanf("%lld", A + i);

        if (N == 2) { printf("%lld\n", LCM(A[0], A[1])); return; }

        GL[1] = A[0];
        for (int i = 2; i < N; i++) GL[i] = GCD(GL[i - 1], A[i - 1]);
        reverse(A, A + N);
        GR[1] = A[0];
        for (int i = 2; i < N; i++) GR[i] = GCD(GR[i - 1], A[i - 1]);
        LL ans = LCM(GL[N - 1], GR[N - 1]);
        for (int i = 1; i < N - 1; i++) {
            LL tmp = GCD(GL[i], GR[N - 1 - i]);
            ans = LCM(ans, tmp);
        }
        printf("%lld\n", ans);
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    p->Solve();
    return 0;
}