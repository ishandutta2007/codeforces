#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using big_int = __int128;
int const nax = 2048;
const int mod = 1000000007;//
ll const inf = 1e18;
void plusle (int &a, int b) {
    if (( a += b) >= mod ) a -= mod ;
}
void minun (int &a, int b) {
    if ((a -= b) < 0) a += mod ;
}
int add (int a, int b) {
    return (( a += b ) >= mod ) ? a - mod  : a;
}
int sub (int a, int b) {
    return (( a -= b) < 0) ? a + mod : a;
}
int mul (int a, int b) {
    return 1LL * a * b % mod;
}
int power (int a, int b) {
    int res = 1;
    for (; b > 0 ; b >>= 1 , a = mul(a, a))
        if (b & 1) res = mul(res, a);
    return res ;
}

struct edge_t {
    int from, to, w;
    edge_t () {}
    edge_t (int from, int to ,int w) : from(from) , to(to), w(w) {}
};
vector <edge_t> edge;

int n, m, q;
vector <pair <int, int>> a[nax];
long long dist[nax][nax];
int ans;
int best_edge[nax];
typedef long double ld;

struct frac {
    ll a, b;

    frac (ll _a, ll _b) {
        if (_b < 0) _a = -_a, _b= -_b;
        a = _a, b = _b;
    }

    friend bool operator <= (const frac &x, const frac &y) {
        return (big_int)x.a * y.b <= (big_int)x.b * y.a;
    }
};

struct line_t {
    ll m, c;

    line_t () {}
    line_t (ll m, ll c): m(m), c(c) {}

    frac intersect_x (line_t other) {
        return frac(c - other.c, other.m - m);
    }
};

void bellman_ford () {
    dist[0][1] = 0;
    for (int i = 2 ; i <= n ; ++ i)
        dist[0][i] = -inf;

    for (int i = 1 ; i <= n - 1 ; ++ i) {

        for (int j = 1 ; j <= n ; ++ j)
            dist[i][j] = -inf;

        for (auto &[from, to, w] : edge) {
            dist[i][to] = max(dist[i][to], dist[i - 1][from] + w);
            dist[i][from] = max(dist[i][from], dist[i - 1][to] + w);
        }

        ll mx = -inf;

        for (int j = 1 ; j <= n; ++ j) {
            mx = max(mx, dist[i][j]);
        }

        if (i != n - 1)
            ans = add(ans, mx % mod);
    }
}

void build_hull () {

    vector <line_t> line;

    for (int i = 1 ; i <= n; ++ i) {
        line.emplace_back(best_edge[i], dist[n - 1][i]);
    }

    sort(line.begin(), line.end(), [] (const line_t &x, const line_t &y) {
        if (x.m != y.m) return x.m < y.m;
        return x.c > y.c;
    });

    line.erase(unique(line.begin(), line.end(), [&](const line_t &x, const line_t &y) {
            return x.m == y.m;
    }), line.end()); /// well better not to have repeat slope

    vector <line_t> hull;

    for (auto cur : line) {

        while (int(hull.size()) >= 2 && cur.intersect_x(hull.back()) <= hull.back().intersect_x(hull[int(hull.size()) - 2]))
            hull.pop_back();
        hull.push_back(cur);
    }

    int s = hull.size();
    q -= n - 1;
    long long keep = 0;

    auto arithmetic_progression_sum = [&] (int start, int d, int num) -> int{
        int c = (1LL * start  * num ) % mod;
        int w = (c + (((1LL * num * (num - 1) / 2) % mod) * d % mod)) % mod;
        return int((w % mod + mod) % mod);
    };

    for (int i = 0 ; i < s - 1 ; ++ i) {

        frac x = hull[i].intersect_x(hull[i + 1]);
        if (x.a < 0) continue;
        long long t = min((ll)q, x.a / x.b); /// round down
        if (keep > t) continue;

        plusle(ans, arithmetic_progression_sum((hull[i].c + hull[i].m * keep) % mod, hull[i].m % mod, t - keep + 1));
        keep = t + 1;
    }

    plusle(ans, arithmetic_progression_sum((hull.back().c + hull.back().m * keep) % mod, hull.back().m % mod, q - keep + 1));
}

int main () {
    scanf("%d %d %d", &n, &m, &q);

    for (int i = 1 ; i <= m; ++ i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        best_edge[u] = max(best_edge[u], w);
        best_edge[v] = max(best_edge[v], w);
        edge.emplace_back(u, v, w);
    }

    bellman_ford();
    build_hull();

    printf("%d\n", ans);
}