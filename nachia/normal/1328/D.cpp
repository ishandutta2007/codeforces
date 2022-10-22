#include<bits/stdc++.h>
using namespace std;
using UL = unsigned long;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(int i = 0; i < (n); i++)

struct Problem {

    UL T[200001];

    void Solve() {
        UL q; cin >> q;
        while (q--) {
            UL N; cin >> N;
            rep(i, N) cin >> T[i];
            {
                bool one = true;
                rep(i, N - 1) if (T[i] != T[i + 1]) one = false;
                if (one) {
                    cout << 1 << endl;
                    rep(i, N) cout << "1 "; cout << endl;
                    continue;
                }
            }

            if (N % 2 == 0) {
                cout << 2 << endl;
                rep(i, N / 2) cout << "1 2 "; cout << endl;
            }
            else {
                bool ok = false;
                rep(i, N - 1) if (T[i] == T[i + 1]) ok = true;
                if (T[0] == T[N - 1]) ok = true;
                if (!ok) {
                    cout << 3 << endl;
                    rep(i, N / 2) cout << "1 2 "; cout << 3 << endl;
                }
                else {
                    ok = false;
                    UL p = 1;
                    cout << 2 << endl << 1;
                    for (UL i = 1; i < N; i++) {
                        if (!ok) if (T[i] == T[i - 1]) { p = 3 - p; ok = true; }
                        cout << " " << (3 - p);
                        p = 3 - p;
                    } cout << endl;
                }
            }
        }
    }
};

int main() {
    unique_ptr<Problem> p(new Problem());
    p->Solve();
    return 0;
}