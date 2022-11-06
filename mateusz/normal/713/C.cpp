#include <bits/stdc++.h>

using namespace std;

const int N = 3005;

int n;
int tab[N];
long long dp[N][N], pref[N][N];

int main(int argc, char *argv[]) {
    scanf("%d", &n);

    vector<int> tmp;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
        tmp.push_back(tab[i] - i);
    }
    sort(tmp.begin(), tmp.end());

    for (int i = 1; i <= n; i++) {
        pref[i][0] = 1e18;
        for (int j = 1; j <= n; j++) {
            dp[i][j] = abs(tab[i] - (tmp[j - 1] + i)) + pref[i - 1][j];
            pref[i][j] = min(pref[i][j - 1], dp[i][j]);
        }

    }
    long long ans = 1e18;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, pref[n][i]);
    }
    printf("%lld\n", ans);

    return 0;
}