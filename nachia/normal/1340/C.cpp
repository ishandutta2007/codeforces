#include<bits/stdc++.h>
using namespace std;
using UL = unsigned long;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

    UL dp[10001][1024];

    void Solve() {
        UL N, M; cin >> N >> M;
        vector<UL> D(M); rep(i, M) cin >> D[i]; sort(D.begin(), D.end());
        UL G, R; cin >> G >> R;
        rep(i, M + 1) rep(j, G + 1) dp[i][j] = -1;
        deque<pair<UL, pair<UL, UL>>> Q;
        Q.push_back({ 0,{0,0} });
        while (Q.size()) {
            UL t = Q.front().second.first;
            UL p = Q.front().second.second;
            UL d = Q.front().first;
            Q.pop_front();
            if (dp[p][t] != -1) continue;
            dp[p][t] = d;
            if (p != 0) {
                UL nt = t + D[p] - D[p - 1];
                if (nt <= G) {
                    if (nt == G) Q.push_back({ d + 1, { 0, p - 1 } });
                    else Q.push_front({ d, { nt, p - 1 } });
                }
            }
            if (p != M - 1) {
                UL nt = t + D[p + 1] - D[p];
                if (nt <= G) {
                    if (nt == G) Q.push_back({ d + 1, { 0, p + 1 } });
                    else Q.push_front({ d, { nt, p + 1 } });
                }
            }
        }

        //rep(i, M) {
        //    rep(j, G) {
        //        if (dp[i][j] != -1) cout << dp[i][j];
        //        else cout << "x";
        //    } cout << endl;
        //}

        UL ans = -1;
        UL anst = 0;
        rep(t, G) {
            if (dp[M - 1][t] < ans) { ans = dp[M - 1][t]; anst = t; }
        }
        if (ans == -1) cout << -1 << endl;
        else if (anst == 0) cout << (ans * (R + G) - R) << endl;
        else cout << (ans * (R + G) + anst) << endl;
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    cout << fixed << setprecision(10);
    p->Solve();
    return 0;
}