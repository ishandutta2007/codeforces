#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = (int)1e9 + 7;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
const int maxN = 105;
const int maxS = maxN * 26;
int dp[maxN][maxS];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    dp[0][0] = 1;
    for (int i = 0; i + 1 < maxN; i++) {
        for (int j = 0; j <= i * 25; j++) {
            for (int k = 0; k < 26; k++) {
                dp[i + 1][j + k] = sum(dp[i + 1][j + k], dp[i][j]);
            }
        }
    }
    int tst;
    cin >> tst;
    while (tst--) {
        string s;
        cin >> s;
        int sm = 0;
        for (int k = 0; k < s.size(); k++) sm += s[k] - 'a';
        cout << sum(dp[s.size()][sm], mod - 1) << '\n';
    }
    return 0;
}