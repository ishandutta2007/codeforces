#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

int main() {
    UL N; cin >> N;
    vector<UL> A(N); rep(i, N) cin >> A[i];
    UL ans = 0;
    rep(b, 24) {
        vector<UL> sorted[2];
        UL mask = 1 << b;
        rep(i, N) {
            if (A[i] & mask) sorted[1].push_back(A[i]);
            else sorted[0].push_back(A[i]);
        }
        ans ^= (ULL(sorted[0].size()) * sorted[1].size() % 2) << b;

        rep(i,sorted[0].size())
            A[i] = sorted[0][i];
        rep(i,sorted[1].size())
            A[i + sorted[0].size()] = sorted[1][i];

        mask = (1 << (b + 1)) - 1;
        UL q; q = N;
        for (UL p = 0; p < N; p++) {
            while (true) {
                if (q <= p) break;
                if ((A[q - 1] & mask) + (A[p] & mask) <= mask) break;
                q--;
            }
            q = max(q, p + 1);
            ans ^= ((N - q) % 2) << (b + 1);
        }
    }
    cout << ans << endl;
    return 0;
}