
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

const int N = 5005;
int n;
ll a[N], dp[N][N], inv[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<pair<ll, int>> ve;
    ve.emplace_back(0, 0);
    rep(i, 1, n + 1) {
        cin >> a[i];
        ve.emplace_back(a[i], i);
    }
    sort(all(ve));
    rep(i, 1, n + 1) {
        inv[ve[i].second] = i;
    }
    rep(i, 1, n + 1) {
        rep(h, 0, n + 1) {
            ll H = ve[h].first;
            if(a[i] >= H) {
                dp[i][h] = min(1 + dp[i - 1][h], (a[i] - H) + dp[i - 1][inv[i]]);
            }else {
                dp[i][h] = dp[i - 1][inv[i]];
            }
        }
    }
    cout << dp[n][0] << '\n';
}