#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const int mod = inf + 7;

inline int _sum(int a, int b) {
    return a + b < mod ? a + b : a + b - mod;
}

struct RangeTree {
    int n; // [0, n)
    vector<int> mn, cn;
    RangeTree(int nn) {
        n = nn;
        mn.resize(2 * n, inf + 10);
        cn.resize(2 * n, 0);
    }
    void merge(int v) {
        if (mn[v << 1] < mn[v << 1 | 1]) {
            mn[v] = mn[v << 1];
            cn[v] = cn[v << 1];
        } else if (mn[v << 1] > mn[v << 1 | 1]) {
            mn[v] = mn[v << 1 | 1];
            cn[v] = cn[v << 1 | 1];
        } else {
            mn[v] = mn[v << 1 | 1];
            cn[v] = _sum(cn[v << 1], cn[v << 1 | 1]);
        }
    }
    void update(int pos, int val, int cnt) {
        pos += n;
        if (mn[pos] < val) return;
        if (mn[pos] > val) {
            mn[pos] = val;
            cn[pos] = cnt;
        } else { // mn[pos] == val
            cn[pos] = _sum(cn[pos], cnt);
        }
        for (pos >>= 1; pos > 0; pos >>= 1) {
            merge(pos);
        }
    }
    pii query(int l, int r) { // [l, r)
        int res = inf + 10;
        int cnt = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                if (res > mn[l]) {
                    res = mn[l];
                    cnt = cn[l];
                } else if (res == mn[l]) {
                    cnt = _sum(cnt, cn[l]);
                }
                l++;
            }
            if (r & 1) {
                r--;
                if (res > mn[r]) {
                    res = mn[r];
                    cnt = cn[r];
                } else if (res == mn[r]) {
                    cnt = _sum(cnt, cn[r]);
                }
            }
        }
        return make_pair(res, cnt);
    }
};

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n;

    cin >> n;

    vector<pii> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end());

    vector<int> dp(n, inf + 10), cn(n, 0);

    RangeTree rt(n);

    for (int i = 0; i < n; i++) {
        int in, out, j;
        tie(out, in) = a[i];
        {
            int bl = 0;
            int br = i;
            int bm;
            while (br - bl > 1) {
                bm = (bl + br) >> 1;
                if (a[bm].first <= in) {
                    bl = bm;
                } else {
                    br = bm;
                }
            }
            j = bl;
        }
        dp[i] = in;
        cn[i] = 1;
        if (i > 0 && a[0].first <= in) {
            // dp[q] + in - a[q].second --> min
            int min_val, cnt;
            tie(min_val, cnt) = rt.query(0, j + 1);
            min_val += in;
            if (dp[i] > min_val) {
                dp[i] = min_val;
                cn[i] = cnt;
            } else if (dp[i] == min_val) {
                cn[i] = _sum(cn[i], cnt);
            }
        }
        rt.update(i, dp[i] - a[i].first, cn[i]);
    }

    int res = inf + 10;
    int cnt = 0;

    for (int max_suff = -inf - 10, i = n - 1; i >= 0; i--) {
        if (a[i].first > max_suff) {
            if (res > dp[i]) {
                res = dp[i];
                cnt = cn[i];
            } else if (res == dp[i]) {
                cnt = _sum(cnt, cn[i]);
            }
        }
        max_suff = max(max_suff, a[i].second);
    }

    cout << cnt << "\n";

    return 0;
}