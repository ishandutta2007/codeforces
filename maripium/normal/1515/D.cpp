#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int T; cin >> T;

    while (T--) {
        int N, L, R; cin >> N >> L >> R;
        vector<array<int, 2>> cnts(N);
        for (int i = 0; i < N; ++i) {
            int a; cin >> a;
            cnts[--a][i < L] ++;
        }
        array<int, 2> tot{};
        int p0 = 0;
        int p1 = 0;
        int r0 = 0;
        int r1 = 0;
        for (int i = 0; i < N; ++i) {
            int v = min(cnts[i][0], cnts[i][1]);
            cnts[i][0] -= v;
            cnts[i][1] -= v;
            p0 += cnts[i][0] / 2;
            p1 += cnts[i][1] / 2;
            r0 += cnts[i][0];
            r1 += cnts[i][1];
        }
        int ans = 1e9;
        for (int v = 0; v <= N; ++v) {
            if (r0 - p0 * 2 > v) continue;
            if (r1 - p1 * 2 > v) continue;
            int cnd = v;
            {
                int lo = 0, hi = p0;
                while (lo < hi) {
                    int mi = (lo + hi) >> 1;
                    if (r0 - mi * 2 <= v) hi = mi;
                    else lo = mi + 1;
                }
                cnd += lo;
            }
            {
                int lo = 0, hi = p1;
                while (lo < hi) {
                    int mi = (lo + hi) >> 1;
                    if (r1 - mi * 2 <= v) hi = mi;
                    else lo = mi + 1;
                }
                cnd += lo;
            }
            ans = min(ans, cnd);
        }
        cout << ans << '\n';
    }
}