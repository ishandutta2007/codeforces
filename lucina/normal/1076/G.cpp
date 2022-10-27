#include<bits/stdc++.h>
using namespace std;
int const nax = 2e5 + 5;

int m;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

struct Data {
    int f[6];

    int& operator [] (int r) {
        return f[r];
    }

    Data () {
        memset(f, 0, sizeof(f));
    }

    Data (int x) {

        memset(f, 0, sizeof(f));

        if (x == 1) {
            for (int j = 0 ; j < m ; ++ j)
                f[j] = j + 1;
            f[m] = 0;
        } else if (x == 0) {
            for (int j = 0 ; j <= m ; ++ j)
                f[j] = min(j + 1, m);
        }

    }

    friend Data operator + (Data x, Data y) {
        Data res;
        for (int i = 0 ; i <= m ; ++ i) {
            res[i] = x[y[i]];
        }
        return res;
    }

    void print() const {
        eprintf("Data :");
        for (int i = 0 ; i <= m ; ++ i)
            eprintf("%d ", f[i]);
        eprintf("\n");
    }
};

template<class context = Data>
struct segtree {
    static const int Mx = nax << 2;

    context sg1[Mx];
    context sg2[Mx];
    bool lazy[Mx] = {};

    segtree () {
        fill(sg1, sg1 + Mx, Data());
        fill(sg2, sg2 + Mx, Data());
        memset(lazy, false, sizeof(lazy));
    }

    inline void pull (int v) {
        sg1[v] = sg1[v << 1] + sg1[v << 1 ^ 1];
        sg2[v] = sg2[v << 1] + sg2[v << 1 ^ 1];
    }

    inline void push (int v) {

        if (lazy[v]) {
            swap(sg1[v], sg2[v]);
            if ((v << 1) < Mx)
                lazy[v << 1] ^= 1;
            if ((v << 1 ^ 1) < Mx)
                lazy[v << 1 ^ 1] ^= 1;
        }

        lazy[v] = false;
    }

    void build (int v, int l, int r, int *a) {

        if (l == r) {
            sg1[v] = Data(a[l]);
            sg2[v] = Data(a[l] ^ 1);

            return ;
        }

        int mid = l + r >> 1;
        build(v << 1, l, mid, a);
        build(v << 1 ^ 1, mid + 1, r, a);
        pull(v);
    }

    ///flip whole range
    inline void update (int v, int x, int y, int l, int r) {
        push(v);
        if (l > r) return ;
        if (l == x && r == y) {
            lazy[v] ^= 1;
            push(v);
            return ;
        }

        int mid = x + y >> 1;
        update(v << 1, x, mid, l, min(r, mid));
        update(v << 1 ^ 1, mid + 1, y, max(l, mid + 1), r);

        pull(v);
    }

    inline Data query (int v, int x, int y, int l, int r) {
        push(v);

        if (l == x && r == y) {
            return sg1[v];
        }

        int mid = x + y >> 1;
        if (r <= mid) {
            return query(v << 1, x, mid, l, r);
        }

        if (l > mid) {
            return query(v << 1 ^ 1, mid + 1, y, l, r);
        }
        /**
            This way you don't need to use identity
        */

        return query(v << 1, x, mid, l, mid) + query(v << 1 ^ 1, mid + 1, y, mid + 1, r);
    }
};

using ll = long long ;


int n, nq;
int a[nax];

segtree <Data> sg;

int main () {

    scanf("%d %d %d", &n, &m, &nq);

    for (int i = 1 ; i <= n ; ++ i) {
        ll p;
        scanf("%lld", &p);
        a[i] = p % 2;
    }

    sg.build(1, 1, n, a);

    for (int i = 1 ; i <= nq ; ++ i) {

        int opt;
        scanf("%d", &opt);

        if (opt == 1) {
            int l, r;
            ll d;

            scanf("%d %d %lld", &l, &r, &d);

            if (d % 2)
                sg.update(1, 1, n, l, r);

        } else if (opt == 2) {

            int l, r;
            scanf("%d %d", &l, &r);

            Data get = sg.query(1, 1, n, l, r);

            puts(get[m] ? "1" : "2");

        } else throw;
    }

}