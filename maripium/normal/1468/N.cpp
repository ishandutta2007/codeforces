#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        auto ans = [](){
            array<int, 3> A; for (int &a : A) cin >> a;
            array<int, 5> B; for (int &b : B) cin >> b;
            if (B[0] > A[0]) return false; A[0] -= B[0];
            if (B[1] > A[1]) return false; A[1] -= B[1];
            if (B[2] > A[2]) return false; A[2] -= B[2];
            B[3] -= min(A[0], B[3]);
            B[4] -= min(A[1], B[4]);
            return bool(B[3] + B[4] <= A[2]);
        }();
        if (ans) cout << "YES\n";
        else cout << "NO\n";
    }
}