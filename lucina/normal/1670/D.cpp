#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;

int64_t f[nax];



int main() {
    int T;
    cin.tie(0)->sync_with_stdio(false);
    f[2] = 2;
    f[3] = 6;

    for (int i = 4 ; i < nax ; ++ i) {
        f[i] = max(f[i - 1], f[i]);
        for (int add = 0 ; add < 2 ; ++ add) {
            int64_t u = i / 3;
            int64_t v = u + add;
            int64_t res = i - u - v;
            int64_t ans = 2 * (u * v + u * res + res * v);
            f[i] = max(f[i], ans);
        }
    }
    for (cin >> T ; T -- ;) {
        int64_t tar;
        cin >> tar;
        int ans = lower_bound(f + 2, f + nax, tar) - f;
        cout << ans << '\n';
    }
}