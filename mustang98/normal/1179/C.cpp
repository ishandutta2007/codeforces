#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1000011, inf = 1000111222;

struct str {
    int tr[max_n * 4];
    int mn[max_n * 4];
    int sum[max_n * 4];
    void add(int cur, int l, int r, int p, int val) {
        if (l == r) {
            tr[cur] += val;
            mn[cur] += val;
            sum[cur] += val;
            return;
        }
        int mid = (l + r) / 2;
        if (p <= mid) add(cur * 2, l, mid, p, val);
        else add(cur * 2 + 1, mid + 1, r, p, val);
        sum[cur] = sum[cur * 2] + sum[cur * 2 + 1];
        mn[cur] = min(mn[cur * 2 + 1], mn[cur * 2] + sum[cur * 2 + 1]);
    }

    int get_min(int cur, int l, int r, int add) {
        if (l == r) {
            return l;
        }
        if (mn[cur] + add >= 0) return -inf;
        int mid = (l + r) / 2;
        if (mn[cur * 2 + 1] + add < 0) {
            return get_min(cur * 2 + 1, mid + 1, r, add);
        } else {
            return get_min(cur * 2, l, mid, add + sum[cur * 2 + 1]);
        }
    }
} t;

int a[max_n];
int b[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    int ml = max_n - 10;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        a[i] = c;
        t.add(1, 0, ml - 1, c, -1);
    }
    for (int i = 0; i < m; ++i) {
        int c;
        cin >> c;
        b[i] = c;
        t.add(1, 0, ml - 1, c, 1);
    }
    int q;
    cin >> q;
    while(q--) {
        int i, j, k;
        cin >> i >> j >> k;
        --j;
        if (i == 1) {
            t.add(1, 0, ml - 1, a[j], 1);
            a[j] = k;
            t.add(1, 0, ml - 1, a[j], -1);
        }

        if (i == 2) {
            t.add(1, 0, ml - 1, b[j], -1);
            b[j] = k;
            t.add(1, 0, ml - 1, b[j], 1);
        }
        int res = t.get_min(1, 0, ml - 1, 0);
        if (res == -inf) {
            cout << -1 << "\n";
        } else {
            cout << res << "\n";
        }
    }

    return 0;
}