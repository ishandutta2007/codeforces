#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem{
    UL N;
    UL P[500001] = {};
    UL D[500001] = {};
    UL ans[500001];
    void Solve() {
        cin >> N;
        for (UL i = 1; i <= N; i++) P[i] = 1;
        for (UL i = 2; i * i <= N; i++) {
            if (P[i] != 1) continue;
            for (UL j = i; j * i <= N; j++)
                P[j * i] = max(P[j * i], j);
        }
        for (UL i = 1; i <= N; i++) D[P[i] - 1]++;
        for (UL i = N; i >= 1; i--) D[i] += D[i + 1];
        for (UL i = 1; i <= N; i++) D[i] = N - D[i];
        //for (UL i = 1; i <= N; i++) printf("%d ", P[i]); printf("\n");
       // for (UL i = 1; i <= N; i++) printf("%d ", D[i]); printf("\n");
        UL p = 1;
        for (UL i = 2; i <= N; i++) {
            while (D[p] < i) p++;
            if (i != 2) printf(" %d", p);
            else printf("%d", p);
        } printf("\n");
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    p->Solve();
    return 0;
}