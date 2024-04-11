/*input
4
1 1 1 1
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x,y) ((x>>y)&1)
#ifdef UncleGrandpa
#include <prettyprint.hpp>
void print() {cout << endl;} template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {cout << value << ' ', print(values...);}
void debug() {cerr << endl;} template<typename T, typename... Ts> void debug(const T& value, const Ts&... values) {cerr << value << ' ', debug(values...);}
#endif
const int N = 1005;
const int mod = 998244353;

int n;
int a[N];
int dp[N];
int C[N][N];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    for (int i = 0; i < N; ++i) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; ++j)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    }

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    dp[n + 1] = 1;
    for (int i = n; i >= 1; i--) {
        if (a[i] <= 0) continue;
        for (int j = i + a[i] + 1; j <= n + 1; ++j) {
            dp[i] += (1LL * dp[j] * C[j - i - 1][a[i]]) % mod;
            dp[i] %= mod;
        }
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) sum = (sum + dp[i]) % mod;
    cout << sum << endl;
}