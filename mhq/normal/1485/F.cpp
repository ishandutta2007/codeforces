#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = (int)1e9 + 7;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
const int maxN = 2e5 + 10;
ll b[maxN];
ll pref[maxN];
int n;
int dp[maxN];
signed main() {
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 int tst;
 cin >> tst;
 while (tst--) {
     cin >> n;
    for (int i = 1; i <= n; i++) {
         cin >> b[i];
     pref[i] = pref[i - 1] + b[i];
    }
    dp[1] = 1;
    map<ll,int> mp;
    mp[pref[0]] = 1;
    int pref_sum = dp[1];
    for (int i = 2; i <= n; i++) {
        dp[i] = pref_sum;
        dp[i] = sub(dp[i], mp[pref[i - 1]]);
        mp[pref[i - 1]] = sum(mp[pref[i - 1]], dp[i]);
        pref_sum = sum(pref_sum, dp[i]);
    }
    cout << pref_sum << '\n';
 }
 
 return 0;
}