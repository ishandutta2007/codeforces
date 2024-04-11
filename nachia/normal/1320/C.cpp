#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct RAQ_RMQ {
    UL N;
    vector<pair<LL, LL>> V;
    RAQ_RMQ(UL n) {
        N = 1; while (N < n) N *= 2;
        V.resize(N * 2 - 1);
    }
    LL query() { return V[0].first; }
    void add(UL l, UL r, LL v, UL a = ~0u, UL b = ~0u, UL i = ~0u) {
        if (i == ~0u) { a = 0; b = N; i = 0; }
        if (r <= a || b <= l) return;
        if (l <= a && b <= r) { V[i].first += v; V[i].second += v; return; }
        add(l, r, v, a, (a + b) >> 1, (i << 1) + 1);
        add(l, r, v, (a + b) >> 1, b, (i << 1) + 2);
        V[i].first = max(V[(i << 1) + 1].first, V[(i << 1) + 2].first) + V[i].second;
    }
};

struct Problem {

    UL N, M, P;
    pair<LL, LL> A[200001];
    pair<LL, LL> B[200001];
    pair<pair<LL, LL>, LL> C[200001];

    void Solve() {
        scanf("%d%d%d", &N, &M, &P);
        rep(i, N) scanf("%lld%lld", &A[i].second, &A[i].first);
        rep(i, M) scanf("%lld%lld", &B[i].first, &B[i].second);
        rep(i, P) scanf("%lld%lld%lld", &C[i].first.second, &C[i].first.first, &C[i].second);
        sort(A, A + N); A[N].first = 10000000;
        sort(B, B + M); B[M].first = 10000000;
        sort(C, C + P); C[P].first.first = 10000000;
        RAQ_RMQ Q(1010000);
        UL p = 0;
        rep(i, N) {
            if (p >= A[i].second) continue;
            Q.add(p, A[i].second, -A[i].first);
            p = A[i].second;
        }
        Q.add(p, Q.N, (LL)-1e17);

        UL pC = 0;
        LL ans = (LL)-1e10;
        rep(i, M) {
            while (C[pC].first.first < B[i].first) {
                Q.add(C[pC].first.second, Q.N, C[pC].second);
                pC++;
            }
            ans = max(ans, Q.query() - B[i].second);
        }
        printf("%lld\n", ans);
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    p->Solve();
    return 0;
}