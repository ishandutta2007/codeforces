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

struct RMQ {
    vector<int> a; // [0, n)
    int n, LOG;
    vector<int> _log;
    vector<vector<pii>> rmq;

    RMQ(const vector<int>& aa) {
        a = aa;
        n = (int) a.size();
        LOG = 0;
        while ((1 << LOG) <= n) LOG++;
        _log.resize(n + 1);
        for (int i = 2; i <= n; i++) {
            _log[i] = _log[i - 1] + 1;
            if ((1 << _log[i]) > i) _log[i]--;
        }
        rmq.resize(LOG, vector<pii>(n));
        for (int i = 0; i < n; i++) {
            rmq[0][i] = {a[i], i};
        }
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                rmq[j][i] = min(rmq[j - 1][i], rmq[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    pii get_min(int l, int r) const {
        int lg = _log[r - l + 1];
        return min(rmq[lg][l], rmq[lg][r - (1 << lg) + 1]);
    }
};


struct DSU {
    int n; // [1, n]
    vector<int> p, sz;

    DSU(int n): n(n) {
        p.resize(n + 1);
        sz.resize(n + 1);
        for (int i = 1; i <= n; i++)
            p[i] = i, sz[i] = 1;
    }

    int find(int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    }

    void merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        sz[x] += sz[y];
        p[y] = x;
    }
};

void solve() {
    int n;
    cin >> n;

    vector<int> p(n + 1), pp(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        pp[i] = -p[i];
    }

    RMQ rmq(pp);
    vector<int> have(n + 1);
    for (int i = 1; i <= n; i++) {
        int bl = 0;
        int br = i;
        int bm;
        while (br - bl > 1) {
            bm = (bl + br) >> 1;
            if (-rmq.get_min(bm, i).first <= p[i])
                br = bm;
            else
                bl = bm;
        }
        have[i] = i - br + 1;
    }

    vector<int> should(n + 1);
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; i++)
        pos[p[i]] = i;

    DSU dsu(n);
    set<pii> q;
    for (int x = 1; x <= n; x++) {
        int mx = 1 + (q.empty() ? 0 : (--q.end())->first);
        should[x] = mx;

        int i = pos[x];
        if (i < n)
            q.insert({1, i});
        if (i > 1 && p[i - 1] <= x) {
            int p1 = dsu.find(i - 1);
            int p2 = dsu.find(i);
            q.erase({dsu.sz[p1], p1});
            q.erase({dsu.sz[p2], p2});
            dsu.merge(p1, p2);
            p1 = dsu.find(i);
            if (i < n)
                q.insert({dsu.sz[p1], p1});
        }
        if (i < n && p[i + 1] <= x) {
            int p1 = dsu.find(i + 1);
            int hlp = dsu.sz[p1];
            int p2 = dsu.find(i);
            q.erase({dsu.sz[p1], p1});
            q.erase({dsu.sz[p2], p2});
            dsu.merge(p1, p2);
            p1 = dsu.find(i);
            if (i + hlp < n)
                q.insert({dsu.sz[p1], p1});
        }
    }
//    cout << "should : "; for (int x = 1; x <= n; x++) cout << should[x] << " "; cout << "\n";
//    cout << "have : "; for (int x = 1; x <= n; x++) cout << have[x] << " "; cout << "\n";
    for (int i = 1; i <= n; i++) {
        if (should[p[i]] != have[i]) {
            cout << "No\n";
            return;
        }

    }
    cout << "Yes\n";
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt;
    cin >> tt;

    for (int ti = 1; ti <= tt; ti++) {
        solve();
    }

    return 0;
}