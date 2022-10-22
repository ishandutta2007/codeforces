#include<bits/stdc++.h>
using namespace std;
using UL = unsigned long;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)


struct Problem {

    void Solve() {
        UL N; cin >> N;
        vector<ULL> A(N); rep(i, N) cin >> A[i];
        reverse(A.begin(), A.end());
        ULL buf = 0;
        ULL ans = 0;
        rep(i, N) {
            buf += A[i] / 2;
            if (A[i] & 1) {
                if (buf) { buf--; ans++; }
            }
        }
        ans += buf * 2 / 3;
        cout << ans << endl;
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    cout << fixed << setprecision(10);
    p->Solve();
    return 0;
}