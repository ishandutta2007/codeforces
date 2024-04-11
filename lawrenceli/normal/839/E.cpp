#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

int n, k;
int a[40][40];

bool conn(int mask, int s = 0) {
    for (int i = 0; i < 20; i++)
        if (mask & 1 << i)
            for (int j = 0; j < 20; j++)
                if ((mask & 1 << j) && !a[i + s][j + s])
                    return 0;
    return 1;
}

ld val(int ma) {
    return ld(k) * k * (ma - 1) / (2 * ma);
}

int dp[1<<20];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (i == j) a[i][j] = 1;
        }

    if (n <= 20) {
        int ma = 0;
        for (int i = 0; i < 1 << n; i++)
            if (conn(i))
                ma = max(ma, __builtin_popcount(i));
        cout << fixed << setprecision(10) << val(ma) << '\n';
        return 0;
    }

    for (int i = 0; i < 1 << 20; i++)
        if (conn(i))
            dp[i] = __builtin_popcount(i);

    for (int i = 0; i < 1 << 20; i++)
        for (int j = 0; j < 20; j++)
            dp[i | 1 << j] = max(dp[i | 1 << j], dp[i]);

    int ma = 0;
    int n1 = n - 20;
    for (int i = 0; i < 1 << n1; i++)
        if (conn(i, 20)) {
            int x = 0;
            for (int j = 0; j < 20; j++) {
                bool good = 1;
                for (int k = 0; k < n1; k++)
                    if ((i & 1 << k) && !a[j][k + 20]) {
                        good = 0;
                        break;
                    }
                if (good) x |= 1 << j;
            }
            ma = max(ma, __builtin_popcount(i) + dp[x]);
        }

    cout << fixed << setprecision(10) << val(ma) << '\n';
}