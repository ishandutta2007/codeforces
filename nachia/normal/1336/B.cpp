#include<bits/stdc++.h>
using namespace std;
using UL = unsigned long;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(int i = 0; i < (n); i++)

LL f(LL x, LL y, LL z) {
    return (x - y) * (x - y) + (z - y) * (z - y) + (x - z) * (x - z);
}

struct Problem {

    void Loop() {
        UL N[3]; rep(i, 3) cin >> N[i];
        vector<LL> W[3];
        rep(i, 3) {
            W[i].resize(N[i]);
            rep(j, N[i]) cin >> W[i][j];
            sort(W[i].begin(), W[i].end());
            W[i].push_back(W[i].back());
        }
        LL ans = (LL)5e18;
        rep(t, 3) {
            UL p, q; p = q = 1;
            rep(i, N[0]) {
                while (p < N[1] - 1) { if (W[1][p] > W[0][i]) break; p++; }
                while (q < N[2] - 1) { if (W[2][q] > W[0][i]) break; q++; }
                ans = min(ans, f(W[0][i], W[1][p - 1], W[2][q - 1]));
                ans = min(ans, f(W[0][i], W[1][p], W[2][q - 1]));
                ans = min(ans, f(W[0][i], W[1][p - 1], W[2][q]));
                ans = min(ans, f(W[0][i], W[1][p], W[2][q]));
            }

            swap(W[0], W[1]); swap(W[1], W[2]);
            swap(N[0], N[1]); swap(N[1], N[2]);
        }
        cout << ans << endl;
    }

    void Solve() {
        UL t; cin >> t; rep(i, t) Loop();
    }
};

int main() {
    cin.tie(0);
    unique_ptr<Problem> p(new Problem());
    p->Solve();
    return 0;
}