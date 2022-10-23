#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int mod = 998244353;
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
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int n;
const int maxN = 3e5 + 10;
int l[maxN], r[maxN];
vector<int> s[maxN];
int dp[maxN][2];
int pw3[maxN];
int pw2[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    pw3[0] = 1;
    pw2[0] = 1;
    for (int i = 1; i <= n; i++) {
        pw3[i] = mult(3, pw3[i - 1]);
        pw2[i] = mult(2, pw2[i - 1]);
    }
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        s[l].emplace_back(i);
        s[r + 1].emplace_back(~i);
    }
    set<int> all;
    int ans = 0;
    for (int i = 0; i < maxN; i++) {
        for (int p : s[i]) {
            if (p > 0) {
                all.insert(p);
            }
            else {
                all.erase(~p);
            }
        }
        if (!all.empty()) {
            int x = *(--all.end());
            int val = 1;
            if (x == 1) {
                val = pw2[n - 1];
            }
            else {
                val = mult(val, mult(mult(2, pw3[x - 2]), pw2[n - x]));
            }
            ans = sum(ans, val);
        }
    }
    cout << ans << '\n';
    return 0;
}