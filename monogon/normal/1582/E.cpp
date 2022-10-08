
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
    vector<ll> a(n + 1);
    rep(i, 1, n + 1) {
        cin >> a[i];
    }
    reverse(1 + all(a));
    rep(i ,1, n + 1) a[i] += a[i - 1];
    vector<ll> dp(n + 1, LLONG_MAX), dp2(n + 1, 0);
    int k = 1;
    while(true) {
        rep(i, 0, k) dp2[i] = LLONG_MIN;
        rep(i, k, n + 1) {
            dp2[i] = dp2[i - 1];
            if(dp[i - k] > a[i] - a[i - k] && a[i] - a[i - k] > dp2[i]) {
                dp2[i] = a[i] - a[i - k];
            }
        }
        if(dp2[n] == LLONG_MIN) break;
        dp.swap(dp2);
        k++;
    }
    k--;
    cout << k << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}