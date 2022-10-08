
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
    int n; string s;
    cin >> n >> s;
    ll ans = LLONG_MAX;
    rep(c, 'a', 'z' + 1) {
        int cnt = 0;
        int l = 0, r = n - 1;
        while(l < r) {
            if(s[l] == s[r]) {
                l++;
                r--;
            }else if(s[l] == c) {
                l++;
                cnt++;
            }else if(s[r] == c) {
                r--;
                cnt++;
            }else {
                break;
            }
        }
        if(l >= r) {
            ans = min(ans, (ll) cnt);
        }
    }
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