#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

struct Node {
    Node * l;
    Node * r;
    ll x;
    Node() {
        l = 0;
        r = 0;
        x = 0;
    }
    Node(ll y, Node * _l, Node * _r) {
        l = _l;
        r = _r;
        x = y;
    }
    Node(Node * _l, Node * _r) {
        l = _l;
        r = _r;
        x = 0;
    }
};

Node * update(Node * v, int tl, int tr, int l, int r, ll x) {
    if(l <= tl && tr <= r) {
        return new Node((v ? v->x : 0) + x, (v ? v->l : 0), (v ? v->r : 0));
    }else {
        int tm = (tl + tr) / 2;
        if(l <= tm) {
            if(r > tm) {
                return new Node(
                    (v ? v->x : 0),
                    update(v ? v->l : 0, tl, tm, l, r, x),
                    update(v ? v->r : 0, tm + 1, tr, l, r, x)
                );
            }else {
                return new Node(
                    (v ? v->x : 0),
                    update(v ? v->l : 0, tl, tm, l, r, x),
                    (v ? v->r : 0)
                );
            }
        }else {
            return new Node(
                (v ? v->x : 0),
                (v ? v->l : 0),
                update(v ? v->r : 0, tm + 1, tr, l, r, x)
            );
        }
    }
}

ll get(Node * L, Node * R, int tl, int tr, int pos) {
    ll res = (R ? R->x : 0) - (L ? L->x : 0);
    if(tl < tr) {
        int tm = (tl + tr) / 2;
        if(pos <= tm) {
            res += get(L ? L->l : 0, R ? R->l : 0, tl, tm, pos);
        }else {
            res += get(L ? L->r : 0, R ? R->r : 0, tm + 1, tr, pos);
        }
    }
    return res;
}

int const X = 2e5 + 5;
int const N = 75005;

int n;
Node * p[N];
Node * q[N];

int main() {

#ifdef debug;
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for(int x1, x2, y1, a, b, y2, i = 1;i <= n;i++) {
        scanf("%d %d %d %d %d %d", &x1, &x2, &y1, &a, &b, &y2);
        p[i] = update(p[i - 1], 0, X, 0, x1, y1);
        p[i] = update(p[i], 0, X, x1 + 1, x2, b);
        p[i] = update(p[i], 0, X, x2 + 1, X, y2);
        q[i] = update(q[i - 1], 0, X, x1 + 1, x2, a);
    }

    ll last = 0;

    int m;

    scanf("%d", &m);

    for(int l, r, x, iter = 0;iter < m;iter++) {
        scanf("%d %d %d", &l, &r, &x);
        x = (x + last) % inf;
        x = min(x, X);
        last = get(p[l - 1], p[r], 0, X, x) +
               get(q[l - 1], q[r], 0, X, x) * x;
#ifdef debug
        printf("%lld\n", last);
#else
        printf("%I64d\n", last);
#endif
    }

    return 0;
}