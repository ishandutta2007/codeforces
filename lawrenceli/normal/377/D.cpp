#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>
#include <vector>
#include <queue>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> pii;

const int MAXN = 1<<17;
const int MAXV = 1<<19;

struct data {
    int l, v, r, id;
    data() {}
};

int n, m;
data arr[MAXN];

bool cmp(data d1, data d2) {
    return d1.v < d2.v;
}

struct ccmp {
    bool operator()(const data& d1, const data& d2) const {
        return d1.r > d2.r;
    }
};

priority_queue<data, vector<data>, ccmp> pq;

pii tree[2*MAXV];
int lazy[2*MAXV];

void down(int cur, int lt, int rt) {
    tree[cur].fi += lazy[cur];
    if (lt + 1 != rt) {
        lazy[2*cur] += lazy[cur];
        lazy[2*cur+1] += lazy[cur];
    }
    lazy[cur] = 0;
}

void init(int cur, int lt, int rt) {
    if (lt + 1 == rt) tree[cur] = pii(0, lt);
    else {
        int mid = (lt + rt) / 2;
        init(2*cur, lt, mid);
        init(2*cur+1, mid, rt);
        tree[cur] = pii(0, tree[2*cur].se);
    }
}

pii query(int cur, int lt, int rt, int ql, int qr) {
    down(cur, lt, rt);
    if (rt <= ql || lt >= qr) return pii(0, 0);
    else if (lt >= ql && rt <= qr) return tree[cur];
    else {
        int mid = (lt + rt) / 2;
        pii p1 = query(2*cur, lt, mid, ql, qr);
        pii p2 = query(2*cur+1, mid, rt, ql, qr);
        if (p1.fi > p2.fi) return p1;
        else return p2;
    }
}

void update(int cur, int lt, int rt, int ql, int qr, int v) {
    down(cur, lt, rt);
    if (rt <= ql || lt >= qr) return;
    else if (lt >= ql && rt <= qr) {
        lazy[cur] += v;
        down(cur, lt, rt);
    } else {
        int mid = (lt + rt) / 2;
        update(2*cur, lt, mid, ql, qr, v);
        update(2*cur+1, mid, rt, ql, qr, v);
        if (tree[2*cur].fi > tree[2*cur+1].fi) tree[cur] = tree[2*cur];
        else tree[cur] = tree[2*cur+1];
    }
}

int main() {
    ios :: sync_with_stdio(false);

    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }

    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i].l >> arr[i].v >> arr[i].r;

    for (int i=0; i<n; i++) {
        arr[i].id = i;
        m = max(m, arr[i].r+1);
    }

    sort(arr, arr + n, cmp);
    init(1, 0, m);

    int ans = 0;
    pii pans;

    for (int i=0; i<n; i++) {
        while (!pq.empty() && pq.top().r < arr[i].v) {
            update(1, 0, m, pq.top().l, pq.top().v+1, -1);
            pq.pop();
        }

        pq.push(arr[i]);
        update(1, 0, m, arr[i].l, arr[i].v+1, 1);

        pii p = query(1, 0, m, 0, arr[i].v+1);
        if (p.fi > ans) {
            ans = p.fi, pans = pii(p.se, arr[i].v);
        }
    }

    cout << ans << endl;
    for (int i=0; i<n; i++) {
        if (arr[i].v >= pans.fi && arr[i].l <= pans.fi && arr[i].v <= pans.se && arr[i].r >= pans.se)
            cout << arr[i].id + 1 << ' ';
    }
    return 0;
}