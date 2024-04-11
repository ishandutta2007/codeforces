#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 5001;

int dp[N][N];
int n;
char s[N];
int d1[N];
int d2[N];

bool isPalindrome(int l, int r) {
    if(l % 2 == r % 2) {
        return l >= (l + r) / 2 - d1[(l + r) / 2] + 1;
    }else {
        return d2[(l + r) / 2] > 0 && l >= (l + r) / 2 - d2[(l + r) / 2] + 1;
    }
}

int cnt[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%s", &s);

    n = strlen(s);

    for(int l = 0, r = -1, i = 0;i < n;i++) {
        if(i >= l && i <= r) {
            d1[i] = min(r - i + 1, d1[l + r - i]);
        }
        while(i + d1[i] < n && i - d1[i] >= 0 && s[i + d1[i]] == s[i - d1[i]]) {
            d1[i]++;
        }
        if(i + d1[i] - 1 > r) {
            l = i - d1[i] + 1;
            r = i + d1[i] - 1;
        }
    }

    for(int l = 0, r = -1, i = 0;i < n;i++) {
        if(i + 1 == n || s[i] != s[i + 1]) continue;
        if(i >= l && i <= r) {
            d2[i] = min(r - i, d2[l + r - i - 1]);
        }
        while(i - d2[i] >= 0 && i + d2[i] + 1 < n && s[i - d2[i]] == s[i + d2[i] + 1]) {
            d2[i]++;
        }
        if(i + d2[i] > r) {
            l = i - d2[i] + 1;
            r = i + d2[i];
        }
    }

    for(int i = 0;i < n;i++) {
        dp[i][i] = 1;
    }

    for(int len = 2;len <= n;len++) {
        for(int m, r, l = 0;l + len - 1 < n;l++) {
            r = l + len - 1;
            if(!isPalindrome(l, r)) continue;
            if(len % 2) {
                dp[l][r] = min(dp[l][(l + r) / 2 - 1], dp[(l + r) / 2 + 1][r]) + 1;
            }else {
                dp[l][r] = min(dp[l][(l + r) / 2], dp[(l + r) / 2 + 1][r]) + 1;
            }
        }
    }

    for(int l = 0;l < n;l++) {
        for(int r = l;r < n;r++) {
            cnt[min(n, dp[l][r])]++;
        }
    }

    for(int i = n - 1;i >= 0;i--) {
        cnt[i] += cnt[i + 1];
    }

    for(int i = 1;i <= n;i++) {
        printf("%d ", cnt[i]);
    }

    printf("\n");

    return 0;
}