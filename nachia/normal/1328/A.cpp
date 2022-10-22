#include<bits/stdc++.h>
using namespace std;
using UL = unsigned long;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(int i = 0; i < (n); i++)

struct Problem {

    void Solve() {
        UL t; scanf("%d", &t);
        while (t--) {
            UL a, b; scanf("%d%d", &a, &b);
            UL m = a % b;
            if (m == 0) printf("0\n");
            else printf("%d\n", b - m);
        }
    }
};

int main() {
    unique_ptr<Problem> p(new Problem());
    p->Solve();
    return 0;
}