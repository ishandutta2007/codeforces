
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

// LHS is just x mod a_1
// a1 = 1, always works
// everything should be a multiple of a1
// (7, 3)
// a1 = 1: subset of 2 numbers from 2...7 => 6 choose 2 = 15
// a1 = 2: 2-subset of 4, 6 => only 1 way: 1
// a1 = 3: 2-subset of 6, doesn't exist
// answer is 15 + 1 = 16
// iterate over a1, count number of multiples of a1 at most n
// count ways to choose k-1 of them.
// compute (i choose k - 1) for all 0 <= i <= n.
// (i + 1 choose k - 1) = (i + 1)! / (k-1)! (i-k+2)! = (i+1)/(i-k+2) (i choose k - 1)
// (i choose k - 1) = i! / (k-1)! (i-k+1)!

const int N = 5e5 + 5, M = 998244353;
ll n, k, choose[N], ans;

ll mod(ll a) {
    return (a % M + M) % M;
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
ll modinverse(ll a) {
    ll x, y;
    ll g = euclid(a, M, x, y);
    return g > 1 ? -1 : mod(x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    rep(i, 0, k - 1) choose[i] = 0;
    choose[k - 1] = 1;
    rep(i, k - 1, n) {
        choose[i + 1] = mod(mod((i + 1) * modinverse(i - k + 2)) * choose[i]);
    }
    rep(d, 1, n + 1) {
        ll amt = max(0LL, n / d - 1);
        ans = mod(ans + choose[amt]);
    }
    cout << ans << '\n';
}