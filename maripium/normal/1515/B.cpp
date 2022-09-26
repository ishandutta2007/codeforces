#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    auto is_sq = [&](int X) {
        int Y = sqrt(X);
        while (Y * Y < X) Y++;
        return Y*Y == X;
    };
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        if (N % 2 == 0 && (is_sq(N) || is_sq(N / 2))) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}