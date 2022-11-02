#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1<<20;

int n, q, qx[MAXN], qy[MAXN], qd[MAXN];
int nums[MAXN], cnt;
int t[2][2*MAXN], l[2][2*MAXN];

void push(int k, int cur, int lt, int rt) {
    t[k][cur] = max(t[k][cur], l[k][cur]);
    if (lt + 1 != rt) {
        l[k][2*cur] = max(l[k][2*cur], l[k][cur]);
        l[k][2*cur+1] = max(l[k][2*cur+1], l[k][cur]);
    }
    l[k][cur] = 0;
}

void upd(int k, int cur, int lt, int rt, int ql, int qr, int v) {
    push(k, cur, lt, rt);
    if (rt <= ql || lt >= qr) return;
    else if (lt >= ql && rt <= qr) {
        l[k][cur] = v;
        push(k, cur, lt, rt);
    } else {
        int mid = (lt + rt) / 2;
        upd(k, 2*cur, lt, mid, ql, qr, v);
        upd(k, 2*cur+1, mid, rt, ql, qr, v);
    }
}

int qry(int k, int cur, int lt, int rt, int p) {
    push(k, cur, lt, rt);
    if (lt + 1 == rt) return t[k][cur];
    else {
        int mid = (lt + rt) / 2;
        if (p < mid) return qry(k, 2*cur, lt, mid, p);
        else return qry(k, 2*cur+1, mid, rt, p);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> q;
    for (int i=0; i<q; i++) {
        char c;
        cin >> qx[i] >> qy[i] >> c;
        qd[i] = c == 'U';
        nums[cnt++] = qx[i], nums[cnt++] = qy[i];
    }
    sort(nums, nums+cnt);
    cnt = unique(nums, nums+cnt)-nums;

    for (int i=0; i<q; i++) {
        int x = qx[i], y = qy[i], d = qd[i];
        if (!d) swap(x, y);
        int cx = lower_bound(nums, nums+cnt, x)-nums;
        int cy = lower_bound(nums, nums+cnt, y)-nums;
        int a = qry(d, 1, 0, cnt, cx);
        cout << y-a << '\n';
        int ca = lower_bound(nums, nums+cnt, a)-nums;
        upd(d, 1, 0, cnt, cx, cx+1, y);
        upd(!d, 1, 0, cnt, ca, cy+1, x);
    }
}