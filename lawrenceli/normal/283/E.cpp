#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>
#include <vector>
#include <cstring>

using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1<<17;

int n, k, s[MAXN], w[MAXN];
pii ar[MAXN];

bool cmp(pii p1, pii p2) { return p1.se > p2.se; }

int tree[2*MAXN], lazy[2*MAXN];

void init(int cur, int lt, int rt) {
    tree[cur] = rt - lt;
    if (lt + 1 != rt) {
        int mid = (lt + rt) / 2;
        init(2*cur, lt, mid);
        init(2*cur+1, mid, rt);
    }
}

void down(int cur, int lt, int rt) {
    if (lazy[cur]) {
        tree[cur] = rt - lt - tree[cur];
        lazy[cur] = 0;
        if (lt + 1 != rt) {
            lazy[2*cur] ^= 1;
            lazy[2*cur+1] ^= 1;
        }
    }
}

void update(int cur, int lt, int rt, int ql, int qr) {
    down(cur, lt, rt);
    if (rt <= ql || lt >= qr) return;
    else if (lt >= ql && rt <= qr) {
        lazy[cur] = 1;
        down(cur, lt, rt);
    } else {
        int mid = (lt + rt) / 2;
        update(2*cur, lt, mid, ql, qr);
        update(2*cur+1, mid, rt, ql, qr);
        tree[cur] = tree[2*cur] + tree[2*cur+1];
    }
}

int query(int cur, int lt, int rt, int ql, int qr) {
    down(cur, lt, rt);
    if (rt <= ql || lt >= qr) return 0;
    else if (lt >= ql && rt <= qr) return tree[cur];
    else {
        int mid = (lt + rt) / 2;
        return query(2*cur, lt, mid, ql, qr) + query(2*cur+1, mid, rt, ql, qr);
    }
}

int main() {
    ios :: sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i=0; i<n; i++)
        cin >> s[i];
    sort(s, s+n);
    for (int i=0; i<k; i++) {
        cin >> ar[i].fi >> ar[i].se;
        ar[i].fi = lower_bound(s, s+n, ar[i].fi)-s;
        ar[i].se = upper_bound(s, s+n, ar[i].se)-s;
    }

    sort(ar, ar+k, cmp);
    init(1, 0, n);

    int p = 0;
    for (int i=n-1; i>=0; i--) {
        for (; p<k && ar[p].se == i+1; p++)
            update(1, 0, n, ar[p].fi, ar[p].se);
        w[i] += query(1, 0, n, 0, i);
    }

    sort(ar, ar+k);
    memset(tree, 0, sizeof(tree));
    memset(lazy, 0, sizeof(lazy));

    p = 0;
    for (int i=0; i<n; i++) {
        for (; p<k && ar[p].fi == i; p++)
            update(1, 0, n, ar[p].fi, ar[p].se);
        w[i] += query(1, 0, n, i+1, n);
    }

    ll ans = ll(n)*(n-1)*(n-2)/6;
    for (int i=0; i<n; i++)
        ans -= ll(w[i])*(w[i]-1)/2;
    cout << ans << '\n';
    return 0;
}