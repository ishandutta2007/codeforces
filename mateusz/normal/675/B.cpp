#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, a, b, c, d;
    scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i + a - d >= 1 && i + a - d <= n && i + b - c >= 1 && i + b - c <= n && (b + i + a - d) - c >= 1 && (b + i + a - d) - c <= n) {
            ans++;
        }
    }
    printf("%I64d\n", (long long)n * ans);

    return 0;
}