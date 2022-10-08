
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 55, M = 998244353;

ll mod(ll a, ll m) {
    return (a % m + m) % m;
}
ll euclid(ll a, ll b, ll &x, ll &y) {
    ll xx = y = 0;
    ll yy = x = 1;
    while(b) {
        ll q = a / b;
        ll t = b; b = a % b; a = t;
        t = xx; xx = x - q * xx; x = t;
        t = yy; yy = y - q * yy; y = t;
    }
    return a;
}

ll modinverse(ll a, ll m) {
    ll x, y;
    ll g = euclid(a, m, x, y);
    return g > 1 ? -1 : mod(x, m);
}

ll choose(ll n, int k) {
    n = mod(n, M);
    ll num = n, den = k;
    for(int i = 1; i < k; i++) {
        num = mod(num * (n - i), M);
        den = mod(den * i, M);
    }
    return mod(num * modinverse(den, M), M);
}

int n;
ll l[N], r[N], dp[N][2 * N];
vector<ll> vx;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = n - 1; i >= 0; i--) {
        cin >> l[i] >> r[i];
        r[i]++;
        vx.push_back(l[i]);
        vx.push_back(r[i]);
    }
    sort(vx.begin(), vx.end());
    vx.erase(unique(vx.begin(), vx.end()), vx.end());
    int m = vx.size();
    for(int j = 0; j < m; j++) {
        if(vx[j] < l[0]) {
            dp[0][j] = 0;
        }else if(vx[j] < r[0]) {
            dp[0][j] = mod((vx[j + 1] - vx[j]) * modinverse(r[0] - l[0], M) + dp[0][j - 1], M);
        }else {
            dp[0][j] = 1;
        }
    }
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(vx[j] < l[i]) {
                dp[i][j] = 0;
            }else if(vx[j] < r[i]) {
                ll len = mod(vx[j + 1] - vx[j], M);
                ll den = 1;
                dp[i][j] = (j == 0 ? 0 : dp[i][j - 1]);
                for(int k = 1; k <= i + 1; k++) {
                    if(vx[j] < l[i - k + 1] || vx[j] >= r[i - k + 1]) break;
                    den = mod(den * modinverse(r[i - k + 1] - l[i - k + 1], M), M);
                    dp[i][j] = mod(dp[i][j] + mod(choose(len + k - 1, k) * den, M)
                                * (k == i + 1 ? 1LL : j == 0 ? 0LL : dp[i - k][j - 1]), M);
                }
            }else {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }
    cout << dp[n - 1][m - 1] << endl;
}