#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cassert>

using namespace std;

const int maxn = 1<<18;
const int maxb = 32;

int n, q, ar[maxn];

struct data {
    int a[maxb];
    int sze;
    data() {
        memset(a, 0, sizeof(a));
        sze = 0;
    }
} tree[2*maxn];

int lazy[2*maxn];

int a[2 * maxb];

data merge(data d1, data d2, bool b = 0) {
    for (int i = 0; i < d1.sze; i++) a[i] = d1.a[i];
    for (int i = 0; i < d2.sze; i++) a[i + d1.sze] = d2.a[i];
    int sze = d1.sze + d2.sze;

    if (sze < maxb && !b) {
        data d = data();
        d.sze = sze;
        for (int i = 0; i < sze; i++) d.a[i] = a[i];
        return d;
    }

    int num = 0;
    for (int i = 0; i <= 30; i++) {
        for (int j = num; j < sze; j++)
            if (a[j] & 1<<i) {
                for (int k = j+1; k < sze; k++)
                    if (a[k] & 1<<i) a[k] ^= a[j];

                if (j != num)
                    a[j] ^= a[num], a[num] ^= a[j], a[j] ^= a[num];

                num++;
                break;
            }
    }

    if (num < sze) {
        assert(a[num] == 0);
        num++;
    }

    data d = data();
    d.sze = num;
    for (int i = 0; i < num; i++) d.a[i] = a[i];
    return d;
}

void init(int cur, int lt, int rt) {
    if (lt + 1 == rt) {
        tree[cur].a[0] = ar[lt] ^ 1<<30;
        tree[cur].sze++;
    } else {
        int mid = (lt + rt) / 2;
        init(2*cur, lt, mid);
        init(2*cur+1, mid, rt);
        tree[cur] = merge(tree[2*cur], tree[2*cur+1]);
        /*
        cout << lt << ' ' << rt << ": ";
        for (int i = 0; i < tree[cur].sze; i++) cout << tree[cur].a[i] << ' ';
        cout << endl;
        */
    }
}

void push(int cur, int lt, int rt) {
    if (lazy[cur]) {
        for (int i = 0; i < tree[cur].sze; i++)
            if (tree[cur].a[i] & 1<<30)
                tree[cur].a[i] ^= lazy[cur];

        if (lt + 1 != rt) {
            lazy[2*cur] ^= lazy[cur];
            lazy[2*cur+1] ^= lazy[cur];
        }
        lazy[cur] = 0;
    }
}

void upd(int cur, int lt, int rt, int ql, int qr, int k) {
    push(cur, lt, rt);
    if (rt <= ql || lt >= qr) return;
    else if (lt >= ql && rt <= qr) {
        lazy[cur] = k;
        push(cur, lt, rt);
    } else {
        int mid = (lt + rt) / 2;
        upd(2*cur, lt, mid, ql, qr, k);
        upd(2*cur+1, mid, rt, ql, qr, k);
        tree[cur] = merge(tree[2*cur], tree[2*cur+1]);
    }
}

data qry(int cur, int lt, int rt, int ql, int qr) {
    push(cur, lt, rt);
    if (rt <= ql || lt >= qr) return data();
    else if (lt >= ql && rt <= qr) return tree[cur];
    else {
        int mid = (lt + rt) / 2;
        return merge(qry(2*cur, lt, mid, ql, qr), qry(2*cur+1, mid, rt, ql, qr));
    }
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> ar[i];

    init(1, 0, n);

    for (int i = 0; i < q; i++) {
        int t; cin >> t;
        if (t == 1) {
            int l, r, k;
            cin >> l >> r >> k;
            l--;
            upd(1, 0, n, l, r, k);
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            data d = qry(1, 0, n, l, r);
            d = merge(d, data(), 1);
            int b = 0;
            for (int i = 0; i < d.sze; i++)
                if (d.a[i] == 0 || d.a[i] == 1<<30) b++;
            
            cout << (1 << (d.sze - b)) << '\n';
        }
    }
}