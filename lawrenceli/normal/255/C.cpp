#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

const int MAXN = 4010;

int n;
int b[MAXN], dp[MAXN][MAXN][2];
map<int, int> mp;
int cnt;

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &b[i]);
        mp[b[i]] = 0;
    }
    for (typeof(mp.begin()) it = mp.begin(); it != mp.end(); it++) {
        mp[it->first] = cnt++;
    }
    for (int i=0; i<n; i++) b[i] = mp[b[i]];
    for (int i=0; i<MAXN; i++) {
        for (int j=0; j<MAXN; j++) {
            dp[i][j][0] = dp[i][j][1] = -1e9;
        }
    }
    for (int i=0; i<n; i++) {
        for (int q=0; q<n; q++) {
            int d1, d2;
            if (b[i] - q >= 0) d1 = dp[b[i] - q][q][0] + 1;
            if (b[i] + q < n) d2 = dp[b[i] + q][q][1] + 1;
            if (b[i] - q >= 0) dp[b[i]][q][1] = max(dp[b[i]][q][1], d1);
            if (b[i] + q < n) dp[b[i]][q][0] = max(dp[b[i]][q][0], d2);
            dp[b[i]][q][0] = max(dp[b[i]][q][0], 1);
            dp[b[i]][q][1] = max(dp[b[i]][q][1], 1);
        }
    }
    int ret = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<2; k++) {
                ret = max(ret, dp[i][j][k]);
            }
        }
    }
    printf("%d\n", ret);
}