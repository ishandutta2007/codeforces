#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = (int)1e5 + 100;
int a[maxN];
int lp[maxN];
vector < int > pr[maxN];
pair < int, int > all[maxN];
bool used[maxN];
vector < pair < int, int > > pri[maxN];
int mu[maxN];
vector < int > so[maxN];
int cnt[maxN];
void add(int x) {
    for (int v : so[x]) cnt[v]++;
}
bool ok(int x) {
    int ans = 0;
    for (int v : so[x]) {
        ans += cnt[v] * mu[v];
    }
    return ans > 0;
}
bool check(ll x) {
    for (int d = 1; d < maxN; d++) {
        vector<int> all;
        int lim = ((int)1e5 + d - 1) / d;
        for (int i = 1; i <= lim; i++) cnt[i] = 0;
        for (int i = d; i < maxN; i += d) {
            if (used[i]) all.push_back(i / d);
        }
        if (all.size() <= 1) continue;
        int r = all.size() - 1;
        for (int v = 0; v < all.size(); v++) {
           // if (v >= r) break;
            while (r > v && 1LL * all[r] * all[v] * d >= x) {
                add(all[r]);
                r--;
            }
            if (ok(all[v])) {
                return true;
            }
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    ll mx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mx = max(mx, (ll)a[i]);
    }
    for (int i = 2; i < maxN; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            for (int j = 2 * i; j < maxN; j += i) {
                lp[j] = i;
            }
        }
    }
    so[1].push_back(1);
    for (int i = 2; i < maxN; i++) {
        int t = i;
        while (t > 1) {
            int p = lp[t];
            int ex = 0;
            while (t % p == 0) {
                t /= p;
                ex++;
            }
            pri[i].emplace_back(p, ex);
        }
        sort(pri[i].begin(), pri[i].end());
        for (int mask = 0; mask < (1 << pri[i].size()); mask++) {
            int who = 1;
            for (int bit = 0; bit < pri[i].size(); bit++) {
                if (mask & (1 << bit)) who *= pri[i][bit].first;
            }
            so[i].push_back(who);
        }
    }
    mu[1] = 1;
    for (int i = 2; i < maxN; i++) {
        if ((i / lp[i]) % lp[i] == 0) mu[i] = 0;
        else mu[i] = -mu[i / lp[i]];
    }
    for (int i = 1; i <= n; i++) {
        if (used[a[i]]) continue;
        int c = a[i];
        used[c] = true;
    }
    ll l = 0;
    ll r = 1e10 + 2;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << max(l, mx);
    // prop
    return 0;
}