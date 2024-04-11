#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 300111, inf = 1000111222;

int m[max_n];

int get_bad(int a) {
    return (a - 1) / 2;
}

struct segment_tree {
    int tr[4 * max_n];
    void build(int cur, int l, int r) {
        if (l == r) {
            tr[cur] = m[l];
            return;
        }
        int mid = (l + r ) / 2;
        build(cur * 2, l, mid);
        build(cur * 2 + 1,mid + 1, r);
        tr[cur] = min(tr[cur * 2], tr[cur * 2 + 1]);
    }
    int get_min(int cur, int l, int r, int ql, int qr) {
        if (l == ql && r == qr) {
            return tr[cur];
        }
        if (ql > r || qr < l) {
            return inf;
        }
        int mid = (l + r) / 2;
        return min(get_min(cur * 2, l, mid, ql, min(mid, qr)),
                   get_min(cur * 2 + 1, mid + 1, r, max(mid + 1, ql), qr));
    }
} tr;
int pos[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    int mx = -1, mn = inf;
    for (int i = 0; i < n; ++i) {
        scanf("%d", m + i);
        mx = max(mx, m[i]);
        mn = min(mn, m[i]);
    }
    if (mn > get_bad(mx)) {
        for (int i = 0; i < n; ++i) {
            cout << -1 << ' ';
        }
        return 0;
    }
    for (int i = 0; i < n * 3; ++i) {
        m[i] = m[i % n];
    }
    tr.build(1, 0, 3 * n - 1);
    pos[3 * n - 1] = inf;

    for (int i = 3 * n - 2; i >= 0; --i) {
        int cur = m[i];
        int bad = get_bad(cur);
        if (tr.get_min(1, 0, 3 * n - 1, i + 1, 3 * n - 1) > bad) {
            pos[i] = inf;
            continue;
        }
        if (m[i + 1] <= bad) {
            pos[i] = i + 1;
            continue;
        }
        int l = i + 1;
        int r = 3 * n - 1;
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (tr.get_min(1, 0, 3 * n - 1, i + 1, mid) > bad) {
                l = mid;
            } else {
                r = mid;
            }
        }
        pos[i] = r;
    }
    mn = inf;
    vector<int> ans;
    for (int i = 3 * n - 1; i >= 0; --i) {
        mn = min(mn, pos[i]);
        if (i < n) {
            //cout << mn - i << " ";
            ans.PB(mn - i);
        }
    }
    reverse(ans.begin(), ans.end());
    for (int a : ans) {
        printf("%d ", a);
    }


    return 0;
}