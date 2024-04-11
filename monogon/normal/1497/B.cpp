
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
    int n, m;
    cin >> n >> m;
    vector<ll> cnt(m, 0);
    rep(i, 0, n) {
        int a;
        cin >> a;
        a %= m;
        cnt[a]++;
    }
    ll ans = 0;
    for(int i = 1; 2 * i < m; i++) {
        int j = m - i;
        if(cnt[i] > 0 || cnt[j] > 0) {
            ans++;
            ll s = min(cnt[i], cnt[j]) + 1;
            if(cnt[i] - s > 0) ans += cnt[i] - s;
            if(cnt[j] - s > 0) ans += cnt[j] - s;
        }
    }
    if(cnt[0] > 0) ans++;
    if(m % 2 == 0 && cnt[m / 2] > 0) ans++;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}