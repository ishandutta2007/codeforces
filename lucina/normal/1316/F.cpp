#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
const int mod = 1e9 + 7, INV2 = (mod + 1) / 2;

int add (int a, int b) {
    return ((a += b) >= mod) ? a - mod : a;
}

int sub (int a, int b) {
    return ((a -= b) < 0) ? a + mod : a;
}

int mul (int a, int b) {
    return 1LL * a * b % mod;
}
/// sigh when will you remember this? :P
#define data Data

int p2[nax], invp2[nax];

struct data {
    int val, lval, rval, power ;

    data () : val(), lval(), rval(), power() {}
    data (int val, int lval, int rval, int power) : val(val), lval(lval), rval(rval), power(power) {}

    friend data operator + (const data & x, const data & y) {
        data res;

        res.val = add(x.val, y.val);
        res.val = add(res.val, mul(x.lval, mul(y.rval, invp2[x.power])));
        res.lval = add(x.lval, mul(y.lval, p2[x.power]));
        res.rval = add(x.rval, mul(y.rval, invp2[x.power]));
        res.power = x.power + y.power;

        return res;
    }

    void print () const {
        fprintf(stderr, "data val lval rval power %d %d %d %d\n", val, lval, rval , power);
    }
};

struct segtree {

    data sg[nax << 3];

    void update (int v, int l, int r, int pos, int val, int opt) {

        if (l == r) {

            if (opt == 1) {
                sg[v] = data(0, val, 1LL * val * INV2 % mod, 1);

            } else {
                sg[v] = data();
            }

            return ;
        }

        int mid = l + r >> 1;
        if (pos <= mid) update(v << 1, l, mid, pos, val, opt);
        else update(v << 1 | 1, mid + 1, r, pos, val, opt);

        sg[v] = sg[v << 1] + sg[v << 1 ^ 1];
    }


};

int n, q;
pair <int, int> com[nax << 1];
int p[nax];
int pos[nax];
int val[nax];
int last_pos[nax];


segtree sg;

int main () {


    int top = 0;

    p2[0] = 1;
    invp2[0] = 1;
    for (int i = 1 ; i < nax ; ++ i) {
        p2[i] = add(p2[i - 1], p2[i - 1]);
        invp2[i] = mul(invp2[i - 1], INV2);
    }

    scanf("%d", &n);

    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d", p + i);
        com[++ top] = make_pair(p[i], i);
    }

    scanf("%d", &q);


    for (int i = 1 ; i <= q ; ++ i) {
        scanf("%d %d", pos + i, val + i);
        com[++ top] = make_pair(val[i], n + i);
    }



    sort(com + 1, com + top + 1);



    for (int i = 1 ; i <= n ; ++ i) {
        int pos_in_seg = lower_bound(com + 1, com + top + 1, make_pair(p[i], i)) - com;
        sg.update(1, 1, top, pos_in_seg, p[i], 1);
        last_pos[i] = pos_in_seg;
    }


    printf("%d\n", sg.sg[1].val);

    for (int i = 1 ; i <= q ; ++ i) {
        int pos_in_seg = lower_bound(com + 1, com + top + 1, make_pair(val[i], n + i)) - com;
        int lst = last_pos[pos[i]];

        sg.update(1, 1, top, lst, 0, 0);
        sg.update(1, 1, top, pos_in_seg, val[i], 1);

        last_pos[pos[i]] = pos_in_seg;

        printf("%d\n", sg.sg[1].val);
    }
}