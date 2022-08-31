#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
struct dsu{
    vector < int > sz;
    vector < pair < int*, int > > roll_back;
    vector < int > p;
    vector < int > dist;
    int all_bipartite;
    void init(int n) {
        sz.resize(n + 1);
        p.resize(n + 1);
        dist.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            sz[i] = 1;
            p[i] = i;
            dist[i] = 0;
        }
        all_bipartite = 1;
    }
    pair < int, int > parent(int a) {
        int cnt = 0;
        while (a != p[a]) {
            cnt ^= dist[a];
            a = p[a];
        }
        return make_pair(a, cnt & 1);
    }
    void unite(int a, int b, int& num) {
        pair < int, int > t1 = parent(a);
        pair < int, int > t2 = parent(b);
        if (t1.first == t2.first) {
            if (t1.second == t2.second) {
                roll_back.push_back(make_pair(&all_bipartite, all_bipartite));
                num++;
                all_bipartite = 0;
            }
        }
        else {
            int para = t1.first;
            int parb = t2.first;
            if (sz[para] > sz[parb]) {
                swap(para, parb);
                swap(a, b);
            }
            roll_back.push_back(make_pair(&p[para], p[para]));
            roll_back.push_back(make_pair(&sz[parb], sz[parb]));
            roll_back.push_back(make_pair(&dist[para], dist[para]));
            num += 3;
            p[para] = parb;
            dist[para] = (t1.second ^ t2.second) ^ 1;
            sz[parb] += sz[para];
        }
    }
    void get_bipartite() {
        if (all_bipartite == 1) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    void go_back(int x) {
        for (int i = 0; i < x; i++) {
            *roll_back.back().first = roll_back.back().second;
            roll_back.pop_back();
        }
    }
} dsu;
const int maxN = (int)1e5 + 10;
int n, q;
map < pair < int, int >, int > last_time;
struct edge{
    int a, b;
    edge (int _a, int _b) {
        a = _a;
        b = _b;
    }
};
vector < edge > t[4 * maxN];
int val[4 * maxN];
void addEdge(int v, int tl, int tr, int l, int r, edge x) {
    if (l > tr || r < tl) return ;
    if (l <= tl && tr <= r) {
        t[v].push_back(x);
        return ;
    }
    int tm = (tl + tr) / 2;
    addEdge(v + v, tl, tm, l, r, x);
    addEdge(v + v + 1, tm + 1, tr, l, r, x);
}
void go(int v, int tl, int tr) {
    for (auto it : t[v]) {
        //if (tl <= 4 && 4 <= tr) cout << it.a << " " << it.b << endl;
        dsu.unite(it.a, it.b, val[v]);
    }
    if (tl == tr) {
        dsu.get_bipartite();
    }
    else {
        int tm = (tl + tr) / 2;
        go(v + v, tl, tm);
        go(v + v + 1, tm + 1, tr);
    }
    dsu.go_back(val[v]);
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> q;
    dsu.init(n);
    set < pair < pair < int, int >, int > > s;
    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        auto it = s.lower_bound(make_pair(make_pair(x, y), 0));
        if (it == s.end() || ((*it).first != make_pair(x, y))) {
            s.insert(make_pair(make_pair(x, y), i));
        }
        else {
            auto t = *it;
            edge x(t.first.first, t.first.second);
            addEdge(1, 1, q, t.second, i - 1, x);
            s.erase(it);
        }
    }
    for (auto t : s) {
        edge x(t.first.first, t.first.second);
        addEdge(1, 1, q, t.second, q + 1, x);
    }
    go(1, 1, q);
    return 0;
}