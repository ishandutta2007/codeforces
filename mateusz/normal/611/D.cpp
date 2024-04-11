#include <bits/stdc++.h>

using namespace std;

const int N = 5005, P = 257, M = 1000000007;

int n;
char slowo[N];
int hasz[N], pot[N];
int dp[N][N];

void add(int &w, int v) {
    w += v;
    if (w >= M) {
        w -= M;
    }
}

int fp[N][N];

int cmp(int pocA, int konA, int pocB, int konB) {
    if (konA - pocA < konB - pocB) {
        return -1;
    } else if (konA - pocA > konB - pocB) {
        return 1;
    }
    if (pocA + fp[pocA][pocB] - 1 > konA) return 0;
    if (slowo[pocA + fp[pocA][pocB] - 1] < slowo[pocB + fp[pocA][pocB] - 1]) return -1;
    else return 0;
    
}

int main() {
    
    scanf("%d", &n);
    scanf("%s", &slowo[1]);
    
    for (int i = n; i >= 1; i--) {
        for (int j = i + 1; j <= n; j++) {
            if (slowo[i] != slowo[j]) {
                fp[i][j] = 1;
            } else {
                fp[i][j] = fp[i + 1][j + 1] + 1;
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        int wsk = i;
        for (int j = i; j >= 2; j--) {
            wsk = min(wsk, j);
            add(dp[i][j], dp[i][j + 1]);
            while (wsk > 1 && cmp(wsk - 1, j - 1, j, i) < 0) {
                wsk--;
            }
            if (slowo[j] != '0')
            add(dp[i][j], dp[j - 1][wsk]);
        }
        if (slowo[1] != '0')
        dp[i][1] = 1;
        else
        dp[i][1] = 0;
        add(dp[i][1], dp[i][2]);
    }
    
    printf("%d\n", dp[n][1]);
    
    return 0;
}