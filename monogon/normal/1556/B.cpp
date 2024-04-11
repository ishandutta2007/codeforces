
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
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n) {
        cin >> a[i];
        a[i] %= 2;
    }
    auto solve = [&]() {
        int cnt = 0;
        ll ans = 0;
        rep(i, 0, n) {
            if(a[i] != (i % 2)) {
                if(a[i]) cnt++;
                else cnt--;
            }
            ans += abs(cnt);
        }
        if(cnt != 0) return LLONG_MAX;
        return ans;
    };
    ll ans = LLONG_MAX;
    ans = min(ans, solve());
    rep(i, 0, n) a[i] = 1 - a[i];
    ans = min(ans, solve());
    if(ans == LLONG_MAX) ans = -1;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}