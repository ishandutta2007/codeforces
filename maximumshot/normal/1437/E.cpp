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
    int n; // [0, n)
    vector<multiset<int>> leaf;
    vector<int> mx;

    RangeTree(int nn) {
        n = nn;
        leaf.resize(n);
        mx.resize(4 * n, -inf);
    }

    void merge(int v) {
        mx[v] = max(mx[v << 1], mx[v << 1 | 1]);
    }

    void upd(int v, int tl, int tr, int pos, int value, int type) {
        if (tl == tr) {
            if (type == +1)
                leaf[tl].insert(value);
            else
                leaf[tl].erase(leaf[tl].lower_bound(value));
            mx[v] = leaf[tl].empty() ? -inf : *(--leaf[tl].end());
        } else {
            int tm = (tl + tr) >> 1;
            if (pos <= tm)
                upd(v << 1, tl, tm, pos, value, type);
            else
                upd(v << 1 | 1, tm + 1, tr, pos, value, type);
            merge(v);
        }
    }

    void upd(int pos, int value, int type) {
        upd(1, 0, n - 1, pos, value, type);
    }

    int query(int v, int tl, int tr, int l, int r) {
        if (l <= tl && tr <= r) {
            return mx[v];
        } else {
            int tm = (tl + tr) >> 1, res = -inf;
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

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1), crd = {-inf}, B(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        crd.push_back(a[i] - i);
    }
    sort(crd.begin(), crd.end());
    crd.erase(unique(crd.begin(), crd.end()), crd.end());
    int sz = (int) crd.size();

    vector<int> pos(n + 1);
    for (int i = 1; i <= n; i++)
        pos[i] = lower_bound(crd.begin(), crd.end(), a[i] - i) - crd.begin();

    for (int x, i = 0; i < k; i++) {
        cin >> x;
        B[x] = 1;
    }

    vector<int> dp(n + 1, -inf);
    dp[0] = 0;
    RangeTree rt(sz);
    rt.upd(0, 0, +1);

    for (int l = 0, i = 1; i <= n; i++) {
//        for (int j = i - 1; j >= 0; j--) {
//            if (j == 0) {
//                dp[i] = max(dp[i], 1);
//                break;
//            }
//            if (a[j] - j <= a[i] - i)
//                dp[i] = max(dp[i], dp[j] + 1);
//            if (B[a[j]])
//                break;
//        }
        {
            int hlp = rt.query(0, pos[i]);
            if (hlp != -inf)
                dp[i] = max(dp[i], hlp + 1);
        }
        rt.upd(pos[i], dp[i], +1);
        if (B[i])
            while (l < i) {
                rt.upd(pos[l], dp[l], -1);
                l++;
            }
    }

    int res = -inf;
    for (int i = n; i >= 1; i--) {
        res = max(res, dp[i]);
        if (B[i])
            break;
    }

    if (res == -inf)
        res = -1;
    else
        res = n - res;

    cout << res << "\n";

    return 0;
}