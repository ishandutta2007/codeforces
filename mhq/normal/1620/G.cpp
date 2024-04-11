#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
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
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
const int maxN = (1 << 23) + 2;
const int maxK = 26;
int val[maxN][maxK];
int n;
const int maxP = 23;
string s[maxP];
int cnt[maxP][maxK];
int ans[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (char& c : s[i]) {
            cnt[i][c - 'a']++;
        }
    }
    for (int x = 0; x < 26; x++) {
        val[0][x] = mod - 1;
    }
    for (int bit = 0; bit < n; bit++) {
        for (int mask = 0; mask < (1 << bit); mask++) {
            for (int z = 0; z < 26; z++) {
                val[mask | (1 << bit)][z] = min(val[mask][z], cnt[bit][z]);
            }
        }
    }
    for (int mask = 0; mask < (1 << n); mask++) {
        ans[mask] = 1;
        for (int z = 0; z < 26; z++) {
            ans[mask] = mult(ans[mask], val[mask][z] + 1);
        }
    }
    for (int bit = 0; bit < n; bit++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            if (mask & (1 << bit)) {
                ans[mask ^ (1 << bit)] = sub(ans[mask ^ (1 << bit)], ans[mask]);
            }
        }
    }
    int tot_s = 0;
    for (int mask = 0; mask < (1 << n); mask++) tot_s = sum(tot_s, ans[mask]);
    for (int bit = 0; bit < n; bit++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            if (mask & (1 << bit)) {
                ans[mask] = sum(ans[mask], ans[mask ^ (1 << bit)]);
            }
        }
    }
    ll xr = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        int k = 0;
        int s = 0;
        for (int bit = 0; bit < n; bit++) {
            if (mask & (1 << bit)) {
                k++;
                s += (bit + 1);
            }
        }
        int cur_ans = sub(tot_s, ans[((1 << n) - 1) ^ mask]);
        xr ^= ((ll)cur_ans * (ll)k * s);
    }
    cout << xr << '\n';
    return 0;
}