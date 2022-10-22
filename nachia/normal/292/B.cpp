#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

    void Solve() {
        UL N, M; scanf("%d%d", &N, &M);
        vector<UL> C(N);
        rep(i, M * 2) {
            UL v; scanf("%d", &v);
            C[v - 1]++;
        }
        if (N == M) {
            rep(i, N) if (C[i] != 2) { printf("unknown topology\n"); return; }
            printf("ring topology\n"); return;
        }
        else if (N == M + 1) {
            rep(i, N) if (C[i] == N - 1) { printf("star topology\n"); return; }
            rep(i, N) if (C[i] > 2) { printf("unknown topology\n"); return; }
            printf("bus topology\n"); return;
        }
        printf("unknown topology\n");
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    //cout << fixed << setprecision(10);
    p->Solve();
    return 0;
}