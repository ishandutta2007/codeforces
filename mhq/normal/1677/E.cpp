#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
struct Fenwick{
    vector<ll> f;
    int n;
    Fenwick(int _n) {
        n = _n;
        f.resize(n + 1);
    }
    void upd(int v, ll by) {
        while (v <= n) {
            f[v] += by;
            v = (v | (v - 1)) + 1;
        }
    }
    ll get(int r) {
        ll ans = 0;
        while (r > 0) {
            ans += f[r];
            r &= (r - 1);
        }
        return ans;
    }
};
int n, q;
const int maxN = 2e5 + 10;
const int maxQ = 1e6 + 10;
int pos[maxN];
vector<int> dvs[maxN];
int left_bigger[maxN], right_bigger[maxN];
int p[maxN];
vector<pair<int,int>> upd[maxN];
int l[maxQ], r[maxQ];
vector<int> ask[maxQ];
ll ans[maxQ];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) dvs[j].emplace_back(i);
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
    }
    vector<int> v;
    p[0] = p[n + 1] = n + 1;
    v.emplace_back(0);
    for (int i = 1; i <= n; i++) {
        while (p[v.back()] < p[i]) v.pop_back();
        left_bigger[i] = v.back() + 1;
        v.emplace_back(i);
    }
    v.clear();
    v.emplace_back(n + 1);
    for (int i = n; i >= 1; i--) {
        while (p[v.back()] < p[i]) v.pop_back();
        right_bigger[i] = v.back() - 1;
        v.emplace_back(i);
    }
//    for (int i = 1; i <= n; i++) {
//        cout << " hi " << left_bigger[i] << " " << right_bigger[i] << " " << i << " " << p[i] << endl;
//    }
    for (int i = 1; i <= n; i++) {
        vector<pair<int,int>> pts;
        for (int j : dvs[p[i]]) {
            if (j == (p[i] / j)) continue;
            int x = pos[j];
            int y = pos[p[i] / j];
            int b = i;
            int c = i;
            b = min({b, x, y});
            c = max({c, x, y});
            if (b < left_bigger[i] || c > right_bigger[i]) continue;
            pts.emplace_back(b, c);
        }
        pts.emplace_back(left_bigger[i] - 1, right_bigger[i] + 1);
        sort(pts.begin(), pts.end());
        reverse(pts.begin(), pts.end());
        int cur_mn = right_bigger[i] + 1;
        for (int it = 0; it + 1 < pts.size(); it++) {
            cur_mn = min(cur_mn, pts[it].second);
            int a = pts[it + 1].first + 1;
            int b = pts[it].first;
            int c = cur_mn;
            int d = right_bigger[i];
            if (a > b || c > d) continue;
//            cout << a << " " << b << " " << c << " " << d << " " << i << " " << p[i] << endl;
            upd[b].emplace_back(c, +1);
            if (d + 1 <= n) {
                upd[b].emplace_back(d + 1, -1);
            }
            if (a > 1) {
                upd[a - 1].emplace_back(c, -1);
                if (d + 1 <= n) {
                    upd[a - 1].emplace_back(d + 1, +1);
                }
            }
        }
    }
    for (int i = 1; i <= q; i++) {
        cin >> l[i] >> r[i];
        ask[l[i]].emplace_back(i);
    }
    Fenwick prod(n), fi(n), se(n), one(n);
    for (int i = n; i >= 1; i--) {
        for (auto& it : upd[i]) {
            prod.upd(it.first, 1LL * (i + 1) * (it.first - 1) * it.second);
            fi.upd(it.first, 1LL * (i + 1) * it.second);
            se.upd(it.first, 1LL * (it.first - 1) * it.second);
            one.upd(it.first, it.second);
        }
        for (auto& id : ask[i]) {
            int le = l[id];
            int ri = r[id];
            ans[id] -= prod.get(ri);
            ans[id] -= one.get(ri) * 1LL * le * ri;
            ans[id] += fi.get(ri) * ri;
            ans[id] += se.get(ri) * le;
        }
    }
    for (int i = 1; i <= q; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}