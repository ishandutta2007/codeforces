#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

    void Solve() {
        UL T; cin >> T;
        while (T--) {
            UL X, N, M; cin >> X >> N >> M;
            while (X > 20) {
                if (N == 0) break;
                N--; X = X / 2 + 10;
            }
            if (X > M * 10) { cout << "NO\n"; }
            else cout << "YES\n";
        }
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    p->Solve();
    return 0;
}