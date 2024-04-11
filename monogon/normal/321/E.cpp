
#include <cstdio>
#include <cstdlib>
#include <algorithm>

#define ll long long
using namespace std;

const int MAX_N = 4005, MAX_K = 805;
int n, k;
int u[MAX_N][MAX_N], pref[MAX_N][MAX_N], cost[MAX_N][MAX_N], dp[MAX_K][MAX_N];
char row[2 * MAX_N];
size_t len;

// compute dp[i][j] for j in [j1, j2] knowing optimal
// l value lies in [l1, l2]
void dprange(int i, int j1, int j2, int l1, int l2) {
    if(j1 > j2) return;
    int j = j1 + (j2 - j1) / 2;
    dp[i][j] = dp[i - 1][l1] + cost[j][l1];
    int minl = l1;
    int lmax = min(j, l2);
    for(int l = l1 + 1; l <= lmax; l++) {
        if(dp[i - 1][l] + cost[j][l] < dp[i][j]) {
            dp[i][j] = dp[i - 1][l] + cost[j][l];
            minl = l;
        }
    }
    dprange(i, j1, j - 1, l1, minl);
    dprange(i, j + 1, j2, minl, l2);
}

int main() {
    scanf("%d %d\n", &n, &k);
    for(int i = 0; i < n; i++) {
        fgets(row, 2 * MAX_N, stdin);
        for(int j = 0; j < n; j++) {
            u[i][j] = row[2 * j] - '0';
        }
    }
    for(int i = 0; i < n; i++) {
        pref[i][0] = pref[0][i] = 0;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            pref[i + 1][j + 1] = pref[i][j + 1] + pref[i + 1][j] - pref[i][j] + u[i][j];
        }
    }
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= i; j++) {
            cost[i][j] = (pref[i][i] + pref[j][j] - 2 * pref[i][j]) / 2;
        }
    }

    for(int i = 1; i <= k; i++) {
        dp[i][0] = 0;
    }
    for(int i = 0; i <= n; i++) {
        dp[1][i] = cost[i][0];
    }
    for(int i = 2; i <= k; i++) {
        dprange(i, 1, n, 0, n);
    }
    printf("%d\n", dp[k][n]);
}