
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
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    ll sum = accumulate(all(a), 0LL);
    sort(all(a));
    int m;
    cin >> m;
    while(m--) {
        ll x, y;
        cin >> x >> y;
        int i = lower_bound(all(a), x) - a.begin();
        ll ans = LLONG_MAX;
        if(i != n) {
            ans = min(ans, max(0LL, y - (sum - a[i])));
        }
        if(i != 0) {
            i--;
            ans = min(ans, x - a[i] + max(0LL, y - (sum - a[i])));
        }
        cout << ans << '\n';
    }
}