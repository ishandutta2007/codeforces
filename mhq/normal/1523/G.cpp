#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxN = 1e5 + 10;
int l[maxN], r[maxN];
struct Fenwick {
    vector<int> f;
    vector<int> data;
    int n;

    Fenwick(int _n) {
        n = _n;
        f.resize(n + 1, 1e9);
    }

    Fenwick() {
        n = 0;
    }

    void addPt(int x) {
        data.emplace_back(x);
    }

    void start() {
        sort(data.begin(), data.end());
        data.erase(unique(data.begin(), data.end()), data.end());
        n = data.size();
        f.resize(n + 1, 1e9);
    }

    void updPriv(int pos, int v) {
        while (pos <= n) {
            f[pos] = min(f[pos], v);
            pos = (pos | (pos - 1)) + 1;
        }
    }

    int getPriv(int r) {
        int ans = 1e9;
        while (r > 0) {
            ans = min(ans, f[r]);
            r &= (r - 1);
        }
        return ans;
    }

    void upd(int T, int by) {
        int pos = lower_bound(data.begin(), data.end(), T) - data.begin();
        assert(0 <= pos && pos < data.size() && data[pos] == T);
        updPriv(pos + 1, by);
    }

    int get(int Tr) {
        int r = lower_bound(data.begin(), data.end(), Tr) - data.begin();
        return getPriv(r);
    }
};

struct Fenwick2D {
    //  ,       - 
    //   ,     lower_bound
    vector<int> cordFirst;
    vector<Fenwick> t;
    int n;
    Fenwick2D(const vector < int >& cord) {
        cordFirst = cord;
        sort(cordFirst.begin(), cordFirst.end());
        cordFirst.erase(unique(cordFirst.begin(), cordFirst.end()), cordFirst.end());
        n = cordFirst.size();
        t.resize(n + 1);
    }

    void build() {
        for (int i = 1; i <= n; i++) {
            t[i].start();
        }
    }

    int getCord(int x) {
        auto it = lower_bound(cordFirst.begin(), cordFirst.end(), x) - cordFirst.begin();
        return it + 1;
    }

    void addPoint(int x, int y) {
        x = getCord(x);
        while (x <= n) {
            t[x].addPt(y);
            x = (x | (x - 1)) + 1;
        }
    }

    int querySimple(int r, int r2) {
        int ans = 1e9;
        while (r > 0) {
            ans = min(ans, t[r].get(r2));
            r &= (r - 1);
        }
        return ans;
    }

    int query(int r1, int r2) {
        r1 = getCord(r1) - 1;
        return querySimple(r1, r2);
    }

    void add(int x, int y, int w) {
        x = getCord(x);
        while (x <= n) {
            t[x].upd(y, w);
            x = (x | (x - 1)) + 1;
        }
    }

};
vector<int> by[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> l[i] >> r[i];
    }
    vector<int> cord(n + 3);
    iota(cord.begin(), cord.end(), -n - 1);
    Fenwick2D ft(cord);
    for (int i = 1; i <= m; i++) {
        ft.addPoint(-l[i], r[i]);
    }
    ft.build();
    //
    for (int i = 1; i <= m; i++) {
        by[r[i] - l[i] + 1].emplace_back(i);
    }
    function<int(int,int,int)> solve = [&](int le, int ri, int x) {
//        cout << le << " " << ri << " " << x << endl;
        if (ri - le + 1 < x) return 0;
        int ind = ft.query(-le + 1, ri + 1);
        if (ind > 1e8) return 0;
        return r[ind] - l[ind] + 1 + solve(le, l[ind] - 1, x) + solve(r[ind] + 1, ri, x);
    };
    vector<int> ans(n + 1);
    for (int x = n; x >= 1; x--) {
        for (auto& it : by[x]) {
            ft.add(-l[it], r[it], it);
        }
        ans[x] = solve(1, n, x);
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}