#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int n;
long long tab[N][N];
int rowX, rowY;

bool good() {
    long long goodSum = 0;
    for (int i = 1; i <= n; i++) {
        goodSum += tab[1][i];
    }

    for (int i = 1; i <= n; i++) {
        long long sum = 0;
        for (int j = 1; j <= n; j++) {
            sum += tab[i][j];
        }
        if (sum != goodSum) {
            return false;
        }
    }


    for (int i = 1; i <= n; i++) {
        long long sum = 0;
        for (int j = 1; j <= n; j++) {
            sum += tab[j][i];
        }
        if (sum != goodSum) {
            return false;
        }
    }

    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += tab[i][i];
    }
    if (sum != goodSum) {
        return false;
    }


    sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += tab[i][n - i + 1];
    }
    if (sum != goodSum) {
        return false;
    }

    return true;
}

int main() {

    scanf("%d", &n);
    if (n == 1) {
        printf("1\n");
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%lld", &tab[i][j]);
            if (tab[i][j] == 0) {
                rowX = i;
                rowY = j;
            }
        }
    }

    int r = rowX == 1 ? 2 : 1;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += tab[r][i];
    }

    long long mySum = 0;
    for (int i = 1; i <= n; i++) {
        mySum += tab[rowX][i];
    }

    long long ans = sum - mySum;
    if (ans <= 0) {
        printf("-1\n");
        return 0;
    } else {
        tab[rowX][rowY] = ans;
        if (good()) {
            printf("%lld\n", ans);
        } else {
            printf("-1\n");
        }
    }

    return 0;
}