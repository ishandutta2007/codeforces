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
    vector<ld> res;

    void print() {
        cout.precision(20);
        cout << fixed;
        for (auto x : res)
            cout << x << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct pt {
    ld x = 0;
    ld y = 0;

    pt operator - (const pt& o) const {
        return {x - o.x, y - o.y};
    }

    pt operator + (const pt& o) const {
        return {x + o.x, y + o.y};
    }

    pt& operator += (const pt& o) {
        x += o.x;
        y += o.y;
        return *this;
    }

    pt operator * (ld coef) const {
        return {x * coef, y * coef};
    }

    ld vector_mul(const pt& o) const {
        return x * o.y - o.x * y;
    }

    ld scalar_mul(const pt& o) const {
        return x * o.x + y * o.y;
    }

    ld sqr_norm() const {
        return scalar_mul(*this);
    }

    ld norm() const {
        return sqrtl(max(ld(0), sqr_norm()));
    }

    bool operator < (const pt& o) const {
        ld vm = vector_mul(o);
        if (vm) return vm < 0;
        return sqr_norm() < o.sqr_norm();
    }
};

struct segment {
    pt a;
    pt b;

    pt dir() const {
        return b - a;
    }

    bool operator < (const segment& o) const {
        return dir() < o.dir();
    }
};

mt19937 GEN(42);

struct Treap {
    struct Node {
        Node* l = nullptr;
        Node* r = nullptr;
        int prior = GEN();
        int cn = 1;
        pt x;
        pt sm;
    };
    Node* root = nullptr;
    Node *nl, *nm, *nr;
    pt st;
    Treap() = default;
    Treap(pt st_) {
        raw_insert(pt{st_.x, 0});
        raw_insert(pt{0, -st_.y});
        st.x = 0;
        st.y = st_.y;
    }
    void update(Node* v) {
        if (!v) return;
        v->sm = v->x;
        v->cn = 1;
        if (v->l) v->sm += v->l->sm, v->cn += v->l->cn;
        if (v->r) v->sm += v->r->sm, v->cn += v->r->cn;
    }
    int get_cnt(Node* v) {
        return v ? v->cn : 0;
    }
    void split_by_cnt(Node* v, Node*& l, Node*& r, int x) {
        if (!v) {
            l = r = nullptr;
            return;
        }
        if (get_cnt(v->l) + 1 <= x) {
            split_by_cnt(v->r, v->r, r, x - get_cnt(v->l) - 1);
            l = v;
        } else {
            split_by_cnt(v->l, l, v->l, x);
            r = v;
        }
        update(l);
        update(r);
    }
    void split(Node* v, Node*& l, Node*& r, pt x) {
        if (!v) {
            l = r = nullptr;
            return;
        }
        if (v->x < x) {
            split(v->r, v->r, r, x);
            l = v;
        } else {
            split(v->l, l, v->l, x);
            r = v;
        }
        update(l);
        update(r);
    }
    void merge(Node*& v, Node* l, Node* r) {
        if (!l || !r) {
            v = l ? l : r;
            return;
        }
        if (l->prior < r->prior) {
            merge(l->r, l->r, r);
            v = l;
        } else {
            merge(r->l, l, r->l);
            v = r;
        }
        update(v);
    }
    void raw_insert(pt x) {
        nl = nr = nullptr;
        split(root, nl, nr, x);
        Node* node = new Node{};
        node->x = x;
        node->sm = x;
        node->cn = 1;
        merge(nl, nl, node);
        merge(root, nl, nr);
    }
    void insert(pt vec) {
        raw_insert(vec * 2);
        st += vec * -1;
        while (1) {
            nl = nr = nullptr;
            split_by_cnt(root, nl, nr, 1);
            if ((st + nl->x).x <= 0) {
                st += nl->x;
                root = nr;
            } else {
                ld t = -st.x / nl->x.x;
//                assert(0 <= t && t <= 1);
                st += nl->x * t;
                nl->x = nl->x * (1 - t);
                nl->sm = nl->x;
                merge(root, nl, nr);
                break;
            }
        }
        while (get_cnt(root) > 1) {
            nl = nr = nullptr;
            split_by_cnt(root, nl, nr, get_cnt(root) - 1);
            if ((st + nl->sm).y <= 0) {
                root = nl;
            } else {
                ld t = -(st.y + nl->sm.y) / nr->x.y;
//                assert(0 <= t && t <= 1);
                nr->x = nr->x * t;
                nr->sm = nr->x;
                merge(root, nl, nr);
                break;
            }
        }
        if (get_cnt(root) == 1) {
            ld t = -st.y / root->x.y;
            root->x = root->x * t;
            root->sm = root->x;
        }
    }
    ld query() {
        pt cur = st, last;
        Node* v = root;
        while (v) {
            if (v->l && (cur + v->l->sm).y <= 0) {
                v = v->l;
            } else {
                if (v->l) cur += v->l->sm;
                if ((cur + v->x).y <= 0) {
                    last = v->x;
                    break;
                } else {
                    cur += v->x;
                    v = v->r;
                }
            }
        }
        if ((cur + last).y >= 0) return (cur + last).x;
        // (cur + t * last).y == 0
        // t = -cur.y / last.y
//        cout << "last = " << last.x << " " << last.y << "\n";
        ld t = ld(-cur.y) / ld(last.y);
        ld x = cur.x + t * last.x;
        return x;
    }
    void dfs(Node* v) {
        if (!v) return;
        dfs(v->l);
        cout << "\t" << v->x.x << " " << v->x.y << "\n";
        dfs(v->r);
    }
    void show() {
        cout << "Treap\n";
        cout << "start = " << st.x << " " << st.y << "\n";
        dfs(root);
    }
};

struct input {
    int n;
    pt start;
    vector<pt> a;

    input() = default;

    void read() {
        cin >> n;
        cin >> start.x >> start.y;
        a.resize(n);
        for (auto& p : a) cin >> p.x;
        for (auto& p : a) cin >> p.y, p.y = -p.y;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        vector<ld> res;
        res.reserve(n);
        Treap treap(start);
        for (auto p : a) {
            treap.insert(p);
//            treap.show();
            ld tmp = treap.query();
//            cout << "query = " << tmp << "\n";
            res.push_back(tmp);
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
//#ifdef DEBUG
    cin >> t;
//#endif
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