#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N;
vector<LL> A[2];

void loop() {
    scanf("%d", &N);
    rep(i, N) {
        int x; scanf("%d", &x);
        A[(x < 0) ? 1 : 0].push_back(x);
    }
    sort(A[0].begin(), A[0].end(), greater<LL>());
    sort(A[1].begin(), A[1].end(), less<LL>());
    LL ans = -(LL)1.e18;
    rep(t, 2) {
        rep(i, 1 + min(5ull, A[0].size())) rep(j, 1 + min(5ull, A[1].size())) {
            if (i + j != 5) continue;
            LL tmp = 1;
            rep(ii, i) tmp *= A[0][ii];
            rep(ii, j) tmp *= A[1][ii];
            ans = max(ans, tmp);
        }
        rep(j, 2) reverse(A[j].begin(), A[j].end());
    }
    printf("%lld\n", ans);
    rep(j, 2) A[j].clear();
}

int main() {
    int T; scanf("%d", &T);
    while (T--) loop();
    return 0;
}