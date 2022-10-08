
#pragma GCC optimize("Ofast")
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

const int N = 1e5 + 5;
int r, n;
int t[N], x[N], y[N], dp[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> r >> n;
    x[0] = 1;
    y[0] = 1;
    rep(i, 1, n + 1) {
        cin >> t[i] >> x[i] >> y[i];
    }
    int idx = 0, mx = -1;
    rep(i, 1, n + 1) {
        for(int j = i - 1; j >= 0 && t[i] - t[j] <= 2 * r; j--) {
            if(abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[i] - t[j] && (j == 0 || dp[j] > 0)) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        while(t[i] - t[idx] > 2 * r) {
            mx = max(mx, dp[idx]);
            idx++;
        }
        dp[i] = max(dp[i], 1 + mx);
    }
    // rep(i, 1, n + 1) {
    //     cout << dp[i] << ' ';
    // }
    // cout << endl;
    cout << *max_element(dp, dp + n + 1) << '\n';
}