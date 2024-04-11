#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Edge { UL to; UL cap; UL rev; };

struct Problem {

    void Solve() {
        UL N; cin >> N;
        UL H; cin >> H;
        multiset<UL> A;
        rep(i, N) {
            UL a; cin >> a; A.insert(a);
            UL l, r; l = r = 0;
            for (UL p : A) {
                l += p; swap(l, r);
            }
            l += *--A.end();
            if (min(l, r) > H) { cout << i << endl; return; }
        }
        cout << N << endl;
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    //cout << fixed << setprecision(10);
    p->Solve();
    return 0;
}