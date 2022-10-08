
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n, c;
int a[N], b[N], dp[N][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> c;
    for(int i = 1; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i < n; i++) {
        cin >> b[i];
    }
    dp[0][0] = 0;
    dp[0][1] = c;
    for(int i = 1; i < n; i++) {
        dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + a[i];
        dp[i][1] = min(dp[i][0] + c, dp[i - 1][1] + b[i]);
    }
    for(int i = 0; i < n; i++) {
        cout << min(dp[i][0], dp[i][1]) << " ";
    }
    cout << endl;
}