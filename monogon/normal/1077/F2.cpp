
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

// dp[i][j] -- i pictures, j reposting, where we do repost the ith picture
// a[i] + max_{l = i-k, ..., i-1} dp[l][j - 1]
// a[i] + getmax(j)
// maintain x different sliding windows

const int N = 5005;
int n, k, x, l = 0, r = -1;
ll a[N], dp[N][N];
deque<int> q[N];

void left() {
    rep(j, 0, x + 1) {
        if(q[j].front() == l) q[j].pop_front();
    }
    l++;
}
void right() {
    r++;
    rep(j, 0, x + 1) {
        while(!q[j].empty() && dp[q[j].back()][j] <= dp[r][j]) q[j].pop_back();
        q[j].push_back(r);
    }
}
ll getmax(int j) {
    return q[j].empty() ? -1 : dp[q[j].front()][j];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> x;
    rep(i, 1, n + 1) cin >> a[i];
    ll ans = -1;
    rep(i, 0, n + 1) {
        dp[i][0] = (i == 0 ? 0 : -1);
        rep(j, 1, x + 1) {
            if(getmax(j - 1) >= 0) {
                dp[i][j] = a[i] + getmax(j - 1);
            }else {
                dp[i][j] = -1;
            }
        }
        if(n - i < k) ans = max(ans, dp[i][x]);
        right();
        if(r - l + 1 > k) left();
    }
    cout << ans << '\n';
}