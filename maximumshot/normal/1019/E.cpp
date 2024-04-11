#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

struct Line {
    ll k = 0;
    ll b = 0;
    ld x0 = 0;
    int type = 0;

    Line() = default;

    Line(ll _k, ll _b, ld _x0 = 1e18, int _type = 0): k(_k), b(_b), x0(_x0), type(_type)
    { }

    Line operator+(const Line &o) const {
        return Line(k + o.k, b + o.b);
    }

    ld get_x(const Line &o) const {

        return ld(b - o.b) / ld(o.k - k);
    }

    ll operator()(ll x) const {
        return k * x + b;
    }

    bool operator<(const Line &o) const {
        if(type || o.type) {
            return x0 < o.x0;
        }else {
            return k < o.k;
        }
    }
};

struct CHT {

    set< Line > lines;

    void update_intersect(const set< Line >::iterator &it) {
        if(it == lines.end()) return;
        auto nxt = next(it);
        Line line = *it;
        if(nxt == lines.end()) line.x0 = 1e18;
        else line.x0 = it->get_x(*nxt);
        lines.insert(lines.erase(it), line);
    }

    bool valid(const set< Line >::iterator &it) const {
        return it != lines.end();
    }

    bool hasr(const set< Line >::iterator &it) const {
        return valid(it) && valid(next(it));
    }

    bool hasl(const set< Line >::iterator &it) const {
        return valid(it) && it != lines.begin() && valid(prev(it));
    }

    bool check(const set< Line >::iterator &it) const {
        if(!hasl(it) || !hasr(it)) return true;
        return prev(it)->get_x(*it) < next(it)->get_x(*it);
    }

    void add_line(Line l) {
        if(lines.empty()) { lines.insert(l); return; }
        auto fnd = lines.lower_bound(l);
        if(valid(fnd) && fnd->k == l.k) {
            if(fnd->b >= l.b) return;
            lines.erase(fnd);
        }
        fnd = lines.insert(l).first;
        if(!check(fnd)) {
            lines.erase(fnd);
            return;
        }
        auto hlp = fnd;
        while(hasr(fnd) && !check(hlp = next(fnd))) lines.erase(hlp);
        while(hasl(fnd) && !check(hlp = prev(fnd))) lines.erase(hlp);
        if(hasl(fnd)) update_intersect(prev(fnd));
        update_intersect(fnd);
    }

    int size() const {
        return (int)lines.size();
    }

    vec< Line > get_vector() const {
        return vec< Line >(ALL(lines));
    }

    ll get_max(ll x) {
        if(lines.empty()) return 0;

        Line line(x, x, x, 1);
        auto fnd = lines.lower_bound(line);

        ll res = 0;

        auto hlp = fnd;
        for(int i = 0;i < 2 && valid(hlp);i++, hlp++) {
            res = max(res, (*hlp)(x));
        }

        hlp = fnd;
        if(!valid(hlp)) hlp--;

        for(int i = 0;i < 2;i++) {
            res = max(res, (*hlp)(x));
            if(hlp == lines.begin()) break;
            else hlp--;
        }

        return res;
    }
};

const int N = 1e5 + 5;

vec< pair< int, Line > > g[N];
int _size[N];
int used[N];
CHT glob_cht;

void calc_size(int v, int par = -1) {
    _size[v] = 1;
    for(auto _edge : g[v]) {
        int to = _edge.first;
        if(used[to] || to == par) continue;
        calc_size(to, v);
        _size[v] += _size[to];
    }
}

void find_centroid(int v, int &centroid, int Size, int par = -1) {
    int mx_size = Size - _size[v];
    for(auto _edge : g[v]) {
        int to = _edge.first;
        if(used[to] || to == par) continue;
        find_centroid(to, centroid, Size, v);
        if(centroid != -1) return;
        if(_size[to] > mx_size) mx_size = _size[to];
    }
    if((mx_size << 1) <= Size) centroid = v;
}

void assign_hull(int v, CHT &cht, ll k, ll b, int par = -1) {
    cht.add_line(Line(k, b));
    for(auto _edge : g[v]) {
        int to = _edge.first;
        if(used[to] || to == par) continue;
        ll adk = _edge.second.k;
        ll adb = _edge.second.b;
        assign_hull(to, cht, k + adk, b + adb, v);
    }
}

void add_sum_to_glob_cht(const vec< Line > &L, const vec< Line > &R) {
    int i = 0;
    int j = 0;
    while(1) {
        glob_cht.add_line(L[i] + R[j]);
        if(i + 1 == (int)L.size() && j + 1 == (int)R.size()) break;
        if(i + 1 == (int)L.size()) j++;
        else if(j + 1 == (int)R.size()) i++;
        else {
            if(L[i].get_x(L[i + 1]) < R[j].get_x(R[j + 1])) i++;
            else j++;
        }
    }
}

CHT _merge(CHT l, CHT r) {
    vec< Line > ar = r.get_vector();
    for(Line _line : ar) {
        l.add_line(_line);
    }
    return l;
}

CHT global_update(vec< CHT > &hulls, int l, int r) {
    if(l > r) return CHT();
    if(l == r) return hulls[l];
    int m = l;
    {
        int tot = 0;
        for(int i = l;i <= r;i++) tot += hulls[i].size();
        int cur = hulls[m].size();
        while((cur << 1) < tot) {
            m++;
            cur += hulls[m].size();
        }
        if(m == r) m--;
    }
    assert(l <= m && m < r);
    CHT lcht = global_update(hulls, l, m);
    CHT rcht = global_update(hulls, m + 1, r);
    add_sum_to_glob_cht(lcht.get_vector(), rcht.get_vector());
    return _merge(lcht, rcht);
}

void solve(int v) {
    calc_size(v);
    int centroid = -1;
    find_centroid(v, centroid, _size[v]);
    assert(centroid != -1);

    used[centroid] = 1;
    vec< CHT > hulls;

    {
        CHT zero;
        zero.add_line(Line(0, 0));
        hulls.push_back(zero);
    }

    for(auto _edge : g[centroid]) {
        int to = _edge.first;
        if(used[to]) continue;
        ll start_k = _edge.second.k;
        ll start_b = _edge.second.b;
        CHT cht;
        assign_hull(to, cht, start_k, start_b, centroid);
        hulls.push_back(cht);
    }

    global_update(hulls, 0, (int)hulls.size() - 1);

    for(auto _edge : g[centroid]) {
        int to = _edge.first;
        if(used[to]) continue;
        solve(to);
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n, m;

    scanf("%d %d", &n, &m);

    for(int u, v, A, B, i = 1;i < n;i++) {
        scanf("%d %d %d %d", &u, &v, &A, &B);
        g[u].push_back({v, Line(A, B)});
        g[v].push_back({u, Line(A, B)});
    }

    solve(1);

    for(int x = 0;x < m;x++) {
        printf("%lld ", glob_cht.get_max(x));
    }

    printf("\n");

    return 0;
}