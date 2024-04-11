#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef unsigned long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 200005;

int nextRand() {
    return (rand() << 16) | rand();
}


struct treap {
private:

    struct Node {
        Node *l, *r;
        int prior;

        int t;
        int id;
        int a;
        // { t, id, a }

        int cnt;
        int sum_a;
        int sum_t;
        int sum_t2;

        Node() : l(0), r(0), prior( nextRand() ), t(0), id(0), a(0), cnt(0), sum_a(0), sum_t(0), sum_t2(0) { }
        Node(int t, int id, int a) :
            l(0), r(0), prior( nextRand() ), t(t), id(id), a(a), cnt(1), sum_a(a), sum_t(t), sum_t2( (t + 1) / 2 )  { }
    };

    void update(Node *& v) {
        v->cnt = 1;
        v->sum_a = v->a;
        v->sum_t = v->t;
        v->sum_t2 = (v->t + 1) / 2;
        if(v->l) {
            v->cnt += v->l->cnt;
            v->sum_a += v->l->sum_a;
            v->sum_t += v->l->sum_t;
            v->sum_t2 += v->l->sum_t2;
        }
        if(v->r) {
            v->cnt += v->r->cnt;
            v->sum_a += v->r->sum_a;
            v->sum_t += v->r->sum_t;
            v->sum_t2 += v->r->sum_t2;
        }
    }

    void merge(Node *& v, Node * l, Node * r) {
        if(!l || !r) {
            v = l ? l : r;
            return;
        }
        if(l->prior < r->prior) {
            merge(l->r, l->r, r);
            v = l;
        }else {
            merge(r->l, l, r->l);
            v = r;
        }
        if(v) update( v );
    }

    // <=
    void split_by_value(Node * v, Node *& l, Node *& r, int t, int id, int a) {
        if(!v) {
            l = r = 0;
            return;
        }
        if( make_tuple( v->t, v->id, v->a ) <= make_tuple( t, id, a ) ) {
            split_by_value(v->r, v->r, r, t, id, a);
            l = v;
        }else {
            split_by_value(v->l, l, v->l, t, id, a);
            r = v;
        }
        if(l) update( l );
        if(r) update( r );
    }

    int get_cnt(Node * v) {
        return v ? v->cnt : 0;
    }

    void split_by_cnt(Node * v, Node *& l, Node *& r, int cnt) {
        if(!v) {
            l = r = 0;
            return;
        }
        if( get_cnt(v->l) + 1 <= cnt ) {
            split_by_cnt( v->r, v->r, r, cnt - get_cnt(v->l) - 1 );
            l = v;
        }else {
            split_by_cnt( v->l, l, v->l, cnt );
            r = v;
        }
        if(l) update( l );
        if(r) update( r );
    }

    Node * root;
public:

    treap() : root(0) { }

    void insert(int t, int id, int a) {
        Node *nl, *nm, *nr;
        nl = nm = nr = 0;
        split_by_value( root, nl, nr, t, id, a );
        merge(nl, nl, new Node(t, id, a) );
        merge(root, nl, nr);
    }
    void erase(int t, int id, int a) {
        Node * nl, *nm, *nr;
        nl = nm = nr = 0;
        split_by_value( root, nl, nr, t, id, a );
        split_by_cnt( nl, nl, nm, get_cnt(nl) - 1 );
        merge(root, nl, nr);
    }
    int calc(int w, int k) {
        Node *nl, *nm, *nr;
        nl = nm = nr = 0;
        w = min( w, get_cnt(root) );
        split_by_cnt( root, nl, nr, get_cnt( root ) - w );
        int total = ( nl ? nl->sum_t : 0 ) + ( nr ? nr->sum_t2 : 0 );
        int result;
        if(total > k) result = -inf;
        else result = ( nl ? nl->sum_a : 0 ) + ( nr ? nr->sum_a : 0 );
        merge(root, nl, nr);
        return result;
    }
};

int n, w, k;
int a[N];
int t[N];

int main() {

    srand(time(NULL));

    scanf("%d %d %d", &n, &w, &k);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }

    for(int i = 1;i <= n;i++) {
        scanf("%d", &t[i]);
    }

    treap T;

    int res = 0;

    for(int l = 1, r = 1;r <= n;r++) {
        T.insert(t[r], r, a[r]);
        while(l <= r && T.calc(w, k) == -inf ) {
            T.erase( t[l], l, a[l] );
            l++;
        }
        if(l <= r) res = max( res, T.calc(w, k) );
    }

    printf("%d\n", res);

    return 0;
}