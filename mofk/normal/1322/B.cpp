#include <bits/stdc++.h>

using namespace std;

int n;
int a[400005];
int f[1 << 26];

int main(void) {
    mt19937 rng(time(NULL));
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    //for (int i = 1; i <= n; ++i) a[i] = rng() % 8;
    //for (int i = 1; i <= n; ++i) cout << a[i] << ' '; cout << endl;
    int ans = 0;
    for (int j = 0; j < 25; ++j) {
        int all = (1 << j + 1) - 1;
        for (int i = 1; i <= n; ++i) ++f[a[i] & all];
        int add = 0;
        for (int i = 0; i < (1 << j+1); ++i)
            if ((i + i) >> j & 1)
                add = (add + 1LL * f[i] * (f[i] - 1) / 2) & 1;
        for (int i = 0; i < (1 << j+1) - 1; ++i) f[i+1] += f[i];
        int l = (1 << j) - 1, r = (1 << j+1) - 1;
        for (int i = 0; i < (1 << j); ++i) {
            int s = f[r] - f[max(l, i)];
            int b = f[i] - (i ? f[i-1] : 0);
            add = (add + 1LL * s * b) & 1;
            --l, --r;
        }
        l = r = (1 << j+1) - 1;
        for (int i = (1 << j); i < (1 << j+1); ++i) {
            int s = f[r] - f[max(l, i)];
            int b = f[i] - (i ? f[i-1] : 0);
            add = (add + 1LL * s * b) & 1;
            --l;
        }
        ans ^= (add << j);
        for (int i = 0; i <= all; ++i) f[i] = 0;
    }
    cout << ans << endl;
    return 0;
}