
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

const int N = 5e5 + 5;
int n, k;
ll d, a[N], pref[N];
bool dp[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> d;
    rep(i, 1, n + 1) cin >> a[i];
    sort(a + 1, a + n + 1);
    dp[0] = true;
    pref[0] = 1;
    rep(i, 1, n + 1) {
        int j = lower_bound(a + 1, a + i + 1, a[i] - d) - a - 1;
        dp[i] = (i - j >= k && pref[i - k] - pref[j - 1] > 0);
        pref[i] = pref[i - 1] + dp[i];
        // cout << i << ": " << dp[i] << endl;
    }
    cout << (dp[n] ? "YES" : "NO") << '\n';
}