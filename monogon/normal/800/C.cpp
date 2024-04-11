
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 2e5 + 5;
int n, m, phi[N], dp[N], par[N];
bool use[N];

ll modpow(ll a, ll b, ll m) {
    ll ans = 1;
    while(b > 0) {
        if(b & 1) {
            ans = (ans * a) % m;
        }
        a = (a * a) % m;
        b /= 2;
    }
    return ans;
}

ll modinv(ll a, ll m) {
    return modpow(a, phi[m] - 1, m);
}

// solve a x = b (mod m)
ll solve(ll a, ll b, ll m) {
    ll g = gcd(a, m);
    if(g == 1) {
        return (modinv(a, m) * b) % m;
    }else if(b % g != 0) {
        return -1;
    }else {
        return (modinv(a / g, m / g) * (b / g)) % (m / g);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    rep(i, 0, n) {
        int a;
        cin >> a;
        use[a] = true;
    }
    rep(i, 1, m + 1) {
        ll x = i;
        phi[i] = 1;
        for(ll p = 2; p * p <= x; p++) {
            if(x % p == 0) {
                phi[i] *= (p - 1);
                x /= p;
                while(x % p == 0) {
                    x /= p;
                    phi[i] *= p;
                }
            }
        }
        if(x > 1) {
            phi[i] *= (x - 1);
        }
    }
    dp[m] = (use[0] ? 0 : 1);
    for(int g = m - 1; g >= 1; g--) {
        if(m % g != 0) continue;
        int mx = 0, cnt = 0;
        if(!use[g]) cnt++;
        par[g] = 0;
        for(ll i = 2 * g; i <= m; i += g) {
            if(i < m && !use[i] && gcd(i, m) == g) cnt++;
            if(dp[i] > mx) {
                mx = dp[i];
                par[g] = i;
            }
        }
        dp[g] = cnt + mx;
    }
    cout << dp[1] << '\n';
    int d = 1;
    ll pr = 1;
    while(d != 0) {
        for(ll i = d; i < m; i += d) {
            if(!use[i] && gcd(i, m) == d) {
                ll x = solve(pr, i, m);
                assert(x != -1);
                cout << x << ' ';
                pr = (pr * x) % m;
                assert(pr == i);
            }
        }
        d = par[d];
    }
    if(!use[0]) {
        cout << 0;
    }
    cout << '\n';
}