#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 5005;
const int MOD = 1e9 + 7;

int n, pw[MAXN], z[MAXN][MAXN];
char s[MAXN];

void init() {
    pw[0] = 1;
    for (int i=1; i<MAXN; i++)
        pw[i] = (ll(pw[i-1])*2)%MOD;

    for (int i=0; i<n; i++) {
        int l = i, r = i;
        for (int j=i+1; j<n; j++) {
            if (r<j) {
                l = r = j;
                while (r<n && s[r] == s[r-l+i]) r++;
                z[i][j] = r-l;
                r--;
            } else {
                if (j+z[i][j-l+i]-1 >= r) {
                    l = j;
                    while (r<n && s[r] == s[r-l+i]) r++;
                    z[i][j] = r-l;
                    r--;
                } else z[i][j] = z[i][j-l+i];
            }
        }
    }
}

bool cmp(int a, int b) { //a...b-1 <= b...(same length)
    int k = z[a][b];
    if (a+k >= b) return 1; //equal
    return s[a+k] < s[b+k];
}

int dp[MAXN][MAXN], p[MAXN][MAXN];

void go1() {
    for (int i=1; i<=n; i++) dp[i][0] = 1;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<i; j++) {
            if (s[j] == '0') continue;
            if (2*j-i < 0) dp[i][j] = (dp[i][j]+p[j][0])%MOD;
            else {
                int k = 2*j-i;
                if (cmp(k, j)) dp[i][j] = (dp[i][j]+p[j][k])%MOD;
                else dp[i][j] = (dp[i][j]+p[j][k+1])%MOD;
            }
        }
        p[i][i] = dp[i][i];
        for (int j=i-1; j>=0; j--)
            p[i][j] = (p[i][j+1]+dp[i][j])%MOD;
    }
    int ans = 0;
    for (int i=0; i<n; i++)
        ans = (ans+dp[n][i])%MOD;
    cout << ans << '\n';
}

void go2() {
    for (int i=0; i<MAXN; i++)
        for (int j=0; j<MAXN; j++)
            dp[i][j] = 1000000;
    for (int i=1; i<=n; i++) dp[i][0] = 1;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<i; j++) {
            if (s[j] == '0') continue;
            if (2*j-i < 0) dp[i][j] = min(dp[i][j], p[j][0]+1);
            else {
                int k = 2*j-i;
                if (cmp(k, j)) dp[i][j] = min(dp[i][j], p[j][k]+1);
                else dp[i][j] = min(dp[i][j], p[j][k+1]+1);
            }
        }
        p[i][i] = dp[i][i];
        for (int j=i-1; j>=0; j--)
            p[i][j] = min(p[i][j+1], dp[i][j]);
    }
    int ans = 1e9;
    for (int i=max(0, n-20); i<n; i++) {
        int x = 0;
        for (int j=i; j<n; j++)
            x += (s[j]-'0')*(pw[n-1-j]);
        if (dp[n][i] <= 5010) ans = min(ans, dp[n][i]+x);
    }
    if (ans < 1e9) {
        cout << ans << '\n';
        return;
    }

    for (int i=n-1; i>=0; i--)
        if (dp[n][i] <= 5010) {
            int x = 0;
            for (int j=i; j<n; j++)
                x = (ll(x)+ll(s[j]-'0')*(pw[n-1-j])%MOD)%MOD;
            cout << (dp[n][i]+x)%MOD << '\n';
            return;
        }
    assert(0);
}

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> s;
    n = strlen(s);

    init();
    go1();
    go2();

    return 0;
}