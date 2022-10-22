#include<bits/stdc++.h>
using namespace std;
using UL = unsigned long;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

    void Loop() {
        UL N; cin >> N;
        for (UL i = 2; i < 30; i++) {
            if (N % ((1 << i) - 1) == 0) {
                cout << N / ((1 << i) - 1) << endl;
                return;
            }
        }
    }

    void Solve() {
        UL T; cin >> T;
        while (T--) Loop();
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    cout << fixed << setprecision(10);
    p->Solve();
    return 0;
}