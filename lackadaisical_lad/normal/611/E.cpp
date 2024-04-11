#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

// const int MOD = 1e9 + 7;
const int MOD = 998244353;
 
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
    vector<int> a(3);
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> b{a[0] + a[1], a[0] + a[2], a[1] + a[2]};
    vector<vector<int>> cnt(4, vector<int>(4));
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t > a[0] + a[1] + a[2]) {
            cout << "-1\n";
            return;
        }
        int x = 0, y = 0;
        while (x < 3 && t > a[x]) x++;
        while (y < 3 && t > b[y]) y++;
        cnt[x][y]++;
    }
    assert(cnt[2][2] == 0);
    assert(cnt[1][1] == 0);
    int ans = cnt[3][3];
    cnt[3][3] = 0;
    
    {
        int delta = min(cnt[3][2], cnt[0][0]);
        ans += cnt[3][2];
        cnt[3][2] = 0;
        cnt[0][0] -= delta;
    }

    {
        int delta = min(cnt[3][1], cnt[1][0] + cnt[0][0]);
        ans += cnt[3][1];
        cnt[3][1] = 0;
        for (int j = 1; j >= 0; j--) {
            int epsilon = min(delta, cnt[j][0]);
            cnt[j][0] -= epsilon;
            delta -= epsilon;
        }
    }

    {
        int delta = min(cnt[3][0], cnt[2][0] + cnt[1][0] + cnt[0][0]);
        ans += cnt[3][0];
        cnt[3][0] = 0;
        for (int j = 2; j >= 0; j--) {
            int epsilon = min(delta, cnt[j][0]);
            cnt[j][0] -= epsilon;
            delta -= epsilon;
        }
    }

    int x = 0, y = 0;
    {
        ans += cnt[2][1];
        x += cnt[2][1];
        y += cnt[2][1];
        cnt[2][1] = 0;
    }

    int l = -1, r = 2e5 + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        vector<int> kek{mid + x, mid + y, mid};
        if (kek[2] < cnt[2][0]) {
            int need = cnt[2][0] - kek[2];
            kek[0] -= need;
            kek[1] -= need;
            kek[2] += need;
        } else {
            kek[1] += kek[2] - cnt[2][0];
            kek[2] = cnt[2][0];
        }
        if (kek[1] > cnt[1][0]) {
            kek[0] += kek[1] - cnt[1][0];
            kek[1] = cnt[1][0];
        }
        if (kek[0] < cnt[0][0] || kek[1] < cnt[1][0]) {
            l = mid;
        } else {
            r = mid;
        }
    }
    ans += r;
    cout << ans << '\n';
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