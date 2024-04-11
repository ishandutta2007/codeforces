#include<bits/stdc++.h>
using namespace std;
using UL = unsigned long;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(int i = 0; i < (n); i++)

struct Problem {

    void Solve() {
        UL N; cin >> N;
        UL K; cin >> K;
        vector<vector<UL>> E(N);
        rep(i, N - 1) {
            UL u, v; cin >> u >> v; u--; v--;
            E[u].push_back(v);
            E[v].push_back(u);
        }
        vector<int> dp(N, 0);
        vector<int> D(N, -1); D[0] = 0;
        vector<UL> P(N);
        vector<UL> O;
        {
            queue<UL> Q; Q.push(0);
            while (Q.size()) {
                UL p = Q.front(); Q.pop();
                O.push_back(p);
                for (UL e : E[p]) {
                    if (D[e] != -1) continue;
                    P[e] = p;
                    D[e] = D[p] + 1;
                    Q.push(e);
                }
            }
        }
        reverse(O.begin(), O.end());
        for (UL p : O) { if (p == 0) break; dp[P[p]] += dp[p] + 1; }
        reverse(O.begin(), O.end());
        for (UL p : O) {
            if (p == 0) dp[p] = -(int)(N - 1);
            else dp[p] = D[p] - dp[p];
        }
        sort(dp.rbegin(), dp.rend());
        LL ans = 0;
        rep(i, K) ans += dp[i];
        cout << ans << endl;
    }
};

int main() {
    cin.tie(0);
    unique_ptr<Problem> p(new Problem());
    p->Solve();
    return 0;
}