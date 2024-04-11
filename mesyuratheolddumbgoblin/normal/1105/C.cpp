#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define mp make_pair
#define MOD 1000000007
typedef long long ll;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a%b);
}

ll binpow(ll x, ll y) {
    if (y == 0) {
        return 1;
    }
    ll tmp = binpow(x, y/2);
    tmp = tmp * tmp % MOD;
    if (y % 2) {
        return x * tmp % MOD;
    }
    return tmp;
}

ll inv(ll x) {
    return binpow(x, MOD-2);
}

ll Abs(ll x) {
    return x>0?x:-x;
}

void add(ll& x, ll y) {
    x += y;
    x %= MOD;
}

ll dp[200500][5], n, i, j, k, l, r;
vector<ll> g[50];
int main() {
    cin >> n >> l >> r;
    dp[0][0] = 1;
    ll s0 = (r+3)/3 - (l+2)/3;
    ll s1 = (r+2)/3 - (l+1)/3;
    ll s2 = (r+1)/3 - l/3;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            add(dp[i+1][j], dp[i][j] * s0);
            add(dp[i+1][(j+1)%3], dp[i][j] * s1);
            add(dp[i+1][(j+2)%3], dp[i][j]*s2);
        }
    }
    cout << dp[n][0] << endl;
  return 0;
}