
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2005;
int n, h, l, r, a[N], dp[N][N];

int mod(int j) {
    return ((j % h) + h) % h;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> h >> l >> r;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 1; i < h; i++) dp[0][i] = -1;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < h; j++) {
            dp[i][j] = max(dp[i - 1][mod(j - a[i - 1])], dp[i - 1][mod(j - a[i - 1] + 1)]);
            if(l <= j && j <= r && dp[i][j] != -1) {
                dp[i][j]++;
            }
        }
    }
    cout << *max_element(dp[n], dp[n] + h) << endl;
}