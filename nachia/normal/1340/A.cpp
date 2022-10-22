#include<bits/stdc++.h>
using namespace std;
using UL = unsigned long;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

    void Loop() {
        UL N; cin >> N;
        vector<UL> P(N); rep(i, N) cin >> P[i];
        bool ok = true;
        rep(i, N - 1) {
            if (1 + P[i] < P[i + 1]) ok = false;
        }
        cout << (ok ? "Yes" : "No") << endl;
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