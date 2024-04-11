#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

    void Solve() {
        UL t; cin >> t;
        while (t--) {
            string S; cin >> S;
            pair<UL, UL> P = { 0,0 };
            set<pair<UL, UL>> V;
            set<pair<UL, UL>> H;
            UL ans = 0;
            for (char c : S) {
                if (c == 'N') {
                    ans += (V.count(P) ? 1 : 5);
                    V.insert(P);
                    P.second++;
                }
                if (c == 'S') {
                    P.second--;
                    ans += (V.count(P) ? 1 : 5);
                    V.insert(P);
                }
                if (c == 'E') {
                    ans += (H.count(P) ? 1 : 5);
                    H.insert(P);
                    P.first++;
                }
                if (c == 'W') {
                    P.first--;
                    ans += (H.count(P) ? 1 : 5);
                    H.insert(P);
                }
            }
            cout << ans << endl;
        }
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    p->Solve();
    return 0;
}