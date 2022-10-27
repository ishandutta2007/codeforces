#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int64_t n;
int m;
int64_t a[nax];
int nq;


struct node {
    int64_t x;
    node(){}
};
node operator +(const node &a, const node &b) {
    node res;
    res.x = max(a.x, b.x);
    return res;
}
node sg[nax << 2];

void build(int v, int l, int r) {
    if (l == r) {
        sg[v].x = a[l];
    } else {
        int mid = l + r >> 1;
        build(v << 1, l, mid);
        build(v << 1 | 1, mid + 1, r);
        sg[v] = sg[v << 1] + sg[v << 1 | 1];
    }
}

node query(int v, int x, int y, int l, int r) {
    if (l == x && r == y) {
        return sg[v];
    }
    int mid = x + y >> 1;
    if (r <= mid) return query(v << 1, x, mid, l, r);
    if (l > mid) return query(v << 1 | 1, mid + 1, y, l, r);
    return query(v << 1, x, mid, l, mid) +
    query(v << 1 | 1, mid + 1, y, mid + 1, r);
}


int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m;

    for (int i = 1 ; i <= m ; ++ i) {
        cin >> a[i];
    }

    build(1, 1, m);

    cin >> nq;
    while (nq --) {
        auto solve = [&]()->bool {
            int64_t xs, ys, xt, yt, k;
            cin >> ys >> xs >> yt >> xt >> k;

            if (xs == xt) {
                if (abs(ys - yt) % k == 0) return true;
                return false;
            }
            int64_t up = n - ys;
            ys += k * (up / k);


            int64_t l = min(xs, xt), r = max(xs, xt);
            int64_t max_block = l > r ? 0 : query(1, 1, m, l, r).x;
            if (max_block >= ys) return false;
            if ((xs - xt) % k) return false;
            if ((ys - yt) % k) return false;
            return true;
        };
        cout << (solve() ? "YES" : "NO") << '\n';
    }

}
/*
    Eduroundd
*/