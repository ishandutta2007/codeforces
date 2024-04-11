
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

const int N = 1e5 + 5;
int n, k;
ll a[N], b[N];
int vis[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    rep(i, 0, n) {
        cin >> a[i];
    }
    if(k == 2) {
        map<ll, int> ma;
        rep(i, 0, n) {
            b[i] = 1;
            for(ll j = 2; j * j <= a[i]; j++) {
                if(a[i] % j == 0) {
                    int p = 0;
                    while(a[i] % j == 0) {
                        a[i] /= j;
                        p = !p;
                    }
                    if(p) {
                        b[i] *= j;
                    }
                }
            }
            b[i] *= a[i];
            ma[b[i]]++;
        }
        ll ans = 0;
        for(auto &p : ma) {
            ans += 1LL * p.second * (p.second - 1) / 2;
        }
        cout << ans << '\n';
        return 0;
    }
    ll ans = 0;
    for(ll x = 1; ; x++) {
        ll p = 1;
        rep(i, 0, k) {
            p *= x;
            if(p > (ll) 1e10) {
                cout << ans << '\n';
                return 0;
            }
        }
        fill(vis, vis + N, 0);
        rep(i, 0, n) {
            if(p % a[i] == 0 && p / a[i] <= (ll) 1e5) {
                ans += vis[p / a[i]];
            }
            vis[a[i]]++;
        }
    }
}