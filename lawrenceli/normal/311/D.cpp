#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 1<<17;
const int MOD = 95542721;
const int CYC = 48;

int n, a[MAXN], q;

struct Node {
    int num[CYC];
};

Node tree[2*MAXN];
int lazy[2*MAXN];

Node merge(Node n1, Node n2) {
    Node ret;
    for (int i=0; i<CYC; i++)
        ret.num[i] = (n1.num[i] + n2.num[i]) % MOD;
    return ret;
}

void down(int cur, int lt, int rt) {
    if (lazy[cur]) {
        rotate(tree[cur].num, tree[cur].num+lazy[cur]%CYC, tree[cur].num+CYC);
        if (lt + 1 != rt) {
            lazy[2*cur] += lazy[cur];
            lazy[2*cur+1] += lazy[cur];
        }
        lazy[cur] = 0;
    }
}

void init(int cur, int lt, int rt) {
    if (lt + 1 == rt) {
        tree[cur].num[0] = a[lt];
        for (int i=1; i<CYC; i++) {
            int x = tree[cur].num[i-1];
            tree[cur].num[i] = ll(x)*x%MOD*x%MOD;
        }
    } else {
        int mid = (lt + rt) / 2;
        init(2*cur, lt, mid);
        init(2*cur+1, mid, rt);
        tree[cur] = merge(tree[2*cur], tree[2*cur+1]);
    }
}

int query(int cur, int lt, int rt, int ql, int qr) {
    down(cur, lt, rt);
    if (rt <= ql || lt >= qr) return 0;
    else if (lt >= ql && rt <= qr) return tree[cur].num[0];
    else {
        int mid = (lt + rt) / 2;
        return (query(2*cur, lt, mid, ql, qr)+query(2*cur+1, mid, rt, ql, qr))%MOD;
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
        tree[cur] = merge(tree[2*cur], tree[2*cur+1]);
    }
}

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    init(1, 0, n);
    scanf("%d", &q);
    for (int i=0; i<q; i++) {
        int t, l, r;
        scanf("%d %d %d", &t, &l, &r); l--;
        if (t == 1)
            printf("%d\n", query(1, 0, n, l, r));
        else
            update(1, 0, n, l, r);
    }
    return 0;
}