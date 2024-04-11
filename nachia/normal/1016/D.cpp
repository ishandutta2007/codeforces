#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

    void Solve() {
        UL H, W; cin >> H >> W;
        vector<UL> A(H); rep(i, H) cin >> A[i];
        vector<UL> B(W); rep(i, W) cin >> B[i];
        UL X = 0, Y = 0;
        rep(i, H) X ^= A[i];
        rep(i, W) Y ^= B[i];
        if (X != Y) printf("NO\n");
        else {
            printf("YES\n");
            rep(y, H - 1) {
                rep(x, W - 1) printf("0 ");
                printf("%d\n", A[y]);
            }
            rep(x, W - 1) printf("%d ", B[x]);
            printf("%d\n", X ^ A[H - 1] ^ B[W - 1]);
        }
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    //cout << fixed << setprecision(10);
    p->Solve();
    return 0;
}