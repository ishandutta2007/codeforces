#include<bits/stdc++.h>
using namespace std;
using UL = unsigned long;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(int i = 0; i < (n); i++)

struct Problem {

    void Solve() {
        UL t; cin >> t;
        while (t--) {
            UL N; cin >> N;
            string A[2];
            bool prog = false;
            rep(i, N) {
                char c; cin >> c;
                if (c == '0') { A[0].push_back('0'); A[1].push_back('0'); }
                else if (c == '1') {
                    if (prog) { A[0].push_back('0'); A[1].push_back('1'); }
                    else { A[0].push_back('1'); A[1].push_back('0'); prog = true; }
                }
                else {
                    if (prog) { A[0].push_back('0'); A[1].push_back('2'); }
                    else { A[0].push_back('1'); A[1].push_back('1'); }
                }
            }
            cout << A[0] << endl;
            cout << A[1] << endl;
        }
    }
};

int main() {
    unique_ptr<Problem> p(new Problem());
    p->Solve();
    return 0;
}