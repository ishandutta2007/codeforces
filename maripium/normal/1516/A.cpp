#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int T; cin >> T;

    while (T--) {
        int N, K; cin >> N >> K;
        vector<int> A(N); for (int &a : A) cin >> a;

        for (int i = 0; i < N-1; ++i) {
            int v = min(K, A[i]);
            A[i] -= v;
            A[N-1] += v;
            K -= v;
        }
        for (int i = 0; i < N; ++i) cout << A[i] << " \n"[i+1==N];
    }
}