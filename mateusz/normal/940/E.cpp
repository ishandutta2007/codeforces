#include <bits/stdc++.h>

using namespace std;

const int N = 100005, BASE = 131072, SQRT = 300, LOG = 17;
const long long INF = 1e18;

int n, c;
int pot[N];
int tab[N];
long long sumPref[N];
long long dp[N];
int rmq[20][100005];

int getMin(int x, int y) {
    int d = y - x + 1;
    int p = pot[d];
    return min(rmq[p][x], rmq[p][y - (1 << p) + 1]);
}

void DP() {
    for (int i = 0; i <= n; i++) {
        dp[i] = INF;
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = min(dp[i - 1] + tab[i], (i < c ? INF : dp[i - c] + sumPref[i] - sumPref[i - c] - getMin(i - c + 1, i)));
        
    }
    printf("%lld\n", dp[n]);
}

int main() {

    scanf("%d %d", &n, &c);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
        sumPref[i] = sumPref[i - 1] + tab[i];
        rmq[0][i] = tab[i];
    }
    
    pot[1] = 0;
    for (int i = 2; i <= n; i++) {
        if ((1 << (pot[i - 1] + 1)) > i) {
            pot[i] = pot[i - 1];
        } else {
            pot[i] = pot[i - 1] + 1;
        }
    }
    for (int l = 1; l <= LOG; l++) {
        for (int i = 1; i <= n - (1 << (l - 1)); i++) {
            rmq[l][i] = min(rmq[l - 1][i], rmq[l - 1][i + (1 << (l - 1))]);
        }
    }
    
    DP();
    
    return 0;
}