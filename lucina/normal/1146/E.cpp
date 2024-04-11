#include<bits/stdc++.h>
using namespace std;
int const nax = 100005, lim = 100000, Mx = 4 * lim + 10;
int n, q, a[nax];

struct node {
    int type ;

    node () : type (0) {}
    node (int type) : type(type) {}
    friend void apply (node & a, node & b) {
        if (a.type == 0) return;
        if (b.type == 0) {b.type = a.type; return;}
        if (a.type == 1) {
            if (b.type == 1) b.type = 0;
            else b.type += (b.type & 1) ? -1 : 1;
        } else {
            b.type = a.type;
        }
    }
};

int tp[nax];
bool is_leaf[Mx];

struct Segtree {
    node sg[Mx];


    inline void push (int v) {
        if (is_leaf[v] || sg[v].type == 0) return;
        apply(sg[v], sg[v * 2]);
        apply(sg[v], sg[v * 2 + 1]);
        sg[v].type = 0;
    }

    inline void update (int v, int x, int y, int l, int r, int type) {
        push(v);
        if (l > r) return ;

        if (l == x && r == y) {
            node tmp = node(type);
            apply(tmp, sg[v]);
            push(v);
            return;
        }

        int mid = x + y >> 1;
        update(v * 2, x, mid, l, min(r, mid), type);
        update(v * 2 + 1 , mid + 1 , y, max(l, mid + 1), r, type);
    }

    void update(int l, int r, int type) {
        update(1, 1, lim, l, r, type);
    }

    void get_ans (int v, int l, int r) {
        push(v);
        if (l == r) {
            tp[l] = sg[v].type;
            return;
        }
        int mid = l + r >> 1;
        get_ans(v * 2, l , mid);
        get_ans(v * 2 + 1, mid + 1, r);
    }
    void build (int v, int l, int r) {
        if (l == r) {
            is_leaf[v] = true;
            return;
        }
        int mid = l + r >> 1;
        build(v * 2, l, mid);
        build(v * 2 + 1, mid + 1, r);
    }
};
Segtree seg;



int main () {
    scanf("%d %d", &n, &q);

    for (int i = 1 ; i <= n ; ++ i)
        scanf("%d", a + i);

    seg.build(1, 1, lim);
    for (; q -- ;) {
        char c; int x;
        scanf(" %c %d", &c, &x);

        if (c == '>') {
            ++ x;
            if (x == 0) x = 1;
            if (x > lim) continue;

            if (x < 0) {
                seg.update(1, abs(x), 1);
                if (abs(x) + 1 <= lim)
                    seg.update(abs(x) + 1, lim, 2);
            } else if (x > 0) {
                seg.update(x, lim, 2);
            }
        } else if (c == '<') {
            -- x;
            if (x == 0) x = -1;
            if (x < -lim) continue;

            if (x > 0) {
                seg.update(1, x, 1);
                if (x + 1 <= lim) {
                    seg.update(x + 1, lim, 3);
                }
            } else if (x < 0) {
                seg.update(abs(x), lim, 3);
            }
        }
    }

    seg.get_ans(1, 1 , lim);


    for (int i = 1 ; i <= n ; ++ i) {

        int f = tp[abs(a[i])];
        if (f == 0) {
            printf("%d ", a[i]);
        } else if (f == 1) {
            printf("%d ", -a[i]);
        } else if (f == 2) {
            printf("%d ", -abs(a[i]));
        } else if (f == 3) {
            printf("%d ", abs(a[i]));
        }
    }

}