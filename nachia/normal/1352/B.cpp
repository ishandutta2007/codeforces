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
            UL N, K; cin >> N >> K;
            if (N % 2 == 1) {
                if (K % 2 == 0) cout << "NO" << endl;
                else if (N < K) cout << "NO" << endl;
                else {
                    cout << "YES" << endl;
                    rep(i, K - 1) cout << "1 ";
                    cout << (N - K + 1) << endl;
                }
            }
            else {
                if (K % 2 == 0) {
                    if (N < K) cout << "NO" << endl;
                    else {
                        cout << "YES" << endl;
                        rep(i, K - 1) cout << "1 ";
                        cout << (N - K + 1) << endl;
                    }
                }
                else if (N < K * 2) cout << "NO" << endl;
                else {
                    cout << "YES" << endl;
                    rep(i, K - 1) cout << "2 ";
                    cout << (N - 2 * K + 2) << endl;
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