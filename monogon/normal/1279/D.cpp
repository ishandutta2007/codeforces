
#include <bits/stdc++.h>

#define ll long long
using namespace std;

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

const int N = 1e6 + 5, M = 998244353;
int n, k[N], a;
vector<int> pres[N];
int cnt[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    ll ninv = modinverse(n, M);
    for(int i = 0; i < n; i++) {
        cin >> k[i];
        for(int j = 0; j < k[i]; j++) {
            cin >> a;
            pres[i].push_back(a);
            cnt[a]++;
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k[i]; j++) {
            ans = mod(ans + mod(ninv * ninv, M) * mod(modinverse(k[i], M) * cnt[pres[i][j]], M), M);
        }
    }
    cout << ans << endl;
}