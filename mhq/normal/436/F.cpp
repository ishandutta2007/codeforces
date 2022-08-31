#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = (int)1e5 + 100;
const int BLOCK = 250;
int bl[maxN];
struct pt{
    ll x, y;
    pt(ll _x, ll _y) {
        x = _x;
        y = _y;
    }
};
bool del(const pt& x, const pt& y, const pt& z) {
    return (y.y - x.y) * (x.x - z.x) <= (z.y - x.y) * (x.x - y.x);
}
ll get(const pt& a, ll y) {
    return (a.x * y + a.y);
}
const ll INF = 2 * (ll)1e18;
vector < pt > cht[maxN];
void add(ll x, ll y, int bl) {
    pt nw(x, y);
    while (cht[bl].size() >= 2 && del(cht[bl][cht[bl].size() - 1], cht[bl][cht[bl].size() - 2], nw)) {
        cht[bl].pop_back();
    }
    cht[bl].push_back(nw);
}
pair < ll, int > get(ll x, int bl) {
    if (cht[bl].empty()) return make_pair(-INF, -1);
    int l = 0;
    int r = cht[bl].size() - 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (get(cht[bl][m], x) > get(cht[bl][m + 1], x)) {
            r = m;
        }
        else l = m;
    }
    return max(make_pair(get(cht[bl][r], x), cht[bl][r].x), make_pair(get(cht[bl][l], x), cht[bl][l].x));
}
int f[maxN];
int n, w;
int lim;
void build(int v) {
    cht[v].clear();
    for (int i = v * BLOCK; i <= min(lim - 1, (v + 1) * BLOCK - 1); i++) {
        add(i, 1LL * f[i] * i, v);
    }
}
vector < int > byB[maxN];
void add(int v) {
    int i = 0;
    while (i + BLOCK - 1 <= v) {
        bl[i / BLOCK]++;
        i += BLOCK;
    }
    if (i <= v) {
        int l = i;
        int r = min(i + BLOCK - 1, lim - 1);
        int id = i / BLOCK;
        for (int j = l; j <= r; j++) {
            f[j] += bl[id];
        }
        bl[id] = 0;
        for (int j = l; j <= v; j++) {
            f[j]++;
        }
        build(id);
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> w;
    int max_a = 0;
    int max_b = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        byB[b].push_back(a);
        max_a = max(max_a, a);
        max_b = max(max_b, b);
    }
    lim = max_a + 3;
    for (int i = 0; i * BLOCK < lim; i++) {
        build(i);
    }
    int num_c = n;
    vector < pair < ll, int > > ans;
    for (int i = 0; i <= max_b + 1; i++) {
        if (i > 0) {
            for (int a : byB[i - 1]) {
                add(a);
                num_c--;
            }
        }
        pair < ll, int > best = make_pair(-INF, -1);
        for (int j = 0; j * BLOCK < lim; j++) {
            best = max(best, get(bl[j], j));
        }
        cout << (1LL * num_c * w * i + best.first) << " " << best.second << '\n';
    }
    return 0;
}