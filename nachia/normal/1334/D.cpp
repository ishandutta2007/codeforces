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
            ULL N, L, R; scanf("%lld%lld%lld", &N, &L, &R); L--;
            deque<UL> ans;
            ULL p = 0;
            for (ULL i = 1; i < N; i++) {
                if (p >= R) break;
                ULL q = p + (N - i) * 2;
                if (q > L) {
                    for (UL j = i + 1; j <= N; j++) {
                        ans.push_back(i);
                        ans.push_back(j);
                    }
                    for (ULL j = p; j < L; j++) ans.pop_front();
                    for (ULL j = R; j < q; j++) ans.pop_back();
                }
                p = q;
            }
            if (p < R) ans.push_back(1);
            rep(i, ans.size() - 1) printf("%d ", ans[i]);
            printf("%d\n", ans.back());
        }
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    p->Solve();
    return 0;
}