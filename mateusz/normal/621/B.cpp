#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int cnt[N][N];
int diag1[2 * N], diag2[2 * N];
int n, x, y;

int main() {

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &x, &y);
        diag1[1000 - x + y]++;
        diag2[x + y]++;
    }

    long long ans = 0;
    for (int i = 1; i <= 2000; i++) {
        ans += (long long)diag1[i] * (diag1[i] - 1) / 2;
        ans += (long long)diag2[i] * (diag2[i] - 1) / 2;
    }

    printf("%I64d\n", ans);

    return 0;
}