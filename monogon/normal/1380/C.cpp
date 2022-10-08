
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
int t, n, dp[N];
ll x, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> x;
        rep(i, 0, n) cin >> a[i];
        sort(a, a + n);
        dp[n] = 0;
        int ans = 0;
        for(int i = n - 1; i >= 0; i--) {
            if((x + a[i] - 1) / a[i] <= n - i) {
                dp[i] = 1 + dp[i + (x + a[i] - 1) / a[i]];
            }else {
                dp[i] = 0;
            }
            ans = max(ans, dp[i]);
        }
        cout << ans << '\n';
    }
}