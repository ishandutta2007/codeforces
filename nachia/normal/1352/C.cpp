#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem{

    void Solve() {
        UL t; cin >> t;
        while (t--) {
            ULL N, K; cin >> N >> K;
            ULL ans = 0;
            ans += N * ((K - 1) / (N - 1));
            K = (K - 1) % (N - 1) + 1;
            ans += K;
            cout << ans << endl;
        }
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    p->Solve();
    return 0;
}