#include <bits/stdc++.h>

using namespace std;

int go(int x) {
    int lo = 0, hi = 100000;
    while (lo < hi) {
        int mid = (lo+hi+1) / 2;
        if ((long long)(mid)*(mid+1)/2 <= x) lo = mid;
        else hi = mid-1;
    }
    return lo;
}

const int MAXN = 200100;
const int MOD = 1e9 + 7;

int dp[MAXN];

int main() {
    int r, g;
    cin >> r >> g;
    int h = go(r+g);
    dp[0] = 1;
    for (int i=1; i<=h; i++)
        for (int j=MAXN-1; j>=0; j--) {
            int k = j+i;
            if (k<MAXN) dp[k] = (dp[k]+dp[j])%MOD;
        }
    int ans = 0;
    for (int i=0; i<=r; i++)
        if (h*(h+1)/2-i <= g)
            ans = (ans + dp[i])%MOD;
    cout << ans;
}