#include <bits/stdc++.h>
using namespace std;
int c[4005][4005];
const int MOD = (int)1e9 + 7;
void calc() {
    for (int i = 0; i <= 4000; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
            if (c[i][j] >= MOD) c[i][j] -= MOD;
        }
    }
}
long long f[4005];
long long g[4005];
int n;
int main() {
    f[0] = 0; g[0] = 1;
    calc();
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            g[i + 1] += g[j] * c[i][j];
            g[i + 1] %= MOD;
        }
        g[i + 1] += g[i];
        g[i + 1] %= MOD;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            f[i + 1] += f[j] * c[i][j];
            f[i + 1] %= MOD;
        }
        f[i + 1] += g[i];
        f[i + 1] %= MOD;
    }
    cout << f[n];
    return 0;
}