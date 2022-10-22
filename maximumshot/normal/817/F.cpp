#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

inline int nextRand() {
    return (rand() << 16) | rand();
}

struct Treap {
    struct Node {
        Node * l;
        Node * r;
        int prior;
        int cnt;
        ll value;
        Node() {
            l = 0;
            r = 0;
            prior = nextRand();
            cnt = 0;
            value = 0;
        }
        Node(ll _value) {
            l = 0;
            r = 0;
            prior = nextRand();
            cnt = 1;
            value = _value;
        }
    };

    void update(Node *& v) {
        v->cnt = 1;
        if(v->l) {
            v->cnt += v->l->cnt;
        }
        if(v->r) {
            v->cnt += v->r->cnt;
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
        if(v) update(v);
    }

    void split_by_value(Node * v, Node *& l, Node *& r, ll value) {
        if(!v) {
            l = r = 0;
            return;
        }
        if(v->value <= value) {
            split_by_value(v->r, v->r, r, value);
            l = v;
        }else {
            split_by_value(v->l, l, v->l, value);
            r = v;
        }
        if(l) update(l);
        if(r) update(r);
    }

    inline int get_cnt(Node * v) {
        return v ? v->cnt : 0;
    }

    void split_by_cnt(Node * v, Node *& l, Node *& r, int cnt) {
        if(!v) {
            l = r = 0;
            return;
        }
        if(get_cnt(v->l) + 1 <= cnt) {
            split_by_cnt(v->r, v->r, r, cnt - get_cnt(v->l) - 1);
            l = v;
        }else {
            split_by_cnt(v->l, l, v->l, cnt);
            r = v;
        }
        if(l) update(l);
        if(r) update(r);
    }

    Node * root;

    Treap() : root(0) { }

    void insert(ll value) {
        Node *nl, *nr;
        nl = nr = 0;
        split_by_value(root, nl, nr, value);
        merge(nl, nl, new Node(value));
        merge(root, nl, nr);
    }

    void erase(ll value) {
        Node *nl, *nm, *nr;
        nl = nm = nr = 0;
        split_by_value(root, nl, nr, value);
        split_by_cnt(nl, nl, nm, get_cnt(nl) - 1);
        merge(root, nl, nr);
    }

    int count(ll value) {
        Node *nl, *nm, *nr;
        nl = nm = nr = 0;
        split_by_value(root, nl, nr, value);
        split_by_cnt(nl, nl, nm, get_cnt(nl) - 1);
        int res = get_cnt(nm);
        merge(nl, nl, nm);
        merge(root, nl, nr);
        return res;
    }

    int get_pos(ll value) {
        Node *nl, *nr;
        nl = nr = 0;
        split_by_value(root, nl, nr, value - 1);
        int res = get_cnt(nl);
        merge(root, nl, nr);
        return res;
    }

    bool empty() {
        return get_cnt(root) == 0;
    }

    int size() {
        return get_cnt(root);
    }

    ll lower_bound(ll value) {
        Node *nl, *nm, *nr;
        split_by_value(root, nl, nr, value - 1);
        ll res;
        if(nr) {
            split_by_cnt(nr, nm, nr, 1);
            res = nm->value;
            merge(nr, nm, nr);
        }else {
            res = -1;
        }
        merge(root, nl, nr);
        return res;
    }

    ll upper_bound(ll value) {
        return lower_bound(value + 1);
    }

    ll At(int pos) {
        if(pos < 0 || pos >= get_cnt(root)) return -1;
        Node *nl, *nm, *nr;
        nl = nm = nr = 0;
        split_by_cnt(root, nl, nr, pos);
        split_by_cnt(nr, nm, nr, 1);
        ll res = nm->value;
        merge(nr, nm, nr);
        merge(root, nl, nr);
        return res;
    }

    void eraseAll(ll l, ll r) {
        Node *nl, *nm, *nr;
        nl = nm = nr = 0;
        split_by_value(root, nl, nr, l - 1);
        split_by_value(nr, nm, nr, r);
        merge(root, nl, nr);
    }
};

int n;
Treap tr;
int fi;

int getColor(ll pos) {
    ll vl = tr.upper_bound(pos);
    int need_id = vl == -1 ? tr.size() - 1 : tr.get_pos(vl) - 1;
    return (need_id % 2) ^ fi;
}

void print(int color, ll l, ll r) {
    int cl = l > 1 ? getColor(l - 1) : -1;
    int cr1 = getColor(r);
    int cr2 = getColor(r + 1);
    int need_l = 0;
    if(l > 1 && cl == color) { }
    else {
        need_l = 1;
    }
    tr.eraseAll(l, r);
    if(need_l) {
        tr.insert(l);
    }
    if(cr1 != color) {
        if(cr2 == color) {
            tr.erase(r + 1);
        }else {
            tr.insert(r + 1);
        }
    }
    if(l == 1) {
        fi = color;
    }
}

void invert(ll l, ll r) {
    if(l == 1) fi ^= 1;
    int cl1 = l > 1 ? getColor(l - 1) : -1;
    int cl2 = getColor(l);
    int cr1 = getColor(r);
    int cr2 = getColor(r + 1);
    if(l > 1) {
        if(cl1 == cl2) {
            tr.insert(l);
        }else {
            tr.erase(l);
        }
    }
    if(cr1 == cr2) {
        tr.insert(r + 1);
    }else {
        tr.erase(r + 1);
    }
}

ll query() {
    if(fi == 0) {
        return tr.At(0);
    }else {
        return tr.At(1);
    }
}

int main() {

    srand(time(NULL));

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);

    cin >> n;

    tr.insert(1);
    fi = 0;

    int ty;
    ll l, r;

    for(int iter = 0;iter < n;iter++) {
        cin >> ty >> l >> r;

        if(ty < 3) {
            print(ty == 1 ? 1 : 0, l, r);
        }else {
            invert(l, r);
        }

        cout << query() << "\n";
    }

    return 0;
}