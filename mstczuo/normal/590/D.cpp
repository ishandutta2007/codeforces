# include <iostream>
# include <cstdio>
# include <cstring>

using namespace std;

int n, k, s;

int f[2][150+2][11175+2];
int a[150+2];

int main() {
    cin >> n >> k >> s;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    s = min(s, n * (n - 1) / 2);
    for(int i = 0; i < n; ++i) {
        memset(f[(i+1)&1], 0, sizeof(f[0]));
        for(int j = 0; j <= i; ++j) {
            for(int k = 0; k <= s; ++k) {
                int val = f[i&1][j][k];
                f[(i+1)&1][j][k] = max(f[(i+1)&1][j][k], val + a[i+1]);
                f[(i+1)&1][j+1][k+(i-j)] = max(f[(i+1)&1][j+1][k+(i-j)], val);
            }
        }
    }
    int sum = 0;
    for(int i = 1; i <= n; ++i) sum += a[i];
    cout << sum - f[n&1][k][s] << endl;
}