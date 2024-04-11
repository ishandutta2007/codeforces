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
            UL n, k; cin >> n >> k;
            UL i = n - 1, ii = 0;
            while (true) {
                ii += n - i;
                i--;
                if (ii >= k) break;
            }
            ii -= n - i - 2;
            UL j = n - 1 - (k - ii);
            rep(x, n) {
                if (x == i || x == j) cout << 'b';
                else cout << 'a';
            } cout << endl;
        }
    }
};

int main() {
    unique_ptr<Problem> p(new Problem());
    p->Solve();
    return 0;
}