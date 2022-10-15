#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
 
ll binpow(ll a, ll p, int mod = MOD) {
    ll res = 1;
    a %= mod;
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

ll go(int l, int r, const string& s) {
    if (l == r) {
        return s[l] - '0';
    }
    int mid = (l + r) / 2;
    // [l, mid] [mid + 1, r]
    ll res = go(l, mid, s) + go(mid + 1, r, s);
    vector<int> lenL(mid - l + 1), suf(mid - l + 1);
    int cur = 0;
    int len = 0;
    for (int i = 0; i < mid - l + 1; i++) {
        if (s[mid - i] == '1') {
            cur++;
            len = max(len, cur);
        } else {
            cur = 0;
        }
        lenL[i] = max(lenL[i], len);
    }
    int ok = 1;
    for (int i = 0; i < mid - l + 1; i++) {
        if (s[mid - i] == '0') ok = 0;
        if (ok) {
            suf[i] = i + 1;
        } else {
            suf[i] = i ? suf[i - 1] : 0;
        }
    }
    vector<int> lenR(r - mid), pref(r - mid);
    cur = len = 0;
    for (int i = 0; i < r - mid; i++) {
        if (s[mid + i + 1] == '1') {
            cur++;
            len = max(len, cur);
        } else {
            cur = 0;
        }
        lenR[i] = max(lenR[i], len);
    }
    ok = 1;
    for (int i = 0; i < r - mid; i++) {
        if (s[mid + i + 1] == '0') ok = 0;
        if (ok) {
            pref[i] = i + 1;
        } else {
            pref[i] = i ? pref[i - 1] : 0;
        }
    }

    vector<int> aux(r - mid);
    vector<ll> prefSum(r - mid);
    for (int j = 0; j < r - mid; j++) {
        aux[j] = lenR[j] - pref[j];
        prefSum[j] = (j ? prefSum[j - 1] : 0) + pref[j];
    }
    for (int i = 0; i < mid - l + 1; i++) {
        // lenR[j] <= lenL[i] and pref[j] <= lenL[i] - suf[i]
        int j1 = upper_bound(lenR.begin(), lenR.end(), lenL[i]) - lenR.begin();
        int j2 = upper_bound(pref.begin(), pref.end(), lenL[i] - suf[i]) - pref.begin();
        res += 1LL * lenL[i] * min(j1, j2);
        // lenL[i] - suf[i] < pref[j] and suf[i] > lenR[j] - pref[j]
        j1 = upper_bound(pref.begin(), pref.end(), lenL[i] - suf[i]) - pref.begin();
        j2 = lower_bound(aux.begin(), aux.end(), suf[i]) - aux.begin();
        // j2 > j >= j1
        if (j1 < j2) {
            res += 1LL * suf[i] * (j2 - j1) + prefSum[j2 - 1] - (j1 ? prefSum[j1 - 1] : 0); 
        }
    }
    for (int j = 0; j < r - mid; j++) {
        // lenL[i] < lenR[j] and suf[i] <= lenR[j] - pref[j]
        int i1 = lower_bound(lenL.begin(), lenL.end(), lenR[j]) - lenL.begin();
        int i2 = upper_bound(suf.begin(), suf.end(), lenR[j] - pref[j]) - suf.begin();
        res += 1LL * lenR[j] * min(i1, i2);
    }
    return res;
}

void solve() {
    int n;
    string s;
    cin >> n >> s;
    cout << go(0, n - 1, s) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";  
        solve();
    }
    return 0;
}