#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int T; T = 1;
    while (T--) {
        int N, M; cin >> N >> M;
        vector<string> G(N);
        for (int i = 0; i < N; ++i) cin >> G[i];    

        vector<int> last(M, -1);
        for (int i = 1; i < N; ++i) {
            for (int j = 1; j < M; ++j) {
                if (G[i-1][j] == 'X' && G[i][j-1] == 'X') {
                    last[j] = max(last[j], j-1);
                }
            }
        }
        for (int i = 1; i < M; ++i) last[i] = max(last[i], last[i - 1]);
        int Q; cin >> Q;
        while (Q--) {
            int l, r; cin >> l >> r; --l, --r;
            if (last[r] >= l) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
        }
    }
}