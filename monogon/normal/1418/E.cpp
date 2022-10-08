
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

const int N = 2e5 + 5, M = 998244353;
int n, m;
ll d[N], a[N], b[N], pref[N];

ll powmod(ll a, ll b) {
    ll ans = 1;
    while(b > 0) {
        if(b & 1) {
            ans = (ans * a) % M;
        }
        b /= 2;
        a = (a * a) % M;
    }
    return ans;
}
ll modinv(ll a) {
    return powmod(a, M - 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    rep(i, 1, n + 1) {
        cin >> d[i];
    }
    sort(d + 1, d + n + 1);
    rep(i, 1, n + 1) {
        pref[i] = (d[i] + pref[i - 1]) % M;
    }
    rep(i, 0, m) {
        cin >> a[i] >> b[i];
        int idx = lower_bound(d + 1, d + n + 1, b[i]) - d;
        ll B = n - idx + 1;
        if(a[i] > B) {
            cout << 0 << '\n';
            continue;
        }else if(B == 0) {
            cout << pref[n] << '\n';
            continue;
        }
        ll ans = ((((B - a[i]) * (pref[n] - pref[idx - 1])) % M) * modinv(B)) % M;
        if(B < n) {
            ans = (ans + (((B + 1 - a[i]) * modinv(B + 1)) % M) * pref[idx - 1]) % M;
        }
        cout << ans << '\n';
    }
}