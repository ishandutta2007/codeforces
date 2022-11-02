#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef pair<int, int> pii;

const int MAXN = 1005;
const int INF = 1e9;

int n, t, dp[MAXN][MAXN];
pii ar[MAXN];

int pw(int x) {
    int ret = 1;
    for (int i=0; i<x; i++) {
        ret <<= 1;
        if (ret >= n) return n;
    }
    return ret;
}

void setmax(int& a, int b) { if (a < b) a = b; }

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> t;
    for (int i=0; i<n; i++) cin >> ar[i].fi >> ar[i].se;
    sort(ar, ar+n); reverse(ar, ar+n);

    for (int i=0; i<MAXN; i++)
        for (int j=0; j<MAXN; j++)
            dp[i][j] = -INF;

    dp[0][pw(t-ar[0].fi)] = 0;

    for (int i=0; i<n; i++)
        for (int j=0; j<=n; j++)
            if (dp[i][j] >= 0) {
                setmax(dp[i+1][min(n, j*pw(ar[i].fi-ar[i+1].fi))], dp[i][j]);
                if (j>0) setmax(dp[i+1][min(n, (j-1)*pw(ar[i].fi-ar[i+1].fi))], dp[i][j]+ar[i].se);
            }

    int ans = 0;
    for (int i=0; i<=n; i++) ans = max(ans, dp[n][i]);
    cout << ans;
}