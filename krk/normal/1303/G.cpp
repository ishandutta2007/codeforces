#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

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

int n;
int a[Maxn];
vector <int> neigh[Maxn];
bool er[Maxn];
int cnt[Maxn];
ll res;

void Count(int v, int p)
{
    cnt[v] = 1;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p || er[u]) continue;
        Count(u, v);
        cnt[v] += cnt[u];
    }
}

int getCentroid(int v, int p, int sz)
{
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p || er[u]) continue;
        if (cnt[u] > sz / 2) return getCentroid(u, v, sz);
    }
    return v;
}

void endB(int v, int p, ll asum, ll sum, int cnt, HullDynamic &hd)
{
    sum += a[v]; cnt++;
    asum += sum;
    bool had = false;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p || er[u]) continue;
        endB(u, v, asum, sum, cnt, hd);
        had = true;
    }
    if (!had) res = max(res, hd.eval(cnt) + asum);
}

void endA(int v, int p, ll asum, ll sum, int cnt, HullDynamic &hd)
{
    sum += a[v]; cnt++;
    asum += ll(a[v]) * cnt;
    bool had = false;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p || er[u]) continue;
        endA(u, v, asum, sum, cnt, hd);
        had = true;
    }
    if (!had) hd.insert_line(sum, asum);
}

void Solve(int v)
{
    Count(v, 0);
    int r = getCentroid(v, 0, cnt[v]);
    HullDynamic hd;
    hd.insert_line(a[r], a[r]);
    for (int i = 0; i < neigh[r].size(); i++) {
        int u = neigh[r][i];
        if (er[u]) continue;
        endB(u, r, 0, 0, 0, hd);
        endA(u, r, a[r], a[r], 1, hd);
    }
    HullDynamic bhd;
    bhd.insert_line(0, 0);
    for (int i = int(neigh[r].size()) - 1; i >= 0; i--) {
        int u = neigh[r][i];
        if (er[u]) continue;
        endB(u, r, 0, 0, 0, bhd);
        endA(u, r, a[r], a[r], 1, bhd);
    }
    res = max(res, bhd.eval(0));
    er[r] = true;
    for (int i = 0; i < neigh[r].size(); i++) {
        int u = neigh[r][i];
        if (er[u]) continue;
        Solve(u);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    Solve(1);
    printf("%I64d\n", res);
    return 0;
}