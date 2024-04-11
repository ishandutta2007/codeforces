#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
    [&]() {
        int N, K; cin >> N >> K;
        vector<int> X(N), Y(N);
        for (int i = 0; i < N; ++i) cin >> X[i] >> Y[i];
        for (int i = 0; i < N; ++i) {
            bool fail = false;
            for (int j = 0; j < N; ++j) if (abs(X[i] - X[j]) + abs(Y[i] - Y[j]) > K) {
                fail = true;
            }
            if (!fail) {
                cout << "1\n";
                return;
            }
        }
        cout << "-1\n";
    }();
    }
}