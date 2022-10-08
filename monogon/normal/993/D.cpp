
// #pragma GCC optimize ("Ofast")
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

const int N = 51, D = 101;
int n, b[N];
ll a[N], dp[N * D][2][N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<pii> ve;
    rep(i, 0, n) {
        cin >> a[i];
    }
    rep(i, 0, n) {
        cin >> b[i];
        ve.emplace_back(a[i], b[i]);
    }
    sort(all(ve));
    rep(i, 0, n) {
        tie(a[i], b[i]) = ve[i];
    }
    double ans = LLONG_MAX;
    rep(i, 0, n) {
        bool p = i % 2;
        rep(sum, 0, N * D) {
            rep(j, 0, n - i) { // j computers with >= power
                rep(k, 0, n - i - j) { // k computers with > power
                    if(i == 0) {
                        if(sum == 0 && k > 0) {
                            dp[sum][p][j][k] = 0;
                        }else if(sum == b[i]) {
                            dp[sum][p][j][k] = a[i];
                        }else {
                            dp[sum][p][j][k] = LLONG_MAX;
                        }
                    }else if(a[i - 1] == a[i]) {
                        dp[sum][p][j][k] = (k > 0 ? dp[sum][!p][j][k - 1] : LLONG_MAX);
                        if(b[i] <= sum) {
                            ll x = dp[sum - b[i]][!p][j + 1][k];
                            if(x != LLONG_MAX && a[i] + x < dp[sum][p][j][k]) {
                                dp[sum][p][j][k] = a[i] + x;
                            }
                        }
                    }else {
                        dp[sum][p][j][k] = (k > 0 ? dp[sum][!p][0][j + k - 1] : LLONG_MAX);
                        if(b[i] <= sum) {
                            ll x = dp[sum - b[i]][!p][0][j + k + 1];
                            if(x != LLONG_MAX && a[i] + x < dp[sum][p][j][k]) {
                                dp[sum][p][j][k] = a[i] + x;
                            }
                        }
                    }
                }
            }
            if(sum > 0 && i == n - 1) {
                ll x = dp[sum][p][0][0];
                if(x != LLONG_MAX) {
                    ans = min(ans, 1.0 * x / sum);
                }
            }
        }
    }
    cout << (ll) ceil(ans * 1000) << '\n';
}