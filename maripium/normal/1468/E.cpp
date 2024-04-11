#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        array<int, 4> A; for (int &a : A) cin >> a;
        sort(A.begin(), A.end());
        cout << A[0] * A[2] << '\n';
    }
}