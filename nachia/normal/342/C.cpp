#include<bits/stdc++.h>
using namespace std;
using UL = unsigned long;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(int i = 0; i < (n); i++)

struct Problem {

    void Solve() {
        ULL r, h; cin >> r >> h; r *= 2; h *= 2; h += r / 2;
        ULL ans = h / r * 2;
        h %= r;
        if (3 * r * r < (2 * h + r) * (2 * h + r)) ans++;
        cout << ans << endl;
    }
};

int main() {
    unique_ptr<Problem> p(new Problem());
    p->Solve();
    return 0;
}