
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

// find expected value for each prime individually
// independent, so answer is product of the expected values
// n = p^i
// dp[i][j] = expected value when n = p^i for j moves
// dp[0][j] = 1
// dp[i][0] = p^i
// dp[i][j] = (1 / (i + 1)) sum_{l = 0}^i dp[l][j - 1]
// dp[i - 1][j] = (1 / i) sum_{l = 0}^(i-1) dp[l][j - 1]
// dp[i][j] = (i / (i + 1)) dp[i - 1][j] + (1 / (i + 1)) dp[i][j - 1]

const int M = 1e9 + 7, LG = 52, K = 1e4 + 5;
int k;
ll n, dp[LG][K], inv[LG];

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    vector<pair<ll, int>> ve;
    for(ll i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            int t = 0;
            while(n % i == 0) {
                n /= i;
                t++;
            }
            ve.emplace_back(i, t);
        }
    }
    rep(i, 1, LG) {
        inv[i] = modinverse(i, M);
    }
    if(n > 1) ve.emplace_back(n, 1);
    ll ans = 1;
    for(auto &pa : ve) {
        ll p = pa.first;
        int t = pa.second;
        rep(i, 0, t + 1) rep(j, 0, k + 1) {
            if(i == 0) dp[i][j] = 1;
            else if(j == 0) {
                dp[i][j] = (p * dp[i - 1][j]) % M;
            }else {
                dp[i][j] = (inv[i + 1] * ((i * dp[i - 1][j] + dp[i][j - 1]) % M)) % M;
            }
        }
        ans = (ans * dp[t][k]) % M;
    }
    ans = mod(ans, M);
    cout << ans << '\n';
}