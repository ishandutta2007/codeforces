#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;

int n;
int a[nax];
int b[nax];
int dp[nax];
int last[nax];
int first[nax];
int freq[nax];
int all_freq[nax];

int solve () {
    scanf("%d", &n);

    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d", a + i);
        b[i] = a[i];
        dp[i] = last[i] = first[i] = -1;
        freq[i] = all_freq[i] = 0;
    }

    sort(b + 1, b + 1 + n);
    int m = unique(b + 1, b + 1 + n) - b - 1;

    for (int i = 1 ; i <= n ; ++ i) {
        a[i] = lower_bound(b + 1, b + 1 + m, a[i]) - b;
        ++ all_freq[a[i]];
    }

    for (int i = 1 ; i <= n ; ++ i) {
        int x = a[i];

        if (last[x - 1] != -1 && first[x - 1] != -1 && freq[x - 1] == all_freq[x - 1]) {
            dp[i] = max(dp[i], dp[first[x - 1]] + freq[x - 1]);
        }

        if (last[x] != -1) {
            dp[i] = max(dp[i], dp[last[x]] + 1);
        }

        if (last[x - 1] != -1) {
            dp[i] = max(dp[i], freq[x - 1] + 1);
        }

        dp[i] = max(dp[i], 1);
        if (first[x] == -1) first[x] = i;
        last[x] = i;
        ++ freq[x];
    }

    return n - *max_element(dp + 1, dp + 1 + n);
}

int main () {
    int T;

    for (cin >> T ; T -- ; ) {
        printf("%d\n", solve());
    }
}