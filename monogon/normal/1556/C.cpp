
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> c(n + 1);
    rep(i, 1, n + 1) {
        cin >> c[i];
    }
    ll ans = 0;
    for(int i = 1; i <= n; i += 2) {
        ll s = 0, m = 0;
        rep(j, i + 1, n + 1) {
            if(j % 2 == 0) {
                ll L = max({1LL, -m, 1 - s});
                ll R = min(c[i], c[j] - s);
                if(R >= L) ans += R - L + 1;
            }
            s += (j % 2 == 0 ? -c[j] : c[j]);
            m = min(m, s);
        }
    }
    cout << ans << '\n';
}