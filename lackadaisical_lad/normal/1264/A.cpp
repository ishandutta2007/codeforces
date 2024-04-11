#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
const int MOD = 1e9 + 7;
 
ll binpow(ll a, ll p, int mod = MOD) {
    ll res = 1;
    while (p) {
        if (p & 1) {
            (res *= a) %= mod;
        }
        p >>= 1;
        (a *= a) %= mod;
    }
    return res;
}
 
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

void solve() {
    int n;
    cin >> n;
    vector<int> len;
    int prev = -1;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        if (p != prev) {
            len.push_back(0);
        }
        prev = p;
        len.back()++;
    }
    int tot = n;
    int mid = n / 2;
    while (tot > mid) {
        tot -= len.back();
        len.pop_back();
    }
    int m = len.size();
    vector<int> pref(m + 1);
    for (int i = 1; i <= m; i++) {
        pref[i] = pref[i - 1] + len[i - 1];
    }
    int j = 1;
    int best = -1;
    vector<int> ans(3);
    for (int i = 0; i + 2 < m; i++) {
        j = max(j, i + 1);
        while (j + 2 <= m && min(pref[j + 2] - pref[i + 1], pref[m] - pref[j + 2]) >= min(pref[j + 1] - pref[i + 1], pref[m] - pref[j + 1])) {
            j++;
        }
        int s = pref[j + 1] - pref[i + 1];
        int b = pref[m] - pref[j + 1];
        int g = pref[i + 1];
        if (g && s && b && g + s + b > best && g < s && g < b) {
            ans = {g, s, b};
            best = g + s + b;
        }
    }
    int g = ans[0];
    int s = ans[1];
    int b = ans[2];
    if (g < 1 || s < 1 || b < 1) {
        g = s = b = 0;
    }
    cout << g << ' ' << s << ' ' << b << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}