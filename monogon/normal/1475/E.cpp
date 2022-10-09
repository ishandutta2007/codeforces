
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

const int M = 1e9 + 7;

ll modpow(ll a, ll b) {
    ll ans = 1;
    while(b > 0) {
        if(b & 1) ans = (ans * a) % M;
        a = (a * a) % M;
        b /= 2;
    }
    return ans;
}
ll modinv(ll a) {
    return modpow(a, M - 2);
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> fact(n + 1);
    fact[0] = 1;
    rep(i, 1, n + 1) fact[i] = (fact[i - 1] * i) % M;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    sort(all(a), greater<>());
    ll val = a[k - 1];
    int cnt = 0, cnt2 = 0;
    rep(i, 0, n) cnt += (a[i] == val);
    rep(i, k, n) cnt2 += (a[i] == val);
    ll ans = fact[cnt];
    ans = (ans * modinv(fact[cnt2])) % M;
    ans = (ans * modinv(fact[cnt - cnt2])) % M;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        solve();
    }
}