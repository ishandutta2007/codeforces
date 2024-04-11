#include<bits/stdc++.h>
using namespace std;
using UL = unsigned long;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

    void Loop() {
        UL N; cin >> N;
        N /= 2;
        if (N & 1) { cout << "NO" << endl; return; }
        cout << "YES" << endl;
        rep(i, N) {
            if (i) cout << " ";
            cout << (i * 2 + 2);
        }
        rep(i, N) {
            if (i < N / 2) cout << " " << (i * 2 + 1);
            else cout << " " << (i * 2 + 3);
        }
        cout << endl;
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