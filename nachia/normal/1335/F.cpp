#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

UL E[1000000];
UL D[1000000];
bool B[1000000];
bool F[1000000];
UL CycleSz[1000000];
UL CycleOf[1000000];
UL Ty[1000000];
UL TyP;
bool f[1000000];
bool fB[1000000];

struct UF {
    UL N; vector<UL> V;
    UF(UL n) { N = n; V.resize(N); rep(i, N) V[i] = i; }
    UL root(UL a) { if (V[a] == a) return a; return V[a] = root(V[a]); }
    void unite(UL r, UL s) { V[root(r)] = root(s); }
};

void DFS(UL p) {
    if (F[p]) {
        if (Ty[p] == ~0u) {
            Ty[p] = TyP;
            TyP++;
            CycleSz[Ty[p]] = p;
        }
        return;
    }
    F[p] = true;
    DFS(E[p]);
    D[p] = D[E[p]] + 1;
    Ty[p] = Ty[E[p]];
}

struct Problem {

    void Loop() {
        UL H, W; scanf("%d%d", &H, &W);
        UL N = H * W;
        rep(i, N) {
            char c; scanf(" %c", &c);
            B[i] = c == '0';
        }
        rep(i, N) {
            char c; scanf(" %c", &c);
            if (c == 'L') E[i] = i - 1;
            else if (c == 'R') E[i] = i + 1;
            else if (c == 'U') E[i] = i - W;
            else if (c == 'D') E[i] = i + W;
        }

        TyP = 0;
        rep(i, N) {
            D[i] = 0;
            F[i] = false;
            Ty[i] = ~0;
            CycleSz[i] = 0;
            f[i] = fB[i] = false;
        }
        rep(i, N) DFS(i);
        rep(i, TyP) CycleSz[i] = D[CycleSz[i]];
        for (UL i = 1; i < TyP; i++) CycleOf[i] = CycleOf[i - 1] + CycleSz[i - 1];
        rep(i, N) D[i] = D[i] % CycleSz[Ty[i]] + CycleOf[Ty[i]];
        rep(i, N) f[i] = fB[i] = false;

        rep(i, N) {
            f[D[i]] = true;
            if (B[i]) fB[D[i]] = true;
        }

        UL ans, ansB; ans = ansB = 0;
        rep(i, N) {
            if (f[i]) ans++;
            if (fB[i]) ansB++;
        }

        printf("%d %d\n", ans, ansB);
    }

    void Solve() {
        UL T; scanf("%d", &T);
        while (T--) Loop();
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    p->Solve();
    return 0;
}