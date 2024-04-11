
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

// imagine turning on all routers
// all uncovered points we're forced to buy
// minimum cost set cover for these intervals
// DP

const int N = 2e5 + 5;
int n, k;
string s;
vi ve;
ll dp[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> s;
    s = "$" + s;
    rep(i, 1, n + 1) {
        if(s[i] == '1') ve.push_back(i);
    }
    rep(i, 1, n + 1) {
        dp[i] = i + dp[i - 1];
        int j = lower_bound(all(ve), i - k) - ve.begin();
        if(j < sz(ve) && ve[j] <= i + k && dp[max(0, ve[j] - k - 1)] + ve[j] < dp[i]) {
            dp[i] = dp[max(0, ve[j] - k - 1)] + ve[j];
        }
    }
    cout << dp[n] << '\n';
}