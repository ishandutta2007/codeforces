#include<bits/stdc++.h>
using namespace std;
const int nax = 2048;
int dp[nax][nax];
int n;
string s;
int judge(int u, int v) {
    if (u < v) return 0;
    return u == v ? 1 : 2;
}

int rec(int l, int r) {
    /**
        can alice win if the result is draw until now
        and the range is [l, r]
    */
    /// OH NO, it's PREPEND!!!!!!!!!!!!!!!!!!!!!!!!!!!

    if (r - l == 1) return s[l] == s[r] ? 1 : 0;
    if (dp[l][r] != -1) return dp[l][r]; /// memo nothing

    int &res = dp[l][r]; res = 2;
    {
        /// choosing L
        auto bob_l = make_pair(rec(l + 2, r), -s[l + 1]);
        auto bob_r = make_pair(rec(l + 1, r - 1), -s[r]);
        auto c = max(bob_l, bob_r);
        if (c.first == 0) res = 0;
        if (c.first == 1) {
            char x = -c.second;
            res = min(res, judge(s[l], x));
        }
    }

    {
        auto bob_l = make_pair(rec(l + 1, r - 1), -s[l]);
        auto bob_r = make_pair(rec(l, r - 2), -s[r - 1]);
        auto c = max(bob_l, bob_r);
        if (c.first == 0) res = 0;
        if (c.first == 1) {
            char x = -c.second;
            res = min(res, judge(s[r], x));
        }
    }
    return res;

    /*
    if (s[l] < min(s[l + 1], s[r]) || s[r] < min(s[r - 1], s[l])) {
        return dp[l][r] = 0;
    }
    if (s[l] > min(s[l + 1], s[r]) && s[r] > min(s[r - 1], s[l])) {
        return dp[l][r] = 2; // lose
        /// if taking either s[l] and s[r] ended up in this way
    }
    int &res = dp[l][r];
    res = 2;

    if (s[l] == min(s[l + 1], s[r])) {
        int u = -1;
        if (s[l] == s[l + 1]) u = max(u, rec(l + 2, r));
        if (s[l] == s[r]) u = max(u, rec(l + 1, r - 1));
        res = min(res, u);
    }

    if (s[r] == min(s[r - 1], s[l])) {
        int u = -1;
        if (s[r] == s[l]) u = max(u, rec(l + 1, r - 1));
        if (s[r] == s[r - 1]) u = max(u, rec(l, r - 2));
        res = min(res, u);
    }
    return res;
    */
}

void solve() {
    cin >> s;
    n = s.size();
    memset(dp, -1, sizeof(dp));
    int ans = rec(0, n - 1);
    if (ans == 0) {
        cout << "Alice\n";
    } else if (ans == 1) {
        cout << "Draw\n";
    } else cout << "Bob\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}