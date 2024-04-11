#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int n, a, b;
int seat[N][N];

int main() {

    scanf("%d %d %d", &n, &a, &b);
    if (n > a * b) {
        printf("-1\n");
        return 0;
    }

    int id = 0;
    for (int i = 1; i <= a; i++) {
        if (i % 2 == 1) {
            for (int j = 1; j <= b; j++) {
                seat[i][j] = ++id;
            }
        } else {
            for (int j = b; j >= 1; j--) {
                seat[i][j] = ++id;
            }
        }
    }

    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            printf("%d ", seat[i][j] > n ? 0 : seat[i][j]);
        }
        printf("\n");
    }

    return 0;
}