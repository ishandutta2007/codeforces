#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int N, M; cin >> N >> M;
        string A, B; cin >> A >> B;

        auto solve = [&]() {
            for (int i = 0; i < M - 1; ++i) if (A[N - 1 - i] != B[M - 1 - i]) return false;
            for (int i = 0; i <= N - M; ++i) if (A[i] == B[0]) return true;
            return false;
        };

        if (solve()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}