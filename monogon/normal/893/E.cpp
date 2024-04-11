
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

// negatives: choose even number
// each prime has some count
// can be distributed a number of ways
// prime appears at most log2(x) times <= 20
// 10^6 choose 20

// 2^y = even + odd
// 0 = even - odd
// 2^{y-1} = even = odd

const int N = 1e6 + 35, M = 1e9 + 7;
int q;
ll x, y, dp[N][21], pow2[N], fact[N];
int sieve[N];

ll powmod(ll a, ll b) {
    ll ans = 1;
    while(b > 1) {
        if(b & 1) {
            ans = (ans * a) % M;
        }
        a = (a * a) % M;
        b /= 2;
    }
    return ans;
}
ll modinverse(ll a) {
    return powmod(a, M - 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    rep(i, 0, N) rep(j, 0, 21) {
        if(j == 0) dp[i][j] = 1;
        else if(i == 0) dp[i][j] = 0;
        else dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % M;
    }
    pow2[0] = 1;
    fact[0] = 1;
    rep(i, 1, N) {
        pow2[i] = (2 * pow2[i - 1]) % M;
        fact[i] = (i * fact[i - 1]) % M;
    }
    sieve[1] = 1;
    rep(i, 2, N) {
        if(sieve[i] == 0) {
            for(int p = i; p < N; p += i) {
                if(sieve[p] == 0) {
                    sieve[p] = i;
                }
            }
        }
    }
    while(q--) {
        cin >> x >> y;
        ll ans = pow2[y - 1];
        map<int, int> cnt;
        while(x > 1) {
            cnt[sieve[x]]++;
            x /= sieve[x];
        }
        for(auto &p : cnt) {
            ans = (ans * dp[y + p.second - 1][p.second]) % M;
            // ans = (ans * dp[y][p.second]) % M;
            // ans = (ans * powmod(y, p.second) * modinverse(fact[p.second])) % M;
        }
        ans = (ans + M) % M;
        cout << ans << '\n';
    }
}