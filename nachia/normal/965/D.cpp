#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

    UL A[100001];

    void Solve() {
        UL L, W; scanf("%d%d", &W, &L); W--;
        A[0] = 0;
        rep(i, W)  scanf("%d", A + i + 1);
        rep(i, W) A[i + 1] += A[i];
        UL ans = 1000000000;
        for (UL i = L; i <= W; i++) {
            ans = min(ans, A[i] - A[i - L]);
        }
        cout << ans << endl;
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    //cout << fixed << setprecision(10);
    p->Solve();
    return 0;
}