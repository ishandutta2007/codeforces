#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int A[N], B[N], prefA[N][40], prefB[N][40];
int n;

int main() {

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        for (int j = 0; j < 31; j++) {
            prefA[i][j] = A[i] % 2;
            A[i] /= 2;
            prefA[i][j] += prefA[i - 1][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &B[i]);
        for (int j = 0; j < 31; j++) {
            prefB[i][j] = B[i] % 2;
            B[i] /= 2;
            prefB[i][j] += prefB[i - 1][j];
        }
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int or1 = 0;
            for (int k = 30; k >= 0; k--) {
                or1 *= 2;
                or1 += (prefA[j][k] - prefA[i - 1][k] > 0);
            }

            int or2 = 0;
            for (int k = 30; k >= 0; k--) {
                or2 *= 2;
                or2 += (prefB[j][k] - prefB[i - 1][k] > 0);
            }
            ans = max(ans, (long long)or1 + or2);
        }
    }

    printf("%I64d\n", ans);

    return 0;
}