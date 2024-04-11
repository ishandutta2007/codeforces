#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> cnt(3);
    map<char, int> id;
    id['0'] = 0;
    id['1'] = 1;
    id['?'] = 2;
    int ok = 1;
    for (int i = k; i < n; i++) {
        if (id[s[i - k]] == 2) {
            s[i - k] = s[i];
        }
        if (id[s[i]] == 2) {
            s[i] = s[i - k];
        }
        ok &= id[s[i - k]] == id[s[i]];
    }
    for (int i = 0; i < k; i++) {
        cnt[id[s[i]]]++;
    }
    ok &= cnt[0] <= k / 2 && cnt[1] <= k / 2;
    for (int i = k; i < n; i++) {
        cnt[id[s[i]]]++;
        cnt[id[s[i - k]]]--;
        ok &= cnt[0] <= k / 2 && cnt[1] <= k / 2;   
    }

    cout << (ok ? "YES\n" : "NO\n");
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