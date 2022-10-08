
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

// dp[i][j][k] => ith day, j food eaten the next day, first k friends
// food is a[i] + a[i - 1] - j
// if food available < v, impossible
// if k = 0, dp[i - 1][food left if eats v][m]
// otherwise, default is dp[i][j][k - 1]
// if choose to feed friend, check l[k] <= i <= r[i], food eaten is f[k], 1 + dp[i][j + ?][k - 1]

// dp[i][j] => day i, if we have j food
// only feed friends in increasing f order

const int N = 405;
int n, v, a[N], m, l[N], r[N], f[N], dp[N][2 * N], feed[N][2 * N];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> v;
    rep(i, 1, n + 1) cin >> a[i];
    cin >> m;
    vector<pii> ve;
    rep(i, 1, m + 1) {
        cin >> l[i] >> r[i] >> f[i];
        ve.emplace_back(f[i], i);
    }
    sort(ve.begin(), ve.end());
    rep(i, 1, n + 1) {
        rep(j, 0, a[i] + a[i - 1] + 1) {
            int sum = 0, pop = 0;
            dp[i][j] = INT_MIN;
            if(v <= j) {
                dp[i][j] = dp[i - 1][min(a[i - 1], j - v) + (i == 1 ? 0 : a[i - 2])];
            }
            rep(k, 0, m) {
                int idx = ve[k].se;
                if(l[idx] <= i && i <= r[idx]) {
                    sum += f[idx];
                    pop++;
                    if(v + sum <= j) {
                        int food = min(a[i - 1], j - v - sum) + (i == 1 ? 0 : a[i - 2]);
                        if(dp[i - 1][food] >= 0 && pop + dp[i - 1][food] > dp[i][j]) {
                            // f
                            feed[i][j] = pop;
                            dp[i][j] = pop + dp[i - 1][food];
                        }
                    }
                }
            }
        }
    }
    cout << dp[n][a[n] + a[n - 1]] << '\n';
    int j = a[n] + a[n - 1];
    vector<vi> ans;
    for(int i = n; i >= 1; i--) {
        if(feed[i][j] == 0) {
            ans.emplace_back();
            j = min(a[i - 1], j - v) + (i == 1 ? 0 : a[i - 2]);
            continue;
        }
        int pop = 0, sum = 0;
        vi vec;
        rep(k, 0, m) {
            int idx = ve[k].se;
            if(l[idx] <= i && i <= r[idx]) {
                pop++;
                sum += f[idx];
                vec.push_back(idx);
                if(pop == feed[i][j]) {
                    j = min(a[i - 1], j - v - sum) + (i == 1 ? 0 : a[i - 2]);
                    break;
                }
            }
        }
        ans.push_back(vec);
    }
    reverse(ans.begin(), ans.end());
    for(auto &ve : ans) {
        cout << sz(ve) << ' ';
        for(int x : ve) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}