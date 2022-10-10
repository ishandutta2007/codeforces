#include <bits/stdc++.h>
#define maxn 1000100
using namespace std;
int dp[maxn], t[maxn], n, a;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i=1; i<=n; ++i) cin >> t[i];
    dp[0] = 0;
    int wyn = 0;
    t[0] = -1000000010;
    for (int i=1; i<=n; ++i) {
      if (t[i] > t[i-1]) dp[i] = dp[i-1] + 1;
      else dp[i] = 1;
      if (wyn < dp[i]) wyn = dp[i];
    }
    cout << wyn;
}