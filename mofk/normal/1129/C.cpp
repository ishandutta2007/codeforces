#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
void add(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}
int n;
int f[3005][3005];
int a[3005];
int valid[16];
int lcp[3005][3005];
int _free[3005];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    valid[3] = valid[5] = valid[14] = valid[15] = 1;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = n; i >= 1; --i) {
        for (int j = i; j >= 1; --j) {
            if (a[i] != a[j]) lcp[i][j] = 0;
            else lcp[i][j] = lcp[i+1][j+1] + 1;
            if (i != j) _free[i] = max(_free[i], i + lcp[i][j]);
        }
    }
    int ans = 0;
    int cur = 0;
    f[1][0] = 1;
    for (int i = 1; i <= n; ++i) {
        int x = a[i];
        cur = cur * 2 + x;
        f[i+1][i] = 1;
        for (int j = 1; j <= i; ++j) {
            if (i >= j)     add(f[j][i], f[j][i-1]);
            if (i >= j - 1) add(f[j][i], f[j][i-2]);
            if (i >= j - 2) add(f[j][i], f[j][i-3]);
            if (i >= j - 3 && !valid[cur]) add(f[j][i], f[j][i-4]);
            if (i >= _free[j]) add(ans, f[j][i]);
        }
        cout << ans << '\n';
        if (i >= 4) cur %= 8;
    }
    return 0;
}