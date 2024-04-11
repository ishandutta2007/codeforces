#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

int main() {
    UL N; scanf("%d", &N);
    ULL A[1000000]; rep(i, N) scanf("%lld", &A[i]);
    deque<pair<ULL, UL>> S;
    for (UL i = N - 1; i != ~0u; i--) {
        S.push_front({ A[i], 1 });
        while (S.size() >= 2) {
            if ((S[0].first + S[1].first) * S[0].second <
                S[0].first * (S[0].second + S[1].second)) {
                S[1].first += S[0].first;
                S[1].second += S[0].second;
                S.pop_front();
            }
            else break;
        }
    }
    rep(i, S.size()) {
        double ans = (double)S[i].first / S[i].second;
        rep(j, S[i].second) {
            printf("%.10f\n", ans);
        }
    }
    return 0;
}