#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 3011, inf = 1000111222;
const int mod = 998244353;

int dp[max_n][max_n];

string s, t;

bool fit(char a, char b) {
    return (a == b) || (a == '*') || (b == '*');
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> s;
    cin >> t;
    int inl = t.size();
    while(t.size() < s.size()) {
        t += '*';
    }
    for (int i = 0; i < t.size(); ++i) {
        if (t[i] == s[0] || t[i] == '*') {
            dp[i][i] = 2;
        } else {
            dp[i][i] = 0;
        }
    }
    for (int len = 2; len <= t.size(); ++len) {
        for (int l = 0; l + len - 1 < t.size(); ++l) {
            int r = l + len - 1;
            if (fit(s[len - 1], t[l])) {
                dp[l][r] += dp[l + 1][r];
                dp[l][r] %= mod;
            }
            if (fit(s[len - 1], t[r])) {
                dp[l][r] += dp[l][r - 1];
                dp[l][r] %= mod;
            }
        }
    }
    /*for (int l = 0; l < t.size(); ++l) {9
        for (int r = l; r < t.size(); ++r) {
            cout << l << ' ' << r << ' ' << dp[l][r] << endl;
        }
    }*/
    ll ans = 0;
    for (int len = inl; len <= t.size(); ++len) {
        ans += dp[0][len - 1];
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}