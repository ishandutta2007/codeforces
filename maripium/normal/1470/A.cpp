#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int N, M; cin >> N >> M;
        vector<int> A(N); for (int &a : A) cin >> a, --a;
        vector<int> C(M); for (int &c : C) cin >> c;
        sort(A.begin(), A.end());
        reverse(A.begin(), A.end());
        int64_t ans = 0;
        for (int i = 0; i < N; ++i) {
            if (i >= M) ans += C[A[i]];
            else ans += C[min(A[i], i)];
        }
        cout << ans << '\n';
    }
}