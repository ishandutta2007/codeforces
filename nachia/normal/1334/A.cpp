#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem{

    void Solve() {
        UL T; scanf("%d", &T);
        while (T--) {
            UL N; scanf("%d", &N);
            UL A, B; A = B = 0;
            bool ok = true;
            rep(i, N) {
                UL a, b; scanf("%d%d", &a, &b);
                if (a < A) ok = false;
                else if (b < B) ok = false;
                else if (a - A < b - B) ok = false;
                A = a; B = b;
            }
            printf(ok ? "YES\n" : "NO\n");
        }
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    p->Solve();
    return 0;
}