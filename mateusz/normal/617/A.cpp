#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

int x;
int dp[N];

int main() {

    scanf("%d", &x);

    for (int i = 1; i <= x; i++) dp[i] = 1e9;

    for (int i = 1; i <= x; i++) {
        for (int j = i - 1; j >= max(0, i - 5); j--) {
            dp[i] = min(dp[i], dp[j] + 1);
        }
    }

    printf("%d\n", dp[x]);

    return 0;
}