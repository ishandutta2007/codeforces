#include <bits/stdc++.h>

using namespace std;

const int X = 100005;
const int N = 2000;
const int M = 1e9 + 7;

int n, m;
char word[X + 5];
int DP[2 * N + 5][2 * N + 5];

void add(int &w, int v) {
    w += v;
    if (w >= M) {
        w -= M;
    }
}

int main() {

    scanf("%d %d", &n, &m);
    scanf("%s", &word[1]);
    DP[0][0] = 1;
    for (int i = 1; i <= 2 * N; i++) {
        for (int j = 1; j <= 2 * N; j++) {
            DP[i][j] = DP[i - 1][j - 1] + DP[i - 1][j + 1];
            if (DP[i][j] >= M) DP[i][j] -= M;
        }
        DP[i][0] = DP[i - 1][1];
    }

    int otwarte = 0;
    int zamkniete = 0;
    for (int i = 1; i <= m; i++) {
        if (word[i] == '(') {
            otwarte++;
            continue;
        }
        if (word[i] == ')' && otwarte > 0) {
            otwarte--;
            continue;
        }
        if (word[i] == ')' && otwarte == 0) {
            zamkniete++;
        }
    }

    int ans = 0;
    for (int i = zamkniete; i <= n - m; i++) {
        for (int j = zamkniete; j <= i; j++) {
            if (otwarte + j - zamkniete > N)
                break;
            add(ans, (long long)DP[i][j] * DP[n - m - i][otwarte + j - zamkniete] % M);
        }
    }

    printf("%d\n", ans);
    return 0;
}