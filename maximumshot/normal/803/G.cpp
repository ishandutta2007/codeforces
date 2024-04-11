#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 1e5 + 5;
int const LOG = 22;

int n, k;
int b[N];

int rmq[LOG][N];
int _log[N];

void buildRmq() {
    _log[1] = 0;
    for(int i = 1;i < N;i++) {
        _log[i] = _log[i - 1];
        if((1 << (_log[i] + 1)) <= i) {
            _log[i]++;
        }
    }
    for(int j = 0;j < LOG;j++) {
        for(int i = 0;i < n;i++) {
            rmq[j][i] = inf;
        }
    }
    for(int i = 0;i < n;i++) {
        rmq[0][i] = b[i];
    }
    for(int j = 1;j < LOG;j++) {
        for(int i = 0;i + (1 << (j - 1)) < n;i++) {
            rmq[j][i] = min(
                rmq[j - 1][i],
                rmq[j - 1][i + (1 << (j - 1))]
            );
        }
    }
}

int get_rmq(int l, int r) {
    int LG = _log[r - l + 1];
    return min(
        rmq[LG][l],
        rmq[LG][r - (1 << LG) + 1]
    );
}

struct Node {
    Node *l, *r;
    int mn;
    int pu;
    Node() : l(0), r(0), mn(inf), pu(-1) { }
};

Node * makeNode(int tl, int tr) {
    Node * v = new Node();
    if(tr - tl + 1 > n) {
        v->mn = get_rmq(0, n - 1);
    }else {
        if(tl % n <= tr % n) {
            v->mn = get_rmq(tl % n, tr % n);
        }else {
            v->mn = min(
                get_rmq(tl % n, n - 1),
                get_rmq(0, tr % n)
            );
        }
    }
    return v;
}

void push(Node *& v, int tl, int tm, int tr) {
    if(v && v->pu != -1) {
        if(!v->l) v->l = makeNode(tl, tm);
        if(!v->r) v->r = makeNode(tm + 1, tr);
        v->l->pu = v->l->mn = v->pu;
        v->r->pu = v->r->mn = v->pu;
        v->pu = -1;
    }
}

int get(Node * v, int tl, int tr) {
    if(v) return v->mn;
    if(tr - tl + 1 > n) {
        return get_rmq(0, n - 1);
    }else {
        if(tl % n <= tr % n) {
            return get_rmq(tl % n, tr % n);
        }else {
            return min(
                get_rmq(tl % n, n - 1),
                get_rmq(0, tr % n)
            );
        }
    }
}

void up(Node *& v, int tl, int tm, int tr) {
    v->mn = min(get(v->l, tl, tm), get(v->r, tm + 1, tr));
}

void update(Node *& v, int tl, int tr, int l, int r, int x) {
    if(l <= tl && tr <= r) {
        v->pu = x;
        v->mn = x;
    }else {
        int tm = (tl + tr) / 2;
        push(v, tl, tm, tr);
        if(l <= tm) {
            if(!v->l) v->l = makeNode(tl, tm);
            update(v->l, tl, tm, l, r, x);
        }
        if(r > tm) {
            if(!v->r) v->r = makeNode(tm + 1, tr);
            update(v->r, tm + 1, tr, l, r, x);
        }
        up(v, tl, tm, tr);
    }
}

int get_min(Node *& v, int tl, int tr, int l, int r) {
    if(l <= tl && tr <= r) {
        return get(v, tl, tr);
    }else {
        int res = inf;
        int tm = (tl + tr) / 2;
        push(v, tl, tm, tr);
        if(l <= tm) {
            if(!v->l) v->l = makeNode(tl, tm);
            res = min(res, get_min(v->l, tl, tm, l, r));
        }
        if(r > tm) {
            if(!v->r) v->r = makeNode(tm + 1, tr);
            res = min(res, get_min(v->r, tm + 1, tr, l, r));
        }
        up(v, tl, tm, tr);
        return res;
    }
}

int main() {

    scanf("%d %d", &n, &k);

    for(int i = 0;i < n;i++) {
        scanf("%d", &b[i]);
    }

    buildRmq();

    int q;
    scanf("%d", &q);

    Node * root = makeNode(0, n * k - 1);

    for(int ty, l, r, x, iter = 0;iter < q;iter++) {
        scanf("%d %d %d", &ty, &l, &r);
        if(ty == 1) {
            scanf("%d", &x);
            update(root, 0, n * k - 1, l - 1, r - 1, x);
        }else {
            printf("%d\n", get_min(root, 0, n * k - 1, l - 1, r - 1));
        }
    }

    return 0;
}