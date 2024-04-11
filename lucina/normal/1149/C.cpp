#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
/**
    answer for substring

    take any position y, the answer is
    take x and z from left and right
    such that d[x] + d[z] - 2 * d[y] is maximum.
    this allows us to maintain some information of each substring.
    maximum value of d[x]
    minimum depth which means -d[y] is maximized
    maximum value of d[x] - 2 * d[y]
    maximum value of - 2 * d[y] + d[z]
    maximum answer
*/
struct node {
    int max_depth;
    int min_depth;
    int max_x2y; /// x - 2 * y
    int max_2yz; /// z - 2 * y
    int bal;
    int ans;

    node (int x = 1) : bal(x) {
        if (x == 1) {
            max_depth = 1;
            min_depth = 0;
            max_x2y = 0;
            max_2yz = 1;
            ans = 1;
        } else if (x == -1) {
            max_depth = 0;
            min_depth = -1;
            max_x2y = 2;
            max_2yz = 1;
            ans = 1;
        } else assert(false);
    }

    node shift (int dif) {
        node res = *this;
        res.bal += dif;
        res.max_depth += dif;
        res.min_depth += dif;
        res.max_x2y -= dif;
        res.max_2yz -= dif;
        return res;
    }

    friend node operator + (node a, node b) {
        node res;
        b = b.shift(a.bal);
        res.bal = b.bal;
        res.max_depth = max(a.max_depth, b.max_depth);
        res.min_depth = min(a.min_depth, b.min_depth);
        res.max_x2y = max({a.max_x2y, b.max_x2y, a.max_depth - 2 * b.min_depth});
        res.max_2yz = max({a.max_2yz, b.max_2yz, -2 * a.min_depth + b.max_depth});
        res.ans = max({a.ans, b.ans, a.max_x2y + b.max_depth, a.max_depth + b.max_2yz});
        return res;
    }
};

char s[nax];

struct segtree {
    node sg[nax << 2];

    void pull (int v) {
        sg[v] = sg[v << 1] + sg[v << 1 | 1];
    }

    void update (int v, int x, int y, int pos) {
        if (x == y) {
            sg[v] = node(s[pos] == '(' ? 1 : -1);
        } else {
            int mid = x + y >> 1;
            if (pos <= mid) update(v << 1, x, mid, pos);
            else update(v << 1 | 1, mid + 1, y, pos);
            pull(v);
        }
    }
};
segtree sg;

int n, q;


int main () {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> q >> s + 1;
    n = 2 * n - 2;
    for (int i = 1 ; i <= n ; ++ i)
        sg.update(1, 1, n, i);

    cout << sg.sg[1].ans << '\n';
    for (; q -- ;) {
        int l, r;
        cin >> l >> r;
        swap(s[l], s[r]);
        sg.update(1, 1, n, l);
        sg.update(1, 1, n, r);
        cout << sg.sg[1].ans << '\n';
    }
}