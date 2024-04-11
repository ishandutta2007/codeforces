
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

// add a new special offer (1, 0) to account for buying without an offer
// we should apply special offers to segments of the sorted prices
// we can ignore all special offers with x > k
// for a fixed x, we should only use the largest y associated with it

// how to sort special offers?
// [X] [----XX]
// [----XX] [X]

// [-X-XX]
// [-XX-X]

// [--XXX-X]
// [-X--XXX]
// don't sort the offers, no obvious correct ordering

const int N = 2e5 + 5, K = 2005;
int n, m, k, x[N], y[N], offer[N];
ll a[N], dp[K];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    rep(i, 1, n + 1) cin >> a[i];
    rep(i, 0, m) {
        cin >> x[i] >> y[i];
        offer[x[i]] = max(offer[x[i]], y[i]);
    }
    sort(a + 1, a + n + 1);
    rep(i, 1, n + 1) a[i] += a[i - 1];
    rep(i, 1, k + 1) {
        dp[i] = LLONG_MAX;
        rep(j, 1, i + 1) {
            int y = offer[j];
            dp[i] = min(dp[i], a[i] - a[i - j + y] + dp[i - j]);
        }
    }
    cout << dp[k] << '\n';
}