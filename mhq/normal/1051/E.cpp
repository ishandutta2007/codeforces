#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = 998244353;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
vector<int> z_function (string s) {
    int n = (int) s.length();
    vector<int> z (n);
    for (int i=1, l=0, r=0; i<n; ++i) {
        if (i <= r)
            z[i] = min (r-i+1, z[i-l]);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if (i+z[i]-1 > r)
            l = i, r = i+z[i]-1;
    }
    return z;
}
string a;
string s[2];
const int maxN = (int)1e6 + 10;
int dp[maxN];
int pref[maxN];
bool f[maxN][2];
void solve() {
    dp[0] = 1;
    pref[0] = 1;
    for (int i = 0; i < a.size(); i++) {
        //cout << f[i][0] << '\n';
    }
    for (int i = 1; i <= a.size(); i++) {
        pref[i] = sum(pref[i - 1], dp[i]);
        int r = i - s[0].size();
        int l = max(0, i - (int)s[1].size());
        if (i >= s[0].size()) {
            if (!f[l][1] && i - l == s[1].size()) l++;
            if (!f[r][0]) r--;
            if (l <= r) {
                dp[i] = sum(pref[r], dp[i]);
                //cout << i << " " << l << " " << r << endl;
                if (l > 0) dp[i] = sub(dp[i], pref[l - 1]);
            }
        }
        pref[i] = sum(pref[i - 1], dp[i]);
        if (i != a.size() && a[i] == '0') {
            if (s[0].size() == 1 && s[0] == "0") {
                dp[i + 1] = dp[i];
            }
            dp[i] = 0;
            pref[i] = pref[i - 1];
        }
        //if (i == 1) cout << dp[2] << endl;
    }
    //cout << dp[2] << endl;
    cout << dp[a.size()] << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> a;
    cin >> s[0] >> s[1];
    string t1 = s[0] + '#' + a;
    vector < int > v = z_function(t1);
    for (int i = 0; i < a.size(); i++) {
        int pos = i + 1 + s[0].size();
        if (v[pos] == s[0].size()) {
            f[i][0] = true;
            continue;
        }
        if (i + v[pos] >= a.size()) {
            f[i][0] = true;
            continue;
        }
        if (a[i + v[pos]] > s[0][v[pos]]) f[i][0] = true;
        else f[i][0] = false;
    }
    t1 = s[1] + '#' + a;
    v = z_function(t1);
    for (int i = 0; i < a.size(); i++) {
        int pos = i + 1 + s[1].size();
        if (v[pos] == s[1].size()) {
            f[i][1] = true;
            continue;
        }
        if (i + v[pos] >= a.size()) {
            f[i][1] = false;
            continue;
        }
        if (a[i + v[pos]] < s[1][v[pos]]) f[i][1] = true;
        else f[i][1] = false;
    }
    solve();
    return 0;
}