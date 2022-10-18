#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1 << 19;

struct pt {
    int x, y;

    pt() {}
    pt(int _x, int _y) : x(_x), y(_y) {}

    pt operator- (const pt &p) const {
        return pt(x - p.x, y - p.y);
    }

    ll operator* (const pt &p) const {
        return 1LL * x * p.y - 1LL * y * p.x;
    }

    ll operator% (const pt &p) const {
        return 1LL * x * p.x + 1LL * y * p.y;
    }

    bool operator< (const pt &p) const {
        if (x != p.x) return x < p.x;
        return y < p.y;
    }

    bool operator== (const pt &p) const {
        return x == p.x && y == p.y;
    }
};

void print(vector<string> a) {
    for (string s : a) {
        printf("%s\n", s.c_str());
    }
}

struct segtree {
    int N;
    vector<int> t;

    segtree(int n) {
        N = 1;
        while (N < n) N <<= 1;
        t.assign(2 * N, -1);
    }

    void upd(int x, int y) {
        x += N;
        t[x] = y;
        while (x > 1) {
            x >>= 1;
            t[x] = max(t[x * 2], t[x * 2 + 1]);
        }
    }

    int get(int l, int r) {
        int res = -1;
        l += N;
        r += N;
        while (l <= r) {
            if (l & 1) res = max(res, t[l]);
            if (!(r & 1)) res = max(res, t[r]);
            l = (l + 1) >> 1;
            r = (r - 1) >> 1;
        }
        return res;
    }
};

vector<string> solve(vector<pair<int, pair<int, int> > > a, int r) {
    vector<pt> pts;
    for (int i = 0; i < (int)a.size(); i++) {
        if (a[i].first == 1) {
            pts.push_back(pt(a[i].second.first, a[i].second.second));
        }
    }
    sort(pts.begin(), pts.end());
    pts.resize(unique(pts.begin(), pts.end()) - pts.begin());

    vector<pt> p(2);
    vector<vector<pt> > b(2);
    vector<function<bool(const pt&, const pt&)> > cmp(2), cmpe(2);
    p[0] = pt(-r, 0);
    p[1] = pt(+r, 0);


    cmp[0] = [&](const pt &x, const pt &y) {
        return ((x - p[0]) * (y - p[0])) > 0;
    };
    cmp[1] = [&](const pt &x, const pt &y) {
        return ((x - p[1]) * (y - p[1])) < 0;
    };
    for (int i = 0; i < 2; i++) {
        b[i] = pts;
        cmpe[i] = [&](const pt &x, const pt &y) {
            return ((x - p[i]) * (y - p[i])) == 0;
        };
        sort(b[i].begin(), b[i].end(), cmp[i]);
        b[i].resize(unique(b[i].begin(), b[i].end(), cmpe[i]) - b[i].begin());

    }
    int m = pts.size();
    vector<pair<int, int> > c(m);
    for (int i = 0; i < m; i++) {
        c[i].first = lower_bound(b[0].begin(), b[0].end(), pts[i], cmp[0]) - b[0].begin();
        c[i].second = lower_bound(b[1].begin(), b[1].end(), pts[i], cmp[1]) - b[1].begin();
    }

    vector<pair<pair<int, int>, int> > vv;
    for (int i = 0; i < m; i++) {
        vv.push_back({c[i], i});
    }
    sort(vv.begin(), vv.end());
    vector<int> o(m);
    for (int i = 0; i < m; i++) o[vv[i].second] = i;

    segtree t(m);
    vector<char> alive(m);
    auto toggle = [&](int id) {
        if (alive[id]) t.upd(o[id], -1);
        else t.upd(o[id], c[id].second);
        alive[id] ^= 1;
    };
    vector<int> id(1, -1);
    vector<string> ans;
    for (auto o : a) {
        if (o.first == 1) {
            pt cur = pt(o.second.first, o.second.second);
            int cid = lower_bound(pts.begin(), pts.end(), cur) - pts.begin();
            assert(pts[cid] == cur);
            id.push_back(cid);
            toggle(cid);
        }
        if (o.first == 2) {
            int q = o.second.first;
            assert(alive[id[q]]);
            toggle(id[q]);
        }
        if (o.first == 3) {
            int u = id[o.second.first];
            int v = id[o.second.second];
            assert(u != v && alive[u] && alive[v]);
            toggle(u);
            toggle(v);
            pair<int, int> qq = {min(c[u].first, c[v].first), min(c[u].second, c[v].second)};
            int fr = lower_bound(vv.begin(), vv.end(), make_pair(make_pair(qq.first, -1), -1)) - vv.begin();
            bool ok = t.get(fr, m - 1) < qq.second && ((pts[u] - p[0]) % (pts[v] - p[1])) >= 0 && ((pts[u] - p[1]) % (pts[v] - p[0])) >= 0;
            ans.push_back(ok ? "YES" : "NO");
            toggle(u);
            toggle(v);
        }
    }
    return ans;
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif
    int r, n;
    scanf("%d%d", &r, &n);
    vector<pair<int, pair<int, int> > > a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i].first, &a[i].second.first);
        if (a[i].first != 2) scanf("%d", &a[i].second.second);
    }
    print(solve(a, r));
}