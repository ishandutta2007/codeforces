#include <bits/stdc++.h>

using namespace std;

const int maxn = 1<<19;

int n, m, q;
int vx[maxn], vxs, vy[maxn], vys;
int qx[maxn], qy[maxn];

int T[2 * maxn];
bool L[2 * maxn];

void push(int cur, int lt, int rt) {
    if (L[cur]) {
        T[cur] = lt;
        if (lt + 1 != rt) {
            L[2 * cur] = L[2 * cur + 1] = 1;
        }
        L[cur] = 0;
    }
}

void upd(int cur, int lt, int rt, int ql, int qr) {
    push(cur, lt, rt);
    if (rt <= ql || lt >= qr) return;
    else if (lt >= ql && rt <= qr) {
        L[cur] = 1;
        push(cur, lt, rt);
    } else {
        int mid = (lt + rt) / 2;
        upd(2 * cur, lt, mid, ql, qr);
        upd(2 * cur + 1, mid, rt, ql, qr);
        T[cur] = min(T[2 * cur], T[2 * cur + 1]);
    }
}

void rem(int cur, int lt, int rt, int p) {
    if (lt + 1 == rt) T[cur] = vys;
    else {
        int mid = (lt + rt) / 2;
        push(2 * cur, lt, mid);
        push(2 * cur + 1, mid, rt);
        if (p < mid) rem(2 * cur, lt, mid, p);
        else rem(2 * cur + 1, mid, rt, p);
        T[cur] = min(T[2 * cur], T[2 * cur + 1]);
    }
}

int qry(int cur, int lt, int rt, int ql, int qr) {
    push(cur, lt, rt);
    if (rt <= ql || lt >= qr) return vys;
    else if (lt >= ql && rt <= qr) return T[cur];
    else {
        int mid = (lt + rt) / 2;
        int res = qry(2 * cur, lt, mid, ql, qr);
        if (res < vys) return res;
        return qry(2 * cur + 1, mid, rt, ql, qr);
    }
}

vector<int> qv[maxn];

int main() {
    scanf("%d %d", &n, &q);
    int ans = 2 * n - 2;

    vx[vxs++] = vy[vys++] = 1;
    vx[vxs++] = vy[vys++] = n;

    for (int i = 0; i < q; i++) {
        int r, c;
        scanf("%d %d", &r, &c);
        qx[i] = r, qy[i] = c;
        vx[vxs++] = r, vy[vys++] = c;
        if (r > 1) vx[vxs++] = r - 1;
        if (r < n) vx[vxs++] = r + 1;
        if (c > 1) vy[vys++] = c - 1;
        if (c < n) vy[vys++] = c + 1;
    }

    sort(vx, vx + vxs); vxs = unique(vx, vx + vxs) - vx;
    sort(vy, vy + vys); vys = unique(vy, vy + vys) - vy;

    for (int i = 0; i < q; i++) {
        qx[i] = lower_bound(vx, vx + vxs, qx[i]) - vx;
        qy[i] = lower_bound(vy, vy + vys, qy[i]) - vy;
        qv[qx[i]].push_back(qy[i]);
    }

    for (int i = 0; i < 2 * maxn; i++) T[i] = vys;
    upd(1, 0, vys, 0, 1);
    for (int i = 0; i < vxs; i++) {
        sort(qv[i].begin(), qv[i].end());
        for (int j : qv[i]) {
            rem(1, 0, vys, j);
        }
        qv[i].push_back(vys);

        int last = 0;
        for (int j : qv[i]) {
            if (last == j) {
                last = j + 1;
                continue;
            }
            int r = qry(1, 0, vys, last, j);
            if (r < vys) upd(1, 0, vys, r, j);
            last = j + 1;
            //cout << j << ' ' << r << endl;
        }

        //for (int j = 0; j < vys; j++) cout << qry(1, 0, vys, j, j + 1) << ' ';
        //cout << endl;
    }

    if (qry(1, 0, vys, vys - 1, vys) == vys - 1) printf("%d\n", ans);
    else printf("-1\n");
}