#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define left  rwrwerrw
#define right gagoaosag
const int maxN = (int)1e6 + 10;
const int mod = (int)1e9 + 7;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int left[maxN];
int right[maxN];
// to the left >= x
// to the right < x
const int INF = (int)1e9 + 10;
int n, k;
int a[maxN];
int dp[maxN];
int main() {
    srand(time(0));
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = sum(dp[i - 1], (i - 1) / (k - 1));
    }
    a[0] = INF;
    a[n + 1] = INF;
    stack < int > s;
    s.push(0);
    for (int i = 1; i <= n; i++) {
        while (1) {
            if (a[i] < a[s.top()]) {
                left[i] = s.top();
                s.push(i);
                break;
            }
            else if (a[i] == a[s.top()]) {
                left[i] = s.top();
                s.pop();
                s.push(i);
                break;
            }
            else {
                s.pop();
            }
        }
    }
    while (!s.empty()) s.pop();
    s.push(n + 1);
    for (int i = n; i >= 1; i--) {
        while (1) {
            if (a[i] < a[s.top()]) {
                right[i] = s.top();
                s.push(i);
                break;
            }
            else s.pop();
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int l = max(1, left[i] + 1);
        int r = min(n, right[i] - 1);
        int cur = dp[r - l + 1];
        cur = sub(cur, dp[i - l]);
        cur = sub(cur, dp[r - i]);
        ans = sum(ans, mult(cur, a[i]));
    }
    cout << ans;
    return 0;
}