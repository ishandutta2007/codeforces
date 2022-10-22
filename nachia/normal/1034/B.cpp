#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

    void Solve() {
        ULL N, M; cin >> N >> M;
        if (N % 2 == 0) swap(N, M);
        if (M % 2 == 0 && N != 1) {
            if (M == 2) {
                UL ans = N * 2;
                if (N == 3 || N == 7) ans -= 2;
                if (N <= 2) ans = 0;
                cout << ans << endl; return;
            }
            else {
                cout << N * M << endl; return;
            }
        }
        if (N * M <= 3) { cout << 0 << endl; return; }

        if (N < M) swap(N, M);
        if (M == 1) { cout << (N/6*6 + (max(N%6,3ull)-3)*2) << endl; return; }
        cout << (N * M - 1) << endl;
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    //cout << fixed << setprecision(10);
    p->Solve();
    return 0;
}