#include <bits/stdc++.h>

using namespace std;

using ld = long double;

ld read_ld() {
    int x; cin >> x;
    return ld(x);
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, H; cin >> N >> H;
    vector<int64_t> X(N), Y(N); for (int i = 0; i < N; ++i) cin >> X[i] >> Y[i];
    ld ans = hypotl(ld(X[N-2]-X[N-1]), ld(Y[N-2]-Y[N-1]));
    int64_t q = Y[N-1]+H-Y[N-2], p = X[N-1] - X[N-2];
    int prv = N-2;
    for (int i = N-3; i >= 0; --i) {
        int64_t dp = X[N-1] - X[i];
        int64_t dq = Y[N-1] + H - Y[i];
        if (dq * p <= dp * q) {
            if (dq * p == dp * q && prv == i+1) {
                ans += hypotl(X[i] - X[i+1], Y[i] - Y[i+1]);
            } else {
        ld v0 = Y[N-1] + H - ld(X[N-1] - X[i]) / ld(X[N-1] - X[prv]) * ld(Y[N-1] + H - Y[prv]);
            ld v1 = Y[N-1] + H - ld(X[N-1] - X[i+1]) / ld(X[N-1] - X[prv]) * ld(Y[N-1] + H - Y[prv]);
            ld l0 = abs(Y[i] - v0);
            ld l1 = abs(Y[i+1] - v1);
            ans += ld(l0) / (l0+l1) * hypotl(ld(X[i]-X[i+1]), ld(Y[i] - Y[i+1]));
            }
            p = dp;
            q = dq;
            prv = i;
        }
    }
    cout << fixed << setprecision(10) << ans << '\n';
    return 0;
}