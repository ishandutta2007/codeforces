#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1<<17;

int n, m, ar[MAXN];
ll tree[2*MAXN];
int ma[2*MAXN];

void init(int cur, int lt, int rt) {
    if (lt + 1 == rt) {
        tree[cur] = ar[lt];
        ma[cur] = lt;
    } else {
        int mid = (lt + rt) / 2;
        init(2*cur, lt, mid);
        init(2*cur+1, mid, rt);
        tree[cur] = tree[2*cur]+tree[2*cur+1];
        int x = ma[2*cur], y = ma[2*cur+1];
        if (ar[x] > ar[y]) ma[cur] = x;
        else ma[cur] = y;
    }
}

ll query(int cur, int lt, int rt, int ql, int qr) {
    if (rt <= ql || lt >= qr) return 0;
    if (lt >= ql && rt <= qr) return tree[cur];
    else {
        int mid = (lt + rt) / 2;
        return query(2*cur, lt, mid, ql, qr)+query(2*cur+1, mid, rt, ql, qr);
    }
}

int query2(int cur, int lt, int rt, int ql, int qr) {
    if (rt <= ql || lt >= qr) return -1;
    if (lt >= ql && rt <= qr) return ma[cur];
    else {
        int mid = (lt + rt) / 2;
        int x = query2(2*cur, lt, mid, ql, qr);
        int y = query2(2*cur+1, mid, rt, ql, qr);
        if (ar[x] > ar[y]) return x;
        else return y;
    }
}

void update(int cur, int lt, int rt, int p) {
    if (lt + 1 == rt) tree[cur] = ar[lt];
    else {
        int mid = (lt + rt) / 2;
        if (p < mid) update(2*cur, lt, mid, p);
        else update(2*cur+1, mid, rt, p);
        tree[cur] = tree[2*cur] + tree[2*cur+1];
        int x = ma[2*cur], y = ma[2*cur+1];
        if (ar[x] > ar[y]) ma[cur] = x;
        else ma[cur] = y;
    }
}

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++) scanf("%d", &ar[i]);
    init(1, 0, n);

    for (int i=0; i<m; i++) {
        int type; scanf("%d", &type);
        if (type == 1) {
            int l, r;
            scanf("%d %d", &l, &r);
            l--;
            printf("%I64d\n", query(1, 0, n, l, r));
        } else if (type == 2) {
            int l, r, x;
            scanf("%d %d %d", &l, &r, &x);
            l--;
            while (1) {
                int k = query2(1, 0, n, l, r);
                if (k == -1 || ar[k] < x) break;
                ar[k] %= x;
                update(1, 0, n, k);
            }
        } else {
            int k, x;
            scanf("%d %d", &k, &x);
            k--;
            ar[k] = x;
            update(1, 0, n, k);
        }
    }
    return 0;
}