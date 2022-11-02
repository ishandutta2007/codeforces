#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 100000 + 5;
int n, q;
int a[N], b[N];
const int MAXN = 100000 + 5;
const int MAXNODE = 400000 + 5;
struct zgz {

    LL tmp[MAXN];
    struct node {
        LL sum, maxl, maxr, maxv;
        node() {
            sum = maxl = maxr = maxv = 0;
        }
    }A[MAXNODE];
    inline void push_up(int x) {
        A[x].sum = A[x << 1].sum + A[x << 1 | 1].sum;
        A[x].maxl = max(A[x << 1].maxl, A[x << 1].sum + A[x << 1 | 1].maxl);
        A[x].maxv = max(A[x << 1].maxr + A[x << 1 | 1].maxl, max(A[x << 1].maxv, A[x << 1 | 1].maxv));
        A[x].maxr = max(A[x << 1 | 1].maxr, A[x << 1].maxr + A[x << 1 | 1].sum);
    }
    void init(int x, int l, int r) {
        if (l == r) {
            A[x].sum = tmp[l];
            A[x].maxl = A[x].maxr = A[x].maxv = max(0LL, tmp[l]);
            return;
        }
        int mid = (l + r) >> 1;
        init(x << 1, l, mid);
        init(x << 1 | 1, mid + 1, r);
        push_up(x);
    }
    void update(int x, int l, int r, int q, LL c) {
        if (l == r) {
            if (l == q)
                A[x].sum = A[x].maxl = A[x].maxr = A[x].maxv = c;
            return;
        }
        int mid = (l + r) >> 1;
        if (q <= mid)
            update(x << 1, l, mid, q, c);
        else
            update(x << 1 | 1, mid + 1, r, q, c);
        push_up(x);
    }
    node query(int x, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return A[x];
        }
        int mid = (l + r) >> 1;
        if (qr <= mid)
            return query(x << 1, l, mid, ql, qr);
        if (ql > mid)
            return query(x << 1 | 1, mid + 1, r, ql, qr);
        node left = query(x << 1, l, mid, ql, qr), right = query(x << 1 | 1, mid + 1, r, ql, qr), ret;
        ret.maxv = max(left.maxr + right.maxl, max(left.maxv, right.maxv));
        ret.maxl = max(left.maxl, left.sum + right.maxl);
        ret.maxr = max(right.maxr, left.maxr + right.sum);
        ret.sum = left.sum + right.sum;
        return ret;
    }
}big, small;

int main() {
    //  B-A 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i += 1)
        cin >> a[i];
    for (int i = 1; i <= n; i += 1)
        cin >> b[i];
    for (int i = 1; i <= n; i += 1) {
        big.tmp[i] = b[i] - a[i];
        small.tmp[i] = a[i] - b[i];
    }/*
    for (int i = 1; i <= n; i += 1) {
        cout << b[i] - a[i] << ' ';
    }
    cout << endl;*/

    big.init(1, 1, n);
    small.init(1, 1, n);

    for (int i = 1; i <= q; i += 1) {
        int l, r;
        cin >> l >> r;
        auto BIG = big.query(1, 1, n, l, r);
        auto SMALL = small.query(1, 1, n, l, r);
        //cout << l << ' ' << r << ' ' << SMALL.maxl << endl;
        if (BIG.sum != 0) {
            cout << "-1\n";
            continue;
        }
        if (SMALL.maxl != 0) {
            cout << "-1\n";
            continue;
        }
        cout << max(BIG.maxv, SMALL.maxv) << '\n';
    }

    /*
        sum = 0;
        minl = 0;
        max( -)
    */

}