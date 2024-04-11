#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int N, M, A, B; cin >> N >> M >> A >> B;
        vector<int> S(M); for (int &s : S) cin >> s;
        if (A > B) {
            A = N+1-A;
            B = N+1-B;
        }
        assert(A < B);
        sort(S.begin(), S.end());
        int low = 0, high = M;
        while (low < high) {
            int mid = (low + high + 1) >> 1;
            if ([&]() {
                if (B - mid <= A) return false;
                for (int i = 0; i < mid; ++i) {
                    if (S[i] + mid - i > B-1) return false;
                }
                return true;
            }()) low = mid;
            else high = mid - 1;
        }
        cout << low << '\n';
    }
}