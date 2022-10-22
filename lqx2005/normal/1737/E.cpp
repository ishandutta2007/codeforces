#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define ROF(i, r, l) for(int i = (r); i >= (l); i--)
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define pr pair<int, int>
using namespace std;
const int N = 1e6 + 10, P = 1e9 + 7;
int n, ip2[N];
int dp[N];
int power(int a, int b, int c = 1) {
    for(; b; b >>= 1, a = (ll)a * a % P) if(b & 1) c = (ll)c * a % P;
    return c;
}
void rmain() {
    cin >> n;
    FOR(i, 0, n) dp[i] = 0;;
    int inv2 = power(2, P - 2);
    ip2[0] = 1;
    FOR(i, 1, n) ip2[i] = (ll)ip2[i - 1] * inv2 % P;
    dp[n] = 1;
    (dp[n / 2 + 1] += P - ip2[n - n / 2 - 1]) %= P;
    ROF(i, n, 3) {
        (dp[i - 1] += dp[i]) %= P;
        (dp[(i - 1) / 2 + 1] += P - (ll)dp[i] * ip2[i - 1 - (i - 1) / 2] % P) %= P;
    }
    if(n == 1) {
        cout << "1\n";
        return;
    }
    cout << "0\n";
    int sum = 0;
    FOR(i, 2, n) {
        int ans;
        if(i < n) ans = ip2[i - i / 2];
        else ans = ip2[i - i / 2 - 1];
        if(i < n) ans = (ll)ans * dp[i + 1] % P;
        cout << ans << "\n";
        (sum += ans) %= P;
    }
    // cout << sum << "\n";
    return;
}
int main() {
    // x * x x * x + x * 2
    // 2 * x + 1
    int t;
    for(cin >> t; t--; ) rmain();
    return 0;
}