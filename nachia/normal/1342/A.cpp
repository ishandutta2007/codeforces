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
            ULL x, y; cin >> x >> y;
            ULL a, b; cin >> a >> b;
            if (a * 2 < b) {
                cout << (x + y) * a << endl;
            }
            else {
                cout << (b * min(x, y) + a * (max(x, y) - min(x, y))) << endl;
            }
        }
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    p->Solve();
    return 0;
}