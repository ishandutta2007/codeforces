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
            string S; cin >> S;
            UL N[2] = {};
            for (char c : S) N[c - '0']++;
            if (N[0] == 0 || N[1] == 0) cout << S;
            else rep(i, S.size()) cout << "01";
            cout << endl;
        }
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    p->Solve();
    return 0;
}