#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int N, M; cin >> N >> M;
        vector<string> G(N);
        for (int i = 0; i < N; ++i) cin >> G[i];
        int ans = 1e9;
        for (int hi = 0; hi < N; ++hi) {
            vector<int> pref_hi(M+1);
            for (int i = 0; i < M; ++i) pref_hi[i+1] = pref_hi[i] + (G[hi][i] == '0');
            vector<int> pref_mi(M+1);
            vector<int> col(M);
            for (int lo = hi+1; lo < N; ++lo) {
                vector<int> pref_lo(M+1);
                for (int i = 0; i < M; ++i) pref_lo[i + 1] = pref_lo[i] + (G[lo][i] == '0');
                if (lo - hi + 1 >= 5) {
                    // cost = (pref_lo[r] - pref[l + 1]) + pref_hi[r] - pref_hi[l + 1] + pref_mi[r] - pref_mi[l + 1] + col[l] + col[r]
                    int best = 1e9;
                    for (int l = 0; l + 4 <= M; ++l) {
                        best = min(best, -pref_hi[l + 1] - pref_mi[l + 1] - pref_lo[l + 1] + col[l]);
                        int r = l + 3;
                        ans = min(ans, best + pref_lo[r] + pref_hi[r] + pref_mi[r] + col[r]);
                    }
                }
                for (int i = 0; i <= M; ++i) pref_mi[i] += i - pref_lo[i];
                for (int i = 0; i < M; ++i) col[i] += (G[lo][i] == '0');
            }
        }
        cout << ans << '\n';
    }
}