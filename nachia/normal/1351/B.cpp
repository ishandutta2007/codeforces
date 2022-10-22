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
            UL a, b; cin >> a >> b;
            UL c, d; cin >> c >> d;
            bool ok = false;
            if (a == c && a == b + d) ok = true;
            if (a == d && a == b + c) ok = true;
            if (b == c && b == a + d) ok = true;
            if (b == d && b == a + c) ok = true;
            cout << (ok ? "YES" : "NO") << endl;
        }
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    p->Solve();
    return 0;
}