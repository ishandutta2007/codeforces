#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

#define p(x) cout << #x << ": " << (x) << endl

const int MAXA = 305;

int n, a[5], memo[MAXA][MAXA];

int calc(int x, int y) {
    if (memo[x][y] != -1) return memo[x][y];
    for (int i=1; i<=x; i++) {
        if (!calc(x-i, y)) return memo[x][y] = 1;
    }
    for (int i=1; i<=y; i++) {
        if (!calc(x, y-i)) return memo[x][y] = 1;
    }
    for (int i=1; i<=min(x, y); i++) {
        if (!calc(x-i, y-i)) return memo[x][y] = 1;
    }
    return memo[x][y] = 0;
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    if (n == 1) {
        if (a[0] != 0) printf("BitLGM\n");
        else printf("BitAryo\n");
    } else if (n == 2) {
        for (int i=0; i<MAXA; i++)
            for (int j=0; j<MAXA; j++)
                memo[i][j] = -1;
        memo[0][0] = 0;
        if (calc(a[0], a[1])) printf("BitLGM\n");
        else printf("BitAryo\n");
    } else {
        if ((a[0] ^ a[1] ^ a[2]) != 0) printf("BitLGM\n");
        else printf("BitAryo\n");
    }
}