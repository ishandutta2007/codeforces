#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
    int T; cin >> T;

    while (T--) {
        int N; cin >> N;
        vector<int64_t> A(N); for (auto &a : A) cin >> a;
        for (int i = 0; i < N - 1; ++i) A[i] -= A[i + 1];
        A.pop_back(); --N;
        for (auto &a : A) a = abs(a);

        vector<array<int64_t, 18>> rmq(N);
        for (int i = 0; i < N; ++i) {
            rmq[i][0] = A[i];
        }

        int ans = 0;
        for (int j = 1; j < 18; ++j) {
            for (int i = 0; i + (1 << j) <= N; ++i) {
                rmq[i][j] = __gcd(rmq[i][j - 1], rmq[i + (1 << j - 1)][j - 1]);
            }
        } 

        auto get_rmq = [&](int l, int r) {
            int lg = __lg(r - l + 1);
            return __gcd(rmq[l][lg], rmq[r - (1 << lg) + 1][lg]);
        };

        for (int i = 0; i < N; ++i) {
            if (A[i] == 1) continue;
            int lo = i, hi = N - 1;
            while (lo < hi) {
                int mi = (lo + hi + 1) >> 1;
                if (get_rmq(i, mi) > 1) lo = mi;
                else hi = mi - 1;
            }
            ans = max(ans, lo - i + 1);
        }

        cout << ans + 1 << '\n';
    }

	return 0;
}