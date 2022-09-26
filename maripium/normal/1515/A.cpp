#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int N, X; cin >> N >> X;
        vector<int> A(N); for (int &a : A) cin >> a;
        if (accumulate(A.begin(), A.end(), 0) == X) {
            cout << "NO\n";
            continue;
        }

        int pref = 0;
        for (int i = 0; i < N; ++i) {
            pref += A[i];
            if (pref == X) {
                swap(A[i], A[i+1]);
                break;
            }
        }
        cout << "YES\n";
        for (int i = 0; i < N; ++i) cout << A[i] << " \n"[i == N-1];
    }
}