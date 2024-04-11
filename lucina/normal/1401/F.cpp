#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n, nq;

int64_t sg[nax * 4];
bool rev[25];
bool sw[25];


void build (int v, int l, int r, int * a) {
    if (l == r) {
        sg[v] = a[l];
    } else {
        int mid = l + r >> 1;
        build(v * 2, l, mid, a);
        build(v * 2  + 1, mid + 1, r, a);
        sg[v] = sg[v * 2] + sg[v * 2 + 1];
    }
}

void update (int v, int l, int r, int pos, int val, bool cur_rever = false, int dep = 1) {
    cur_rever ^= rev[dep];
    bool cur_sw = sw[dep];
    if (l == r) {
        sg[v] = val;
    } else {
        int mid = l + r >> 1;
        int to_xor = cur_sw ^ cur_rever;
        if (pos <= mid) {
            int nxt_node = v << 1 ^ to_xor;
            update(nxt_node, l, mid, pos, val, cur_rever, dep + 1);
        } else {
            int nxt_node = (v << 1 | 1) ^ to_xor;
            update(nxt_node, mid + 1, r, pos, val, cur_rever, dep + 1);
        }
        sg[v] = sg[v << 1] + sg[v << 1 | 1];
    }
}

int64_t get_sum (int v, int x, int y, int l, int r, bool cur_rever = false, int dep = 1) {

    cur_rever ^= rev[dep];
    bool cur_sw = sw[dep];
    if (l == x && r == y) {
        return sg[v];
    } else {
        int mid = x + y >> 1;
        if (r <= mid) {
            int nxt_node = v << 1;
            nxt_node ^= cur_sw;
            nxt_node ^= cur_rever;
            return get_sum(nxt_node, x, mid, l, r, cur_rever, dep + 1);
        } else if (l > mid) {
            int nxt_node = v << 1 | 1;
            nxt_node ^= cur_sw;
            nxt_node ^= cur_rever;
            return get_sum(nxt_node, mid + 1, y, l, r, cur_rever, dep + 1);
        } else {
            int to_xor = cur_sw ^ cur_rever;
            return get_sum((v << 1) ^ to_xor, x, mid, l, mid, cur_rever, dep + 1)
            + get_sum((v << 1 | 1) ^ to_xor, mid + 1, y, mid + 1, r, cur_rever, dep + 1);
        }
    }

}

int a[nax];

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> nq;

    for (int i = 1 ; i <= (1 << n) ; ++ i)
        cin >> a[i];

    int sz = 1 << n;
    build(1, 1, 1 << n, a);

    for (; nq -- ;) {
        int type;
        cin >> type;
        if (type == 1) {
            int pos, val;
            cin >> pos >> val;
            update(1, 1, 1 << n, pos, val);
        } else if (type == 2) {
            int k;
            cin >> k;
            rev[n - k + 1] ^= 1;
        } else if (type == 3) {
            int k;
            cin >> k;
            sw[n - k] ^= 1;
        } else if (type == 4) {
            int l, r;
            cin >> l >> r;
            cout << get_sum(1, 1, 1 << n, l, r) << '\n';
        } else throw;
    }
}