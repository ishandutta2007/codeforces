
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

const int N = 505, K = 505;
int n, k;
ll a[N], b[N];
bool dp[N][K];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    ll A = 0, B = 0;
    rep(i, 1, n + 1) {
        cin >> a[i] >> b[i];
        A += a[i];
        B += b[i];
    }
    ll ans = A / k + B / k;
    A %= k; B %= k;
    if(A + B < k) {
        cout << ans << '\n';
        return 0;
    }
    dp[0][0] = true;
    rep(i, 1, n + 1) {
        rep(x, 0, k) {
            if(x <= a[i] && k - x <= b[i]) {
                rep(v, 0, k) {
                    dp[i][(v + x) % k] |= dp[i - 1][v];
                }
            }
        }
        rep(v, 0, k) {
            dp[i][v] |= dp[i - 1][v];
        }
    }
    rep(v, 0, k) {
        ll A2 = (A + k - v) % k;
        ll B2 = (B + v) % k;
        if(dp[n][v] && A2 + B2 < k) {
            ans++;
            break;
        }
    }
    cout << ans << '\n';
}