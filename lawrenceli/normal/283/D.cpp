#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 5005;

int n, e[MAXN], dp[MAXN];
ll a[MAXN], b[MAXN];

int main() {
    ios :: sync_with_stdio(false);

    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        while (!(a[i] & 1))
            a[i] >>= 1, e[i] ++;
        b[i] = a[i];
    }

    for (int i=1; i<=n; i++) {
        for (int j=0; j<i; j++)
            if (j == 0 || b[j-1] % b[i-1] == 0 && (e[j-1] + i - j == e[i-1] || e[i-1] <= i - j - 1))
                dp[i] = max(dp[i], dp[j] + 1);
    }

    int ans = 0;
    for (int i=0; i<=n; i++) ans = max(ans, dp[i]);

    cout << n - ans << endl;
    return 0;
}