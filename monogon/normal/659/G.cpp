
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

const int N = 1e6 + 5, M = 1e9 + 7;
int n;
ll h[N];

ll powmod(ll a, ll b) {
    ll res = 1;
    while(b > 0) {
        if(b & 1) {
            res = (res * a) % M;
        }
        a = (a * a) % M;
        b /= 2;
    }
    return res;
}
ll modinv(ll a) {
    return powmod(a, M - 2);
}

ll ans = 0;

void solve(vector<ll> &a) {
    int n = sz(a);
    vector<ll> c(n, 0), bc(n + 1, 0);
    c[0] = 1;
    rep(i, 1, n - 1) {
        c[i] = (c[i - 1] * min({a[i - 1], a[i], a[i + 1]})) % M;
    }
    bc[n] = 0;
    for(int i = n - 1; i >= 1; i--) {
        bc[i] = (bc[i + 1] + min(a[i - 1], a[i]) * c[i - 1]) % M;
    }
    rep(i, 0, n - 1) {
        ans = (ans + ((min(a[i], a[i + 1]) * modinv(c[i])) % M) * bc[i + 1]) % M;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int j = 0;
    rep(i, 0, n) {
        cin >> h[i];
        h[i]--;
        ans = (ans + h[i]) % M;
        if(h[i] == 0) {
            if(j < i) {
                vector<ll> ve(h + j, h + i);
                solve(ve);
            }
            j = i + 1;
        }
    }
    if(j < n - 1) {
        vector<ll> ve(h + j, h + n);
        solve(ve);
    }
    cout << ans << '\n';
}