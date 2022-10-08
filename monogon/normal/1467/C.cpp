
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
    int n[3];
    rep(i, 0, 3) cin >> n[i];
    vector<ll> sum(3), mn(3);
    rep(i, 0, 3) {
        sum[i] = 0;
        mn[i] = LLONG_MAX;
        rep(j, 0, n[i]) {
            ll a;
            cin >> a;
            sum[i] += a;
            mn[i] = min(mn[i], a);
        }
    }
    ll ans = max({
        sum[0] + sum[1] - sum[2],
        sum[0] - sum[1] + sum[2],
        -sum[0] + sum[1] + sum[2],
        sum[0] + sum[1] + sum[2] - 2 * mn[0] - 2 * mn[1],
        sum[0] + sum[1] + sum[2] - 2 * mn[0] - 2 * mn[2],
        sum[0] + sum[1] + sum[2] - 2 * mn[1] - 2 * mn[2],
    });
    cout << ans << '\n';
}