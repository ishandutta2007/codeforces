#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

inline int nextRand() {
    return (rand() << 16) | rand();
}

struct Node {
    Node * l, * r;
    int prior;
    int cnt;
    int value;
    int pu;
    Node() {
        l = 0;
        r = 0;
        prior = nextRand();
        cnt = 0;
        value = inf + 10;
        pu = 0;
    }
    Node(int t) {
        l = 0;
        r = 0;
        prior = nextRand();
        cnt = 1;
        value = t;
        pu = 0;
    }
};

inline void update(Node *& v){
    v->cnt = 1;
    if(v->l) {
        v->cnt += v->l->cnt;
    }
    if(v->r) {
        v->cnt += v->r->cnt;
    }
}

void push(Node * v) {
    if(v->pu) {
        if(v->l) {
            v->l->pu += v->pu;
            v->l->value += v->pu;
        }
        if(v->r) {
            v->r->pu += v->pu;
            v->r->value += v->pu;
        }
        v->pu = 0;
    }
}

void merge(Node *& v, Node * l, Node * r) {
    if(l) push(l);
    if(r) push(r);
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
    if(v) update(v);
}

void split_by_key(Node *v, Node *& l, Node *& r, int x) {
    if(v) push(v);
    if(!v) {
        l = r = 0;
        return;
    }
    if(v->value <= x) {
        split_by_key(v->r, v->r, r, x);
        l = v;
    }else {
        split_by_key(v->l, l, v->l, x);
        r = v;
    }
    if(l) update(l);
    if(r) update(r);
}

inline int get_cnt(Node * v) {
    return v ? v->cnt : 0;
}

void split_by_cnt(Node * v, Node *& l, Node *& r, int x) {
    if(v) push(v);
    if(!v) {
        l = r = 0;
        return;
    }
    if(get_cnt(v->l) + 1 <= x) {
        split_by_cnt(v->r, v->r, r, x - get_cnt(v->l) - 1);
        l = v;
    }else {
        split_by_cnt(v->l, l, v->l, x);
        r = v;
    }
    if(l) update(l);
    if(r) update(r);
}

void show(Node * v) {
    if(!v) return;
    show(v->l);
    cout << v->value << " ";
    show(v->r);
}

bool check(Node * t, int value) {
    Node *nl, *nm, *nr;
    nl = nm = nr = 0;
    split_by_key(t, nl, nr, value);
    split_by_key(nl, nl, nm, value - 1);
    bool res = nm ? true : false;
    merge(nl, nl, nm);
    merge(t, nl, nr);
    return res;
}

int main() {

    srand(time(NULL));

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    int n;

    scanf("%d", &n);

    Node * t = 0;

    for(int i = 1;i <= n;i++) {
        merge(t, t, new Node(inf + 10));
    }

    for(int l, r, iter = 0;iter < n;iter++) {
        scanf("%d %d", &l, &r);

        bool have = check(t, l);

        if(have && l == r) {
            continue;
        }

        Node *nl, *nm, *nr;
        nl = nm = nr = 0;

        split_by_key(t, nl, nr, l);
        split_by_key(nr, nm, nr, r - 1);

        Node *tmp;

        tmp = 0;

        split_by_cnt(nr, tmp, nr, 1);
        merge(nm, nm, tmp);

#ifdef maximumSHOT
        cout << iter << " : ";
        show(nm);
        cout << "\n";
#endif

        if(nm) {
            tmp = 0;
            split_by_cnt(nm, nm, tmp, get_cnt(nm) - 1);
            if(nm) {
                nm->pu++;
                nm->value++;
            }
            if(l + (int)have <= r) {
                merge(nm, new Node(l + (int)have), nm);
            }
        }

        merge(nl, nl, nm);
        merge(t, nl, nr);

#ifdef maximumSHOT
        cout << "add [" << l << " .. " << r << "] : ";
        show(t);
        cout << "\n";
#endif
    }

    for(int i = n;i >= 1;i--) {
        Node *nl, *nm, *nr;
        nl = nm = nr = 0;

        split_by_cnt(t, nl, nr, i);
        split_by_cnt(nl, nl, nm, i - 1);

        if(nm->value <= inf) {
            printf("%d\n", i);
            return 0;
        }

        merge(nl, nl, nm);
        merge(t, nl, nr);
    }

    return 0;
}