#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

static const ULL M = 998244353;

struct Node {
    ULL v;
    ULL d;
    ULL m;
};

struct Comb {
    ULL F[51];
    ULL I[51];
    ULL iF[51];
    Comb() {
        F[0] = 1; for (UL i = 1; i <= 50; i++) F[i] = F[i - 1] * i % M;
        I[1] = 1; for (UL i = 2; i <= 50; i++) I[i] = M - M / i * I[M % i] % M;
        iF[0] = 1; for (UL i = 1; i <= 50; i++) iF[i] = iF[i - 1] * I[i] % M;
    }
    ULL operator()(UL n, UL r) { return F[n] * iF[r] % M * iF[n - r] % M; }
};

ULL GCD(ULL a, ULL b) { return b ? GCD(b, a % b) : a; }

struct Problem {

    void Solve() {
        ULL D; scanf("%lld", &D);
        vector<pair<ULL, UL>> F;
        for (ULL i = 2; i * i <= D; i++) {
            if (D % i) continue;
            F.push_back({ i, 0 });
            while (D % i == 0) {
                D /= i; F.back().second++;
            }
        }
        if (D != 1) F.push_back({ D, 1 });

        Comb C;
        vector<Node> Dv = { {1, 0, 1} };
        for (auto& f : F) {
            UL S = Dv.size();
            rep(i, f.second) {
                rep(j, S) {
                    Node tmp = Dv[j + i * S];
                    tmp.v *= f.first;
                    tmp.d = Dv[j].d + (i + 1);
                    tmp.m = Dv[j].m * C(tmp.d, Dv[j].d) % M;
                    Dv.push_back(tmp);
                }
            }
        }
        map<ULL, UL> G;
        for (UL i = 0; i < Dv.size(); i++) G[Dv[i].v] = i;

        UL Q; scanf("%d", &Q);
        while (Q--) {
            ULL u, v; scanf("%lld%lld", &u, &v);
            ULL g = GCD(u, v);
            u /= g; v /= g;
            ULL ans = Dv[G[u]].m * Dv[G[v]].m % M;
            printf("%lld\n", ans);
        }
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    p->Solve();
    return 0;
}