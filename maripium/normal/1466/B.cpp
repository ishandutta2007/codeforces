#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<int> A(N); for (int &a : A) cin >> a;
        for (int i = N-1; i >= 0; --i) {
            if (i+1 == N || A[i] + 1 < A[i+1]) A[i]++;
        }
        int ans = 1;
        for (int i = 1; i < N; ++i) ans += (A[i] > A[i-1]);
        cout << ans << '\n';
    }
    return 0;
}