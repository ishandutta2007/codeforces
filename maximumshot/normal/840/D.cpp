#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 3e5 + 5;

struct Node;
inline int get_cnt(Node * v);

struct Node {
    Node * l;
    Node * r;
    int cnt;
    Node() {
        l = 0;
        r = 0;
        cnt = 0;
    }
    Node(int _cnt) {
        l = 0;
        r = 0;
        cnt = _cnt;
    }
    Node(Node * _l, Node * _r) {
        l = _l;
        r = _r;
        cnt = get_cnt(l) + get_cnt(r);
    }
};

inline int get_cnt(Node * v) {
    return v ? v->cnt : 0;
}

inline Node * get_left(Node * v) {
    return v ? v->l : 0;
}

inline Node * get_right(Node * v) {
    return v ? v->r : 0;
}

Node * update(Node * v, int tl, int tr, int pos) {
    if(tl == tr) {
        return new Node(get_cnt(v) + 1);
    }else {
        int tm = (tl + tr) / 2;
        if(pos <= tm) {
            return new Node(
                update(get_left(v), tl, tm, pos),
                get_right(v)
            );
        }else {
            return new Node(
                get_left(v),
                update(get_right(v), tm + 1, tr, pos)
            );
        }
    }
}

int query(Node * L, Node * R, int tl, int tr, int l, int r, int k) {
    if((get_cnt(R) - get_cnt(L)) * k <= 1ll * (r - l + 1)) {
        return -1;
    }
    if(tl == tr) {
        return (get_cnt(R) - get_cnt(L)) * k > r - l + 1 ? tl : -1;
    }else {
        int tm = (tl + tr) / 2;
        int res = query(get_left(L), get_left(R), tl, tm, l, r, k);
        if(res == -1) res = query(get_right(L), get_right(R), tm + 1, tr, l, r, k);
        return res;
    }
}

int n, q;
Node * tree[N];
int a[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &q);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
        tree[i] = update(tree[i - 1], 1, n, a[i]);
    }

    for(int l, r, k, i = 0;i < q;i++) {
        scanf("%d %d %d", &l, &r, &k);
        printf("%d\n", query(tree[l - 1], tree[r], 1, n, l, r, k));
    }

    return 0;
}