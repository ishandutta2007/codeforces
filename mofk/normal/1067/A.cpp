#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;
int n;
int a[100005];
int f[2][205][3]; //<=>
int s[2][205][3]; //<=>

void add(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    if (a[1] == -1) for (int i = 1; i <= 200; ++i) f[0][i][0] = 1;
    else f[0][a[1]][0] = 1;
    for (int i = 1; i <= 200; ++i) s[0][i][0] = (s[0][i-1][0] + f[0][i][0]) % mod;
    int now = 0, nxt = 1;
    for (int i = 2; i <= n; ++i) {
        memset(f[nxt], 0, sizeof f[nxt]);
        memset(s[nxt], 0, sizeof s[nxt]);
        if (a[i] == -1) {
            for (int j = 1; j <= 200; ++j) {
                f[nxt][j][0] = ((long long)s[now][j-1][0] + s[now][j-1][1] + s[now][j-1][2]) % mod;
                f[nxt][j][1] = ((long long)f[now][j][0] + f[now][j][1] + f[now][j][2]) % mod;
                add(f[nxt][j][2], (s[now][200][1] + mod - s[now][j][1]) % mod);
                add(f[nxt][j][2], (s[now][200][2] + mod - s[now][j][2]) % mod);
            }
        }
        else {
            int j = a[i];
            f[nxt][j][0] = ((long long)s[now][j-1][0] + s[now][j-1][1] + s[now][j-1][2]) % mod;
            f[nxt][j][1] = ((long long)f[now][j][0] + f[now][j][1] + f[now][j][2]) % mod;
            add(f[nxt][j][2], (s[now][200][1] + mod - s[now][j][1]) % mod);
            add(f[nxt][j][2], (s[now][200][2] + mod - s[now][j][2]) % mod);
        }
        for (int j = 1; j <= 200; ++j) for (int k = 0; k < 3; ++k) s[nxt][j][k] = (s[nxt][j-1][k] + f[nxt][j][k]) % mod;
        swap(now, nxt);
    }
    int ans = (s[now][200][1] + s[now][200][2]) % mod;
    cout << ans << endl;
    return 0;
}