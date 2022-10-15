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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> indeg(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        indeg[a[i]]++;
    }
    set<int> kekw;
    for (int i = 1; i <= n; i++) {
        if (!indeg[i]) {
            kekw.insert(i);
        }
    }
    vector<int> b(n + 1);
    vector<int> used(n + 1);
    int unused = 1;
    int prev = -1;
    int xyi = -1;
    if (!kekw.empty()) {
        xyi = *kekw.begin();
    }
    while (true) {
        int start = -1;
        if (kekw.empty()) {
            break;
        } else {
            start = *kekw.begin();
            kekw.erase(kekw.begin());
        }
        if (prev != -1) {
            b[prev] = start;
        }
        used[start] = 1;
        int cur = start;
        while (!used[a[cur]]) {
            b[cur] = a[cur];
            cur = a[cur];
            used[cur] = 1;
        }
        if (a[cur] == start && prev == -1) {
            b[cur] = a[cur];
            prev = -1;
            continue;
        }
        prev = cur;
    }
    for (int i = 1; i <= n; i++) {
        if (used[i]) continue;
        used[i] = 1;
        int cur = i;
        while (!used[a[cur]]) {
            b[cur] = a[cur];
            cur = a[cur];
            used[cur] = 1;
        }
        b[cur] = i;
    }

    for (int i = 1; i <= n; i++) {
        if (!b[i]) {
            b[i] = xyi;
        }
    }

    int k = 0;
    for (int i = 1; i <= n; i++) {
        k += a[i] == b[i];
    }
    cout << k << '\n';
    for (int i = 1; i <= n; i++) {
        cout << b[i] << " \n"[i == n];
    }
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