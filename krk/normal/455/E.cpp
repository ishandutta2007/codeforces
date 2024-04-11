#include <bits/stdc++.h>
using namespace std;

// Dynamic convex hull implementation found online. I can't find the source of this code anymore.
typedef long long ll;

const ll Inf = 1000000000000000000ll;
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
        m = -m; b = -b;
        auto y = insert({ m, b });
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
    ll eval(ll x) {
        if (this->empty()) return Inf;
        auto l = *lower_bound((Line) { x, is_query });
        return -(l.m * x + l.b);
    }
};


const int Maxn = 100005;
const int Maxm = 524288;

HullDynamic hd[Maxm];
ll nil;
int n;
int a[Maxn];
int m;
int qx[Maxn], qy[Maxn];
vector <int> quer[Maxn];
int res[Maxn];

void Update(int v, int l, int r, int a, int b, ll la, ll lb)
{
    if (l == a && r == b) hd[v].insert_line(la, lb);
    else {
        int m = l + r >> 1;
        if (a <= m) Update(2 * v, l, m, a, min(m, b), la, lb);
        if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b, la, lb);
    }
}

ll Get(int v, int l, int r, int ind)
{
    ll res = hd[v].eval(ind);
    if (l < r) {
        int m = l + r >> 1;
        if (ind <= m) res = min(res, Get(2 * v, l, m, ind));
        else res = min(res, Get(2 * v + 1, m + 1, r, ind));
    }
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &qx[i], &qy[i]);
        quer[qy[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        Update(1, 1, n, 1, i, -a[i], i * a[i] - nil);
        nil += a[i];
        for (int j = 0; j < quer[i].size(); j++) {
            int ind = quer[i][j];
            res[ind] = Get(1, 1, n, qy[ind] - qx[ind] + 1) + nil;
        }
    }
    for (int i = 1; i <= m; i++)
        printf("%d\n", res[i]);
    return 0;
}