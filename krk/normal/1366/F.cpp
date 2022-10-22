#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll is_query = -(1LL<<62);
struct Line {
    ll m, b;
    mutable function<const Line*()> succ;
    bool operator<(const Line& rhs) const {
        if (rhs.b != is_query) return m < rhs.m;
        const Line* s = succ();
        if (!s) return 0;
        ll x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};
struct HullDynamic : public multiset<Line> { // will maintain upper hull for maximum
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;

        // **** May need long double typecasting here
        return (long double)(x->b - y->b)*(z->m - y->m) >= (long double)(y->b - z->b)*(y->m - x->m);
    }
    void insert_line(ll m, ll b) {
        auto y = insert({ m, b });
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
    ll eval(ll x) {
        auto l = *lower_bound((Line) { x, is_query });
        return l.m * x + l.b;
    }
};

HullDynamic hd;

typedef pair <int, int> ii;

const int Maxn = 2005;
const int mod = 1000000007;
const int Inf = (Maxn + 5) * 1000000;
const int inv2 = (mod + 1) / 2;

int n, m, q;
vector <ii> neigh[Maxn];
int dist[Maxn][Maxn];
int my[Maxn];
int res;

int main()
{
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 0; i < m; i++) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        neigh[a].push_back(ii(b, c));
        neigh[b].push_back(ii(a, c));
    }
    fill((int*)dist, (int*)dist + Maxn * Maxn, -Inf);
    dist[0][1] = 0;
    for (int i = 0; i + 1 < Maxn; i++) {
        for (int v = 1; v <= n; v++)
            for (int j = 0; j < neigh[v].size(); j++) {
                auto u = neigh[v][j];
                dist[i + 1][u.first] = max(dist[i + 1][u.first], dist[i][v] + u.second);
            }
        my[i + 1] = -Inf;
        for (int v = 1; v <= n; v++)
            my[i + 1] = max(my[i + 1], dist[i + 1][v]);
        if (i + 1 <= q) res = (res + ll(my[i + 1])) % mod;
    }
    for (int v = 1; v <= n; v++) {
        int add = 0;
        for (int j = 0; j < neigh[v].size(); j++)
            add = max(add, neigh[v][j].second);
        hd.insert_line(add, dist[Maxn - 1][v] - ll(Maxn - 1) * add);
    }
    int nxt = Maxn;
    while (nxt <= q) {
        auto in = hd.eval(nxt);
        ll mor = hd.eval(nxt + 1) - in;
        int lef = nxt, rig = q;
        while (lef <= rig) {
            int mid = lef + rig >> 1;
            ll dif = hd.eval(mid) - in;
            if (dif == (mid - lef) * mor) lef = mid + 1;
            else rig = mid - 1;
        }
        res = (res + (in + in + mor * (rig - nxt)) % mod * inv2 % mod * (rig - nxt + 1)) % mod;
        nxt = rig + 1;
    }
    cout << res << endl;
    return 0;
}