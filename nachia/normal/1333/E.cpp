#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem{

    UL G[3][3] = {
        {0,7,8},{5,6,2},{1,3,4}
    };
    UL ans[500][500];

    void Solve() {
        UL N; cin >> N;
        if (N <= 2) { printf("-1\n"); return; }
        rep(x, 3) rep(y, 3) ans[x][y] = G[x][y];
        for (UL d = 4; d <= N; d++) {
            UL p = (d - 1) * (d - 1);
            if (d & 1) {
                for (UL i = 0; i < d; i++) { ans[d - 1][i] = p; p++; }
                for (UL i = d - 2; i != ~0u; i--) { ans[i][d - 1] = p; p++; }
            }
            else {
                for (UL i = 0; i < d; i++) { ans[i][d - 1] = p; p++; }
                for (UL i = d - 2; i != ~0u; i--) { ans[d - 1][i] = p; p++; }
            }
        }
        rep(y, N) {
            rep(x, N) {
                ans[x][y] = N * N - ans[x][y];
                if (x) printf(" %d", ans[x][y]);
                else printf("%d", ans[x][y]);
            } printf("\n");
        }
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    p->Solve();
    return 0;
}