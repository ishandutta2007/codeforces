#include<bits/stdc++.h>
using namespace std;
using UL = unsigned long;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

    UL dp[2001][2001];

    void Solve() {
        UL N, K; cin >> N >> K;
        rep(i, N + 1) rep(j, K + 1) dp[i][j] = -1;
        dp[0][0] = 0;
        const UL digit[10] = {
            0b1110111, 0b0010010, 0b1011101, 0b1011011, 0b0111010,
            0b1101011, 0b1101111, 0b1010010, 0b1111111, 0b1111011
        };
        const UL szdigit[10] = { 6,2,5,5,4,5,6,3,7,6 };
        vector<vector<pair<UL, UL>>> J(N);
        vector<pair<UL, UL>> P(N);
        {
            rep(i, N) {
                rep(j, 7) {
                    char c; cin >> c;
                    P[i].first <<= 1;
                    P[i].first |= ((c == '0') ? 0 : 1);
                    P[i].second += ((c == '0') ? 0 : 1);
                }
            }
            for (UL i = N - 1; i != -1; i--) {
                J[i].resize(10);
                rep(j, 10) {
                    if (P[i].first & ~digit[j]) continue;
                    UL d = szdigit[j] - P[i].second;
                    J[i].push_back({ j, d });
                    for (UL k = d; k <= K; k++) {
                        if (dp[N - 1 - i][k - d] != -1)
                            dp[N - i][k] = j;
                    }
                }
            }
        }
        //rep(i, N + 1) {
        //    rep(j, K + 1) {
        //        if (dp[i][j] == -1) cout << ".";
        //        else cout << dp[i][j];
        //    } cout << endl;
        //}
        string ans;
        if (dp[N][K] == -1) { cout << -1 << endl; return; }
        UL k = K;
        for (UL i = N; i > 0; i--) {
            ans.push_back('0' + dp[i][k]);
            k -= szdigit[dp[i][k]] - P[N - i].second;
        }
        cout << ans << endl;

        /*
        UL N, M; cin >> N >> M;
        vector<UL> D(M); rep(i, M) cin >> D[i]; sort(D.begin(), D.end());
        UL G, R; cin >> G >> R;
        vector<UL> V(M * G, -1);
        priority_queue<pair<UL, UL>, vector<pair<UL, UL>>, greater<pair<UL, UL>>> Q;
        Q.push({ 0,0 });
        UL ans = -1;
        UL anst = 0;
        while (Q.size()) {
            UL i = Q.top().second;
            UL t = i / M;
            UL p = i - M * t;
            UL d = Q.top().first;
            Q.pop();
            if (t == G) { t = 0; d++; i = t * M + p; }
            if (V[i] != -1) continue;
            V[i] = d;
            if (p != 0)
                if (t + D[p] - D[p - 1] <= G)
                    Q.push({ d, (t + D[p] - D[p - 1]) * M + (p - 1) });
            if (p != M - 1)
                if (t + D[p + 1] - D[p] <= G)
                    Q.push({ d, (t + D[p + 1] - D[p]) * M + (p + 1) });
            if (p == M - 1) if (t + N - D[p] <= G) {
                ans = d; anst = t + N - D[p]; break;
            }
        }
        if (ans == -1) cout << -1 << endl;
        else cout << (ans * (R + G) + anst) << endl;

        UL N; cin >> N;
        vector<vector<UL>> E(N);
        rep(i, N - 1) {
            UL u, v; cin >> u >> v; u--; v--;
            E[u].push_back(v);
            E[v].push_back(u);
        }

        */
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    cout << fixed << setprecision(10);
    p->Solve();
    return 0;
}