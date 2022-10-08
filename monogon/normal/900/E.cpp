
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

// dp[i] = answer for length i prefix
// we want to query: what's the cost to make s[j, j + m) -> t?
// if non question marks match, cost is number of ?'s.
// otherwise, cost is infinite.
// prefq = num ?
// pref[0/1] = number of a's/b's that match. Starting with a for 0, or b for 1.

const int N = 1e5 + 5;
int n, m, dp[N], cost[N], prefq[N], pref[2][N];
string s;

int check(int idx) {
    int q = prefq[idx + m - 1] - prefq[idx - 1];
    bool b = (idx & 1);
    int p = pref[b][idx + m - 1] - pref[b][idx - 1];
    if(p + q != m) return INT_MAX;
    return q;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s >> m;
    rep(i, 1, n + 1) {
        prefq[i] = prefq[i - 1] + (s[i - 1] == '?');
        pref[0][i] = pref[0][i - 1];
        pref[1][i] = pref[1][i - 1];
        if(s[i - 1] != '?') {
            pref[0][i] += ((s[i - 1] == 'a') ^ (i & 1));
            pref[1][i] += ((s[i - 1] == 'b') ^ (i & 1));
        }
    }
    dp[0] = 0;
    rep(i, 1, n + 1) {
        dp[i] = dp[i - 1];
        cost[i] = cost[i - 1];
        int c = check(i - m + 1);
        if(i >= m && c < INT_MAX && (1 + dp[i - m] > dp[i] || (1 + dp[i - m] == dp[i] && c + cost[i - m] < cost[i]))) {
            dp[i] = 1 + dp[i - m];
            cost[i] = c + cost[i - m];
        }
    }
    cout << cost[n] << '\n';
}