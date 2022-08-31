#include <bits/stdc++.h>
using namespace std;
const int mod = (int)1e9 + 7;
int n, m;
const int maxN = 1005;
char a[55][maxN];
long long s[maxN];
int f[maxN];
int c[maxN][maxN];
void calc() {
    c[0][0] = 1;
    for (int i = 1; i < maxN; i++) {
        for (int j = 0; j < maxN; j++) {
            c[i][j] = c[i - 1][j];
            if (j > 0) c[i][j] += c[i - 1][j - 1];
            if (c[i][j] >= mod) c[i][j] -= mod;
        }
    }
    f[0] = 1;
    for (int i = 1; i < maxN; i++) {
        for (int j = 1; j <= i; j++) {
            f[i] += (1LL * f[i - j] * c[i - 1][j - 1]) % mod;
            if (f[i] >= mod) f[i] -= mod;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    calc();
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == '1') s[j] |= (1LL << i);
        }
    }
    sort(s, s + m);
    long long prv = s[0];
    int cur = 0;
    int ans = 1;
    for (int i = 0; i < m; i++) {
        if (s[i] == prv) {
            cur++;
        }
        else {
            ans = (1LL * ans * f[cur]) % mod;
            cur = 1;
            prv = s[i];
        }
    }
    ans = (1LL * ans * f[cur]) % mod;
    cout << ans;
    return 0;
}