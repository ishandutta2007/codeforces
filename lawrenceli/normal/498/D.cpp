#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1<<17;
const int MOD = 60;

int n, ar[MAXN], q;
int tree[2*MAXN][MOD];

void init(int cur, int lt, int rt) {
    if (lt + 1 == rt) {
        for (int i=0; i<MOD; i++)
            if (i%ar[lt] == 0) tree[cur][i] = 2;
            else tree[cur][i] = 1;
    } else {
        int mid = (lt + rt) / 2;
        init(2*cur, lt, mid);
        init(2*cur+1, mid, rt);
        for (int i=0; i<MOD; i++)
            tree[cur][i] = tree[2*cur][i]+tree[2*cur+1][(i+tree[2*cur][i])%MOD];
    }
}

int query(int cur, int lt, int rt, int ql, int qr, int st=0) {
    if (rt <= ql || lt >= qr) return 0;
    else if (lt >= ql && rt <= qr) return tree[cur][st];
    else {
        int mid = (lt + rt) / 2;
        int res = query(2*cur, lt, mid, ql, qr, st);
        return res+query(2*cur+1, mid, rt, ql, qr, (st+res)%MOD);
    }
}

void update(int cur, int lt, int rt, int p, int v) {
    if (lt + 1 == rt) {
        for (int i=0; i<MOD; i++)
            if (i%v == 0) tree[cur][i] = 2;
            else tree[cur][i] = 1;
    } else {
        int mid = (lt + rt) / 2;
        if (p < mid) update(2*cur, lt, mid, p, v);
        else update(2*cur+1, mid, rt, p, v);
        for (int i=0; i<MOD; i++)
            tree[cur][i] = tree[2*cur][i]+tree[2*cur+1][(i+tree[2*cur][i])%MOD];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }

    cin >> n;
    for (int i=0; i<n; i++) cin >> ar[i];
    init(1, 0, n);

    cin >> q;
    for (int i=0; i<q; i++) {
        char c;
        int x, y;
        cin >> c >> x >> y;
        if (c == 'A') {
            x--, y--;
            cout << query(1, 0, n, x, y) << '\n';
        } else {
            x--;
            update(1, 0, n, x, y);
        }
    }
    return 0;
}