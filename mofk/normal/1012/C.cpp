#include <bits/stdc++.h>

using namespace std;

///deo biet nua, minh dot may bai DP kieu nay lam
int n;
long long meo[5005];
long long f[5005][5005][2];
const long long inf = 1e15;

long long cost(long long x, long long y) {
    return max(0LL, x - y);
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    ///bai de hieu qua <3

    ///nhung chua biet lam
    ///wtf
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> meo[i];

    ///take this Aria xdddd
    memset(f, 0x7f, sizeof f);
    f[1][0][0] = 0;
    f[1][1][1] = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (f[i][j][0] < inf) {///tranh tran so
                f[i+1][j+1][1] = min(f[i+1][j+1][1], f[i][j][0] + cost(meo[i], meo[i+1] - 1));
                f[i+1][j][0] = min(f[i+1][j][0], f[i][j][0]);
            }
            if (f[i][j][1] < inf) {
                f[i+2][j+1][1] = min(f[i+2][j+1][1], f[i][j][1] + cost(meo[i+1], min(meo[i], meo[i+2]) - 1));
                f[i+1][j][0] = min(f[i+1][j][0], f[i][j][1] + cost(meo[i+1], meo[i] - 1));
            }
        }
    }
    for (int i = 1; i <= (n + 1) / 2; ++i)
        cout << min(f[n][i][0], f[n][i][1]) << ' ';
    cout << endl;
    return 0;
}