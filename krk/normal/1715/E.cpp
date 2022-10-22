#include <bits/stdc++.h>
using namespace std;
// Dynamic convex hull implementation found online. I can't find the source of this code anymore.
typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ll, int> lli;

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
        auto y = insert({ -m, -b });
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
    ll eval(ll x) {
        auto l = *lower_bound((Line) { x, is_query });
        return -(l.m * x + l.b);
    }
};

const ll Inf = 1000000000000000000ll;
const int Maxn = 100005;
const int Maxk = 22;

int n, m, k;
vector <ii> neigh[Maxn];
ll dist[Maxn];

void Dijkstra(ll dist[])
{
    priority_queue <lli> Q;
    for (int i = 1; i <= n; i++)
        Q.push(lli(-dist[i], i));
    while (!Q.empty()) {
        int v = Q.top().second;
        ll d = -Q.top().first; Q.pop();
        if (dist[v] != d) continue;
        for (int i = 0; i < neigh[v].size(); i++) {
            int u = neigh[v][i].first;
            ll cand = d + neigh[v][i].second;
            if (cand < dist[u]) {
                dist[u] = cand;
                Q.push(lli(-dist[u], u));
            }
        }
    }
}

void addFlights(ll dist[])
{
    HullDynamic hd;
    for (int i = 1; i <= n; i++) if (dist[i] < Inf)
        hd.insert_line(-2 * i, ll(i) * i + dist[i]);
    for (int i = 1; i <= n; i++)
        dist[i] = hd.eval(i) + ll(i) * i;
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        neigh[a].push_back(ii(b, c));
        neigh[b].push_back(ii(a, c));
    }
    dist[1] = 0;
    fill(dist + 2, dist + n + 1, Inf);
    Dijkstra(dist);
    for (int i = 1; i <= k; i++) {
        addFlights(dist);
        Dijkstra(dist);
    }
    for (int i = 1; i <= n; i++)
        printf("%I64d%c", dist[i], i + 1 <= n? ' ': '\n');
    return 0;
}