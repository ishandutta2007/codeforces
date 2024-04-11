#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

struct RangeTree {
    int n = 0; // [0, n)
    vector<int> t;

    RangeTree() = default;

    RangeTree(int nn) {
        n = nn;
        t.resize(4 * n, -1);
    }

    void merge(int v) {
        t[v] = max(t[v << 1], t[v << 1 | 1]);
    }

    void update(int v, int tl, int tr, int pos, int value) {
        if (tl == tr) {
            t[v] = value;
        } else {
            int tm = (tl + tr) >> 1;
            if (pos <= tm)
                update(v << 1, tl, tm, pos, value);
            else
                update(v << 1 | 1, tm + 1, tr, pos, value);
            merge(v);
        }
    }

    void update(int pos, int value) {
        update(1, 0, n - 1, pos, value);
    }

    int query(int v, int tl, int tr, int l, int r) {
        if (l <= tl && tr <= r) {
            return t[v];
        } else {
            int tm = (tl + tr) >> 1, res = -1;
            if (l <= tm)
                res = max(res, query(v << 1, tl, tm, l, r));
            if (r > tm)
                res = max(res, query(v << 1 | 1, tm + 1, tr, l, r));
            return res;
        }
    }

    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

struct HLD {
    int n = 0; // [0, n)
    vector<int> p, sz, pos, top, tin;
    vector<vector<int>> g;
    RangeTree rt;
    int timer = 0;

    HLD() = default;

    HLD(vector<int> link) {
        n = (int) link.size();
        p = link;
        g.resize(n);
        for (int i = 1; i < n; i++)
            g[p[i]].push_back(i);
        sz.resize(n, 0);
        dfs(0);
        pos.resize(n, 0);
        top.resize(n, 0);
        tin.resize(n);
        go(0);
        rt = RangeTree(n);
    }

    void go(int v) {
        tin[v] = timer++;
        for (int i = 0; i < (int) g[v].size(); i++) {
            int to = g[v][i];
            if (i == 0) {
                top[to] = top[v];
                pos[to] = pos[v] + 1;
            } else {
                top[to] = to;
                pos[to] = 0;
            }
            go(to);
        }
    }

    void dfs(int v) {
        sz[v] = 1;
        for (int to : g[v]) {
            dfs(to);
            sz[v] += sz[to];
        }
        if (!g[v].empty()) {
            int pos = max_element(g[v].begin(), g[v].end(), [&](int to1, int to2){
                return sz[to1] < sz[to2];
            }) - g[v].begin();
            swap(g[v][0], g[v][pos]);
        }
    }

    void update(int v, int x) {
        rt.update(tin[top[v]] + pos[v], x);
    }

    int query(int v) {
        int res = -1;
        while (1) {
            res = max(res, rt.query(tin[top[v]], tin[top[v]] + pos[v]));
            v = top[v];
            if (!v)
                break;
            v = p[v];
        }
        return res;
    }
};

const int A = 26; // alphabet size
struct Aho {

    struct Node {
        int nxt[A], go[A];
        int par, pch, link;
        multiset<int> values;

        Node():
                par(-1), pch(-1), link(-1)
        {
            fill(nxt, nxt + A, -1);
            fill(go, go + A, -1);
        }
    };

    vector< Node > a;
    HLD hld;

    Aho() {
        a.push_back(Node());
    }

    int add_string(const string &s) {
        int v = 0;
        for(char c : s) {
            c -= 'a';
            if(a[v].nxt[c] == -1) {
                a[v].nxt[c] = (int)a.size();
                a.push_back(Node());
                a.back().par = v;
                a.back().pch = c;
            }
            v = a[v].nxt[c];
        }
        a[v].values.insert(0);
        return v;
    }

    int go(int v, int c) {
        if(a[v].go[c] == -1) {
            if(a[v].nxt[c] != -1) {
                a[v].go[c] = a[v].nxt[c];
            }else {
                a[v].go[c] = v ? go(get_link(v), c) : 0;
            }
        }
        return a[v].go[c];
    }

    int get_link(int v) {
        if(a[v].link == -1) {
            if(!v || !a[v].par) a[v].link = 0;
            else a[v].link = go(get_link(a[v].par), a[v].pch);
        }
        return a[v].link;
    }

    void push_links() {
        for (int v = 0; v < (int) a.size(); v++)
            get_link(v);
        vector<int> link(a.size());
        for (int i = 0; i < (int) a.size(); i++)
            link[i] = a[i].link;
        hld = HLD(link);
    }

    int query(const string& q) {
        int v = 0;
        int res = -1;
        for (char c : q) {
            c -= 'a';
            v = go(v, c);
            res = max(res, hld.query(v));
        }
        return res;
    }

    void update(int v, int was, int now) {
        a[v].values.erase(a[v].values.lower_bound(was));
        a[v].values.insert(now);
        hld.update(v, a[v].values.empty() ? -1 : *(--a[v].values.end()));
    }
};

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    Aho aho;
    vector<int> pos(n), cur(n);

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        pos[i] = aho.add_string(s);
    }
    aho.push_links();

    for (int i = 0; i < n; i++)
        aho.update(pos[i], 0, 0);

    for (int it = 0; it < m; it++) {
        int ty;
        cin >> ty;
        if (ty == 1) {
            int i, x;
            cin >> i >> x;
            i--;
            aho.update(pos[i], cur[i], x);
            cur[i] = x;
        } else {
            string q;
            cin >> q;
            cout << aho.query(q) << "\n";
        }
    }

    return 0;
}