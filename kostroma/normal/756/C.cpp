#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
//#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve(bool);
void precalc();
clock_t start;
//int timer = 1;

int testNumber = 1;

bool todo = true;

int main() {
#ifdef AIM
    freopen("/home/alexandero/ClionProjects/ACM/input.txt", "r", stdin);
    //freopen("/home/alexandero/ClionProjects/ACM/output.txt", "w", stdout);
    //freopen("out.txt", "w", stdout);
#else
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    start = clock();
    int t = 1;
    cout.sync_with_stdio(0);
    cin.tie(0);
    precalc();
    cout.precision(10);
    cout << fixed;
    //cin >> t;
    int testNum = 1;
    while (t--) {
        //cerr << testNum << endl;
        //cout << "Case #" << testNum++ << ": ";
        solve(true);
        ++testNumber;
        //++timer;
    }

    /*while (true) {
        solve(false);
    }*/

#ifdef AIM
    cerr << "\n\n time: " << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

    return 0;
}

//BE CAREFUL: IS INT REALLY INT?

template<typename T>
T binpow(T q, T w, T mod) {
    if (!w)
        return 1 % mod;
    if (w & 1)
        return q * 1LL * binpow(q, w - 1, mod) % mod;
    return binpow(q * 1LL * q % mod, w / 2, mod);
}

template<typename T>
T gcd(T q, T w) {
    while (w) {
        q %= w;
        swap(q, w);
    }
    return q;
}
template<typename T>
T lcm(T q, T w) {
    return q / gcd(q, w) * w;
}

void precalc() {

}

//#define int li

class Treap {
public:
    typedef struct _node {
        int key;
        int cnt;
        int prior;
        int val;
        _node* l;
        _node* r;
        _node(int key, int val) :key(key), val(val), l(nullptr), r(nullptr), cnt(1) { prior = (rand() << 16) | rand(); }

        void push() {

        }

        void recalc() {
            cnt = 1 + Cnt(l) + Cnt(r);
        }

        static int Cnt(_node* v) {
            if (!v)
                return 0;
            return v->cnt;
        }
    }*node;

    static int Cnt(node v) {
        if (!v)
            return 0;
        return v->cnt;
    }

    node root;

    size_t Size;

    node merge(node l, node r) {
        if (!l)
            return r;
        if (!r)
            return l;
        if (l->prior < r->prior) {
            l->push();
            l->r = merge(l->r, r);
            l->recalc();
            return l;
        }
        else {
            r->push();
            r->l = merge(l, r->l);
            r->recalc();
            return r;
        }
    }

    void split(node v, int key, node& l, node& r) {
        l = r = nullptr;
        if (!v)
            return;
        v->push();
        if (v->key < key) {
            l = v;
            split(l->r, key, l->r, r);
            l->recalc();
        }
        else {
            r = v;
            split(r->l, key, l, r->l);
            r->recalc();
        }
    }

    void splitCnt(node v, int key, node& l, node& r) {
        l = r = nullptr;
        if (!v)
            return;
        v->push();
        int cur_cnt = Cnt(v->l) + 1;
        if (key >= cur_cnt) {
            l = v;
            splitCnt(l->r, key - cur_cnt, l->r, r);
            l->recalc();
        }
        else {
            r = v;
            splitCnt(r->l, key, l, r->l);
            r->recalc();
        }
    }

public:
    Treap() {
        root = nullptr;
        Size = 0;
    }

    size_t size() const {
        return Size;
    }

    void insert(int key, int val) { //insert at the idx - position
        node l = nullptr, r = nullptr;
        split(root, key, l, r);
        node cur_node = new _node(key, val);
        root = merge(merge(l, cur_node), r);
        ++Size;
    }

    int get_number(int key) {
        node l = nullptr, m = nullptr, r = nullptr;
        splitCnt(root, key, m, r);
        splitCnt(m, key - 1, l, m);
        int ans = m->val;
        root = merge(merge(l, m), r);
        return ans;
    }

};

typedef Treap::node TreapNode;

const int shift = 1 << 17;

struct Node {
    int min;
    int push_add;
    Node(): min(0), push_add(0) {}
    Node(int min): min(min), push_add(0) {}
};

Node tree[2 * shift];

void push(int v) {
    for (int h = 0; h < 2; ++h) {
        tree[2 * v + h].min += tree[v].push_add;
        tree[2 * v + h].push_add += tree[v].push_add;
    }
    tree[v].push_add = 0;
}

Node merge(const Node& l, const Node& r) {
    Node res;
    res.push_add = 0;
    res.min = max(l.min, r.min);
    return res;
}

Node rmq(int v, int tl, int tr, int l, int r) {
    if (tr <= l || r <= tl) {
        return Node(0);
    }
    if (l <= tl && tr <= r) {
        return tree[v];
    }
    push(v);
    int tm = (tl + tr) / 2;
    Node ans = merge(rmq(2 * v, tl, tm, l, r), rmq(2 * v + 1, tm, tr, l, r));
    tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
    return ans;
}


Node get_min(int l, int r) {
    return rmq(1, 0, shift, l, r);
}

void modify(int v, int tl, int tr, int l, int r, int val) {
    if (tr <= l || r <= tl) {
        return;
    }
    if (l <= tl && tr <= r) {
        tree[v].min += val;
        tree[v].push_add += val;
        return;
    }
    push(v);
    int tm = (tl + tr) / 2;
    modify(2 * v, tl, tm, l, r, val);
    modify(2 * v + 1, tm, tr, l, r, val);
    tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
}

void update(int l, int r, int val) {
    return modify(1, 0, shift, l, r, val);
}

void solve(bool read) {
    int n;
    cin >> n;
    vector<int> vals(n);
    for (int i = 0; i < n; ++i) {
        int pos;
        cin >> pos;
        --pos;
        int type;
        cin >> type;
        if (type == 0) {
            update(0, pos + 1, -1);
        }
        else {
            int val;
            cin >> val;
            update(0, pos + 1, 1);
            vals[pos] = val;
        }
        if (get_min(0, n).min <= 0) {
            cout << "-1\n";
            continue;
        }
        int v = 1, l = 0, r = shift;
        while (l + 1 < r) {
            push(v);
            int m = (l + r) / 2;
            if (tree[2 * v + 1].min > 0) {
                l = m;
                v = 2 * v + 1;
            }
            else {
                r = m;
                v = 2 * v;
            }
        }
        cout << vals[l] << "\n";
    }

}