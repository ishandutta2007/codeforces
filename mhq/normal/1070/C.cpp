#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = (int)1e6 + 10;
const int maxK = (int)1e6 + 1;
int n, k, m;
vector < pair < int, int > > in[maxN], out[maxN];
ll fenw[2][maxN];
void add(int pos, ll val, int tp) {
    while (pos <= maxK) {
        fenw[tp][pos] += val;
        pos = (pos | (pos - 1)) + 1;
    }
}
ll get_fenw(int r, int tp) {
    ll ans = 0;
    while (r > 0) {
        ans += fenw[tp][r];
        r &= (r - 1);
    }
    return ans;
}
ll get_sum(int l, int r, int tp) {
    if (l > r) return 0;
    return get_fenw(r, tp) - get_fenw(l - 1, tp);
}
int lower_bound(ll lim) {
    int lg = 21;
    int res = 0;
    for (int k = lg; k >= 0; k--) {
        int p = (res + (1 << k));
        if (p <= maxK && fenw[0][p] < lim) {
            lim -= fenw[0][p];
            res += (1 << k);
        }
    }
    return res + 1;
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k >> m;
    for (int i = 1; i <= m; i++) {
        int l, r, c, p;
        cin >> l >> r >> c >> p;
        in[l].emplace_back(make_pair(c, p));
        out[r + 1].emplace_back(make_pair(c, p));
    }
    ll total = 0;
    ll all = 0;
    for (int i = 1; i <= n; i++) {
        for (auto t : in[i]) {
            total += t.first;
            add(t.second, t.first, 0);
            add(t.second, 1LL * t.first * t.second, 1);
        }
        for (auto t : out[i]) {
            total -= t.first;
            add(t.second, -t.first, 0);
            add(t.second, -1LL * t.first * t.second, 1);
        }
        if (total < k) {
            all += get_sum(1, maxK, 1);
        }
        else {
            int t = lower_bound(k);
            ll already = get_sum(1, t - 1, 0);
            ll cur = get_sum(1, t - 1, 1);
            all += cur + (k - already) * t;
        }
    }
    cout << all;
    return 0;
}