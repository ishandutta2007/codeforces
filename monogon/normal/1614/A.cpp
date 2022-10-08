
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

void solve() {
    int n; ll l, r, k;
    cin >> n >> l >> r >> k;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    sort(all(a));
    int ans = 0;
    rep(i, 0, n) {
        if(l <= a[i] && a[i] <= r && a[i] - k <= 0) {
            ans++;
            k -= a[i];
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}