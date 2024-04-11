#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1<<19;

int n, ar[MAXN];
int tmin[2*MAXN], tcnt[2*MAXN], lazy[2*MAXN];
int up[MAXN], down[MAXN], cup, cdown;

void init(int cur, int lt, int rt) {
    tmin[cur] = lt;
    tcnt[cur] = 1;
    lazy[cur] = 0;
    if (lt + 1 != rt) {
        int mid = (lt + rt) / 2;
        init(2*cur, lt, mid);
        init(2*cur+1, mid, rt);
    }
}

void prop(int cur, int lt, int rt) {
    tmin[cur] += lazy[cur];
    if (lt + 1 != rt) {
        lazy[2*cur] += lazy[cur];
        lazy[2*cur+1] += lazy[cur];
    }
    lazy[cur] = 0;
}

void merge(int cur, int lt, int rt) {
    tmin[cur] = min(tmin[2*cur], tmin[2*cur+1]);
    tcnt[cur] = (tmin[2*cur] == tmin[cur] ? tcnt[2*cur] : 0) + (tmin[2*cur+1] == tmin[cur] ? tcnt[2*cur+1] : 0);
}

void upd(int cur, int lt, int rt, int ql, int qr, int v) {
    prop(cur, lt, rt);
    if (rt <= ql || lt >= qr) return;
    else if (lt >= ql && rt <= qr) {
        lazy[cur] = v;
        prop(cur, lt, rt);
    } else {
        int mid = (lt + rt) / 2;
        upd(2*cur, lt, mid, ql, qr, v);
        upd(2*cur+1, mid, rt, ql, qr, v);
        merge(cur, lt, rt);
    }
}

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n; i++) {
        int r, c;
        cin >> r >> c;
        ar[r-1] = c;
    }

    init(1, 0, n);

    up[0] = down[0] = -1;
    cup = cdown = 1;

    long long ans = 0;
    for (int i=0; i<n; i++) {
        while (cup >= 2 && ar[i] < ar[up[cup-1]]) {
            upd(1, 0, n, up[cup-2]+1, up[cup-1]+1, ar[up[cup-1]]);
            cup--;
        }
        while (cdown >= 2 && ar[i] > ar[down[cdown-1]]) {
            upd(1, 0, n, down[cdown-2]+1, down[cdown-1]+1, -ar[down[cdown-1]]);
            cdown--;
        }

        up[cup++] = down[cdown++] = i;
        upd(1, 0, n, up[cup-2]+1, up[cup-1]+1, -ar[up[cup-1]]);
        upd(1, 0, n, down[cdown-2]+1, down[cdown-1]+1, ar[down[cdown-1]]);
        ans += tcnt[1];
    }

    cout << ans;
}