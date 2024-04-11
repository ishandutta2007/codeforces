#include<bits/stdc++.h>
using namespace std;
using UL = unsigned long;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {
    ULL A[100][100] = {};
    ULL B[100][100] = {};
    ULL C[100][100] = {};

    void Solve() {
        ULL N; UL M; cin >> N >> M;
        A[0][0] = 1;
        rep(i, M - 1) A[i][i + 1] = 1;
        A[M - 1][0] = 1;
        rep(i, M) C[i][i] = 1;
        for (UL i = 59; i != -1; i--) {
            rep(x, M) rep(y, M) {
                B[x][y] = 0;
                rep(j, M) B[x][y] += C[x][j] * C[j][y] % 1000000007;
                B[x][y] %= 1000000007;
            }
            if (N & (1ull << i)) {
                rep(x, M) rep(y, M) {
                    C[x][y] = 0;
                    rep(j, M) C[x][y] += B[x][j] * A[j][y] % 1000000007;
                    C[x][y] %= 1000000007;
                }
            }
            else rep(x, M) rep(y, M) C[x][y] = B[x][y];
        }
        cout << C[0][0] << endl;
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    cout << fixed << setprecision(10);
    p->Solve();
    return 0;
}