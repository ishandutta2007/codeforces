#include <bits/stdc++.h>
using namespace std;

const int N = 205;
int n;
int dp[N][2 * N], t[N];

int main() {
 int te;
 cin >> te;
 while(te--) {
cin >> n;
for(int i = 1; i <= n; i++) cin >> t[i];
sort(t + 1, t + n + 1);
 for(int i = 0; i <= n; i++) {
 for(int T = 0; T <= 2*n; T++) {
 if(i == 0) dp[i][T] = 0;
 else if(T < i) dp[i][T] = INT_MAX;
 else {
 dp[i][T] = min(dp[i][T - 1], abs(T - t[i]) + dp[i - 1][T - 1]);
}
}
}
 cout << dp[n][2 * n] << '\n';
}
}