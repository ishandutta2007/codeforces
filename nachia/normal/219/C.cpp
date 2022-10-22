#include<bits/stdc++.h>
using namespace std;
using UL = unsigned long;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(int i = 0; i < (n); i++)

struct Problem {
    UL dp[500001];
    void Solve() {
        UL N, K; cin >> N >> K;
        string S; cin >> S;

        if (K == 2) {
            UL a, b; a = b = 0;
            rep(i, N) {
                if ((S[i] != 'A') == bool(i % 2)) a++; else b++;
            }
            cout << min(a, b) << endl;
            if (a < b) { rep(i, N) cout << ((i % 2) ? "A" : "B"); cout << endl; }
            else { rep(i, N) cout << ((i % 2) ? "B" : "A"); cout << endl; }
        }
        else {
            dp[0] = dp[1] = 0;
            for (UL i = 2; i <= N; i++) {
                if (S[i - 2] == S[i - 1]) dp[i] = i - 1;
                else dp[i] = dp[i - 1];
            }
            UL p = dp[N];
            UL ans = 0;
            while (p != 0) {
                for (char c : string("ABC")) {
                    bool ok = true;
                    if (p >= 2) if (S[p - 2] == c) ok = false;
                    if (p != N) if (S[p] == c) ok = false;
                    if (ok) { S[p - 1] = c; break; }
                }
                p -= 1;
                p = dp[p];
                ans++;
            }
            cout << ans << endl;
            cout << S << endl;
        }
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    p->Solve();
    return 0;
}