
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

const int N = 77;
int t, n, k, inv[N];
ll a[N], b[N], a2[N], b2[N], dp[N][N];
bool summon[N][N], s[N], ans[N][N];

ll solve() {
    dp[0][0] = 0;
    rep(i, 1, n + 1) {
        rep(j, 0, min(k, i) + 1) {
            dp[i][j] = -1;
            summon[i][j] = true;
            if(j > 0) {
                dp[i][j] = dp[i - 1][j - 1] + a[i] + (j - 1) * b[i];
            }
            if(j < i && dp[i - 1][j] + b[i] * (k - 1) > dp[i][j]) {
                summon[i][j] = false;
                dp[i][j] = dp[i - 1][j] + b[i] * (k - 1);
            }
        }
    }
    return dp[n][k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> k;
        vector<tuple<int, int, int>> ve;
        rep(i, 1, n + 1) {
            cin >> a[i] >> b[i];
            ve.emplace_back(b[i], a[i], i);
        }
        sort(all(ve));
        rep(i, 1, n + 1) {
            tie(b[i], a[i], inv[i]) = ve[i - 1];
        }
        solve();
        int i = n, j = k;
        while(i > 0) {
            if(summon[i][j]) {
                j--;
                s[i] = true;
            }else {
                s[i] = false;
            }
            i--;
        }
        int cnt = 0;
        vi v;
        int last = 0;
        rep(i, 1, n + 1) {
            if(s[i]) {
                if(cnt < k - 1) {
                    v.push_back(inv[i]);
                    cnt++;
                }else {
                    last = inv[i];
                }
            }
        }
        rep(i, 1, n + 1) {
            if(!s[i]) {
                v.push_back(inv[i]);
                v.push_back(-inv[i]);
            }
        }
        v.push_back(last);
        cout << sz(v) << '\n';
        for(int x : v) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}