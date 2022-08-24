#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 2 * (int)1e5 + 10;
ll fenw[2][maxN];
int n, m;
void add(int pos, ll val, int tp) {
    while (pos <= n) {
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
        if (p <= n && fenw[0][p] < lim) {
            lim -= fenw[0][p];
            res += (1 << k);
        }
    }
    return res + 1;
}
int p[maxN];
ll t;
vector < int > by_val[maxN];
ll count_time(int i) {
    int cnt = (int)get_sum(1, i, 0);
    int blocks = max(0, (cnt - 1) / m);
    if (blocks == 0) {
        return get_sum(1, i, 1);
    }
    int pos = lower_bound(blocks * m);
    assert(get_sum(1, pos, 0) == blocks * m);
    assert(get_sum(1, pos - 1, 0) < blocks * m);
    ll sum = 2 * get_sum(1, pos, 1);
    ll other = get_sum(pos + 1, i, 1);
    return sum + other;
}
void solve() {
    cin >> n >> m >> t;
    set < int > inter;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        inter.insert(p[i]);
        by_val[p[i]].push_back(i);
    }
    set < int > all_poses;
    int max_tasks = 0;
    int opt_d = 1;
    for (int v : inter) {
        for (int x : by_val[v]) {
            add(x, 1, 0);
            add(x, v, 1);
            all_poses.insert(x);
        }
        while (true) {
            if (all_poses.empty()) break;
            int pos = *(--all_poses.end());
            if (count_time(pos) > t) {
                add(pos, -1, 0);
                add(pos, -p[pos], 1);
                all_poses.erase(pos);
            }
            else {
                break;
            }
        }
        int upd = (int)get_sum(1, n, 0);
        if (upd > max_tasks) {
            assert(count_time(n) <= t);
            opt_d = v;
            max_tasks = upd;
        }
    }
    cout << max_tasks << " " << opt_d << '\n';


    /////// clear
    for (int v : inter) {
        by_val[v].clear();
    }
    for (int v : all_poses) {
        add(v, -1, 0);
        add(v, -p[v], 1);
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tst;
    cin >> tst;
    while (tst--) solve();
    return 0;
}