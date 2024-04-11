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

ll a[100500], n, i, j, k;
vector<ll> g[50];
int main() {
    cin >> n >> k;
    ll cnt = 1;
    string s;
    cin >> s;
    for (int i = 0; i + 1 < n; i++) {
        if (s[i] != s[i+1]) {
            g[s[i]-'a'].push_back(cnt);
            cnt = 1;
        } else {
            cnt++;
        }
    }
    g[s[n-1]-'a'].push_back(cnt);
    ll ans = 0;
    for (int i = 0; i < 26; i++) {
        ll sum = 0;
        for (int j = 0; j < g[i].size(); j++) {
            sum += g[i][j] / k;
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
  return 0;
}