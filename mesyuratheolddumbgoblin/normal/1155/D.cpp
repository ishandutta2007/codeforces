#include <utility>
#include <bitset>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <time.h>
#include <iostream>
#include <vector>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD 1000000007
typedef long long ll;
using namespace std;

ll a[300500], x, y, z, b[100500], n, m;
vector<pii> ans, f;
ll Abs(ll x) {
    return (x > 0 ? x : -x);
}
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a%b);
}
ll dp[300500][3];
int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        dp[i+1][0] = max(dp[i+1][0], dp[i][0] + a[i]);
        dp[i+1][1] = max(max(dp[i+1][1], dp[i][1] + a[i] * x), dp[i][0] + a[i] * x);
        dp[i+1][2] = max(max(dp[i+1][2], dp[i][1] + a[i]), dp[i][2] + a[i]);
    }
    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 3; j++)
            ans = max(ans, dp[i][j]);
    }
    cout << ans << endl;
    return 0;
}