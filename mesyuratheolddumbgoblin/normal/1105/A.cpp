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

ll a[100500], n, i, j, k;
vector<ll> g[50];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = MOD, t = -1;
    for (int i = 1; i <= 100; i++) {
            ll sum = 0;
        for (int j = 0; j < n; j++) {
            sum += min(Abs(i-a[j]), min(Abs(i+1-a[j]), Abs(i-1-a[j])));
        }
        if (sum < ans) {
            ans = sum;
            t = i;
        }
    }
    cout << t << " " << ans << endl;
  return 0;
}