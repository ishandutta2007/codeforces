#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ui = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

const int inf = 1e9;
const ll inf64 = 1e18;

struct output {
    vector<int> res;

    void print() {
        for (auto x : res)
            cout << x << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

mt19937 GEN(42);

struct Treap {

    struct Node {
        Node* l = nullptr;
        Node* r = nullptr;
        Node* p = nullptr;
        int x = 0;
        int sz = 1;
        int prior = GEN();
        int pu = -1;
    };

    int get_sz(Node* v) {
        return v ? v->sz : 0;
    }

    void upd(Node* v, int x) {
        if (!v) return;
        v->x = x;
        v->pu = x;
    }

    void push(Node* v) {
        if (!v || v->pu == -1) return;
        upd(v->l, v->pu);
        upd(v->r, v->pu);
        v->pu = -1;
    }

    void update(Node*& v) {
        if (!v) return;
        v->sz = 1;
        if (v->l) {
            v->sz += v->l->sz;
            v->l->p = v;
        }
        if (v->r) {
            v->sz += v->r->sz;
            v->r->p = v;
        }
    }

    void merge(Node*& v, Node* l, Node* r) {
        if (!l || !r) {
            v = l ? l : r;
            return;
        }
        push(l);
        push(r);
        if (l->prior < r->prior) {
            merge(l->r, l->r, r);
            v = l;
        } else {
            merge(r->l, l, r->l);
            v = r;
        }
        update(v);
    }

    // <= x | > x
    void split_by_value(Node* v, Node*& l, Node*& r, int x) {
        if (!v) {
            l = r = nullptr;
            return;
        }
        push(v);
        if (v->x <= x) {
            split_by_value(v->r, v->r, r, x);
            l = v;
        } else {
            split_by_value(v->l, l, v->l, x);
            r = v;
        }
        update(l);
        update(r);
    }

    void split_by_sz(Node* v, Node*& l, Node*& r, int x) {
        if (!v) {
            l = r = nullptr;
            return;
        }
        push(v);
        if (get_sz(v->l) + 1 <= x) {
            split_by_sz(v->r, v->r, r, x - get_sz(v->l) - 1);
            l = v;
        } else {
            split_by_sz(v->l, l, v->l, x);
            r = v;
        }
        update(l);
        update(r);
    }

    int get_pos(Node* v) {
        assert(v);
        int pos = get_sz(v->l);
        while (v->p) {
            if (v->p->r == v) pos += get_sz(v->p->l) + 1;
            v = v->p;
        }
        return pos;
    }

    vector<Node*> nodes;
    Node* root = nullptr;
    Node *nl, *nm, *nm2, *nr;

    Treap() = default;

    Treap(vector<int> a) {
        int n = (int) a.size();
        nodes.resize(n, nullptr);
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node();
            nodes[i]->x = a[i];
        }
        for (int i = 0; i < n; i++)
            insert(i);
    }

    void update(int l, int r) {
        int md = (l + r) / 2;
        nl = nm = nr = nullptr;
        split_by_value(root, nl, nr, r);
        split_by_value(nl, nl, nm, l - 1);
        split_by_value(nm, nm, nm2, md);
        upd(nm, l - 1);
        upd(nm2, r + 1);
        merge(nl, nl, nm);
        merge(nl, nl, nm2);
        merge(root, nl, nr);
    }

    void erase(int i) {
        int pos = get_pos(nodes[i]);
        nl = nm = nr = nullptr;
        split_by_sz(root, nl, nr, pos + 1);
        split_by_sz(nl, nl, nm, pos);
        merge(root, nl, nr);
    }

    void insert(int i) {
        nl = nr = nullptr;
        split_by_value(root, nl, nr, nodes[i]->x);
        merge(nl, nl, nodes[i]);
        merge(root, nl, nr);
    }

    void set(int pos, int val) {
        erase(pos);
        nodes[pos]->x = val;
        insert(pos);
    }

    int get(int pos) {
        erase(pos);
        int res = nodes[pos]->x;
        insert(pos);
        return res;
    }
};

struct input {
    int n;
    vector<int> a;

    struct Query {
        int t, k, w, l, r;

        void read() {
            cin >> t;
            if (t == 1) {
                cin >> k >> w;
                k--;
            } else if (t == 2) {
                cin >> k;
                k--;
            } else {
                cin >> l >> r;
            }
        }
    };

    int m;
    vector<Query> qs;

    input() = default;

    void read() {
        cin >> n;
        a.resize(n);
        for (auto& x : a) cin >> x;
        cin >> m;
        qs.resize(m);
        for (auto& q : qs)
            q.read();
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        Treap tr(a);
        vector<int> res;
        res.reserve(m);
        for (auto q : qs) {
            if (q.t == 1) {
                tr.set(q.k, q.w);
            } else if (q.t == 2) {
                int tmp = tr.get(q.k);
                res.push_back(tmp);
            } else {
                assert(q.t == 3);
                tr.update(q.l, q.r);
            }
        }
        return output{res};
    }

#ifdef DEBUG
    output slow() {
        return output();
    }
#endif
};

void test_case() {
    input in;
    in.read();
    output res = in.fast();
    res.print();
}

void work() {
    int t = 1;
    while (t--)
        test_case();
}

#ifdef DEBUG
void test() {
    for (int t = 1;;t++) {
        input in;
        in.gen();
        input in_fs = in;
        input in_sl = in;
        output fs = in_fs.fast();
        output sl = in_sl.slow();
        if (fs == sl) {
            cout << "OK" << endl;
            fs.print();
            cout << "\n=========" << endl;
        } else {
            cout << "WA " << t << "\n";
            cout << "exp\n";
            sl.print();
            cout << "\n=========\n";
            cout << "fnd\n";
            fs.print();
            cout << "\n=========\n";
            in.print();
            break;
        }
    }
}
#endif

#ifdef DEBUG
void max_test() {
    input in;
    in.gen_max_test();
    input in_fs = in;
    output fs = in_fs.fast();
    fs.print();
}
#endif

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();
//    test();
//    max_test();

    return 0;
}