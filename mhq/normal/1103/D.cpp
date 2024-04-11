#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll gcd(ll a, ll b) {
    while (a > 0 && b > 0) {
        if (a < b) swap(a, b);
        a %= b;
    }
    return a + b;
}
const int maxN = (int)1e6 + 10;
ll a[maxN];
ll k;
vector < ll > factor(ll x) {
    vector < ll > cur;
    for (int i = 2; 1LL * i * i <= x; i++) {
        if (x % i == 0) {
            while (x % i == 0) {
                x /= i;
            }
            cur.push_back(i);
        }
    }
    if (x > 1) cur.push_back(x);
    return cur;
}
int n;
int e[maxN];
int vals[maxN][13];
map < ll, int > all;
ll dp[10000][20];
ll ndp[10000][20];
vector < pair < int, int > > best[10000];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> e[i];
    }
    ll d = a[1];
    for (int i = 2; i <= n; i++) {
        d = gcd(d, a[i]);
    }
    if (d == 1) {
        cout << 0;
        return 0;
    }
    auto t = factor(d);
    vector < pair < ll, int > > ss;
    for (int i = 1; i <= n; i++) {
        ll cop = a[i];
        for (int j = 0; j < t.size(); j++) {
            while (cop % t[j] == 0) {
                cop /= t[j];
                vals[i][j]++;
            }
        }
        a[i] /= cop;
        ss.push_back(make_pair(a[i], e[i]));
    }
    sort(ss.begin(), ss.end());
    vector < pair < ll, int > > vals;
    int ii = 0;
    int m = t.size();
    while (ii < ss.size()) {
        int j = ii;
        while (j < ss.size() && ss[j].first == ss[ii].first) j++; j--;
        for (int k = ii; k <= j && k <= ii + m - 1; k++) vals.push_back(ss[k]);
        ii = j + 1;
    }
    for (int i = 0; i < (1 << m); i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = (ll)1e18;
            ndp[i][j] = (ll)1e18;
        }
    }
    dp[0][0] = 0;
    int r = vals.size();
    for (int u = 0; u < vals.size(); u++) {
        auto f = vals[u];
        vector < bool > is_good(1 << m, false);
        for (int i = 0; i < (1 << m); i++) {
            for (int j = 0; j <= m; j++) {
                ndp[i][j] = dp[i][j];
            }
            ll s = 1;
            ll x = f.first;
            for (int j = 0; j < m; j++) {
                if (!(i & (1 << j))) continue;
                while (x % t[j] == 0) {
                    s *= t[j];
                    x /= t[j];
                }
            }
            if (s <= k) {
                best[i].push_back(make_pair(f.second, u));
                is_good[i] = true;
            }
        }
    }
    vector < bool > need(vals.size(), false);
    for (int i = 0; i < (1 << m); i++) {
        sort(best[i].begin(), best[i].end());
        for (int j = 0; j < min((int)best[i].size(), m); j++) {
            need[best[i][j].second] = true;
        }
    }
    for (int u = 0; u < vals.size(); u++) {
        if (!need[u]) continue;
        auto f = vals[u];
        vector < bool > is_good(1 << m, false);
        for (int i = 0; i < (1 << m); i++) {
            for (int j = 0; j <= m; j++) {
                ndp[i][j] = dp[i][j];
            }
            ll s = 1;
            ll x = f.first;
            for (int j = 0; j < m; j++) {
                if (!(i & (1 << j))) continue;
                while (x % t[j] == 0) {
                    s *= t[j];
                    x /= t[j];
                }
            }
            if (s <= k) {
                is_good[i] = true;
            }
        }
        for (int i = 0; i < (1 << m); i++) {
            if (!is_good[i]) continue;
            int st = ((1 << m) - 1) ^ i;
            int msk = st;
            while (true) {
                for (int j = 0; j < m; j++) {
                    ndp[st | i][j + 1] = min(ndp[st | i][j + 1], dp[st][j] + f.second);
                }
                if (st == 0) break;
                st = (msk & (st - 1));
            }
        }
        for (int i = 0; i < (1 << m); i++) {
            for (int j = 0; j <= m; j++) {
                dp[i][j] = ndp[i][j];
            }
        }
    }
    ll mn = (ll)1e18 - 10;
    bool ok = false;
    for (int i = 0; i <= m; i++) {
        if (dp[(1 << m) - 1][i] > (ll)1e16) continue;
        ok = true;
        mn = min(mn, i * dp[(1 << m) - 1][i]);
    }
    if (ok) cout << mn;
    else cout << -1;
    return 0;
}