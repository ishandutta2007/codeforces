
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

const int N = 1e6 + 5;
int t, n, k;
string s;
int dp[N], pref[N];

// dp[i] = answer if we set state[i] = 1

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> k >> s;
        pref[0] = 0;
        rep(i, 1, n + 1) {
            pref[i] = pref[i - 1] + (s[i - 1] == '1');
        }
        int ans = pref[n];
        rep(i, 1, n + 1) {
            int L = max(0, i - k);
            dp[i] = (s[i - 1] == '0') + min(pref[i - 1], (pref[i - 1] - pref[L]) + dp[L]);
            ans = min(ans, pref[n] - pref[i] + dp[i]);
        }
        cout << ans << '\n';
    }
}