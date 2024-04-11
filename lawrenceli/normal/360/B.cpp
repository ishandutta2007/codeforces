#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 2005;

int n, k, a[MAXN], dp[MAXN];

bool pos(ll mid) {
    for (int i=0; i<n; i++) dp[i] = i;
    dp[n] = 1e9;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<=n; j++) {
            if (j == n || abs(a[j] - a[i]) <= ll(j-i) * mid) {
                dp[j] = min(dp[j], dp[i] + j - i - 1);
            }
        }
    }
    return dp[n] <= k;
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d %d", &n, &k);
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    ll lo = 0, hi = 2e9;
    while (lo < hi) {
        ll mid = (lo + hi) / 2;
        if (pos(mid)) hi = mid;
        else lo = mid + 1;
    }
    printf("%d\n", lo);
    return 0;
}