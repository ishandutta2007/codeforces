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
        return res == o.res;
    }
};

mt19937 GEN(42);

struct input {
    int n, q;
    vector<int> p;

    struct Query {
        int t, x, y;
    };

    vector<Query> qs;

    struct Node {
        Node* l = nullptr;
        Node* r = nullptr;
        Node* p = nullptr;
        int prior = GEN();
        int cn = 1;
        int x;

        Node(int x_) {
            x = x_;
        }
    };

    void update(Node* v) {
        if (!v)
            return;
        v->cn = 1;
        v->p = nullptr;
        if (v->l) {
            v->cn += v->l->cn;
            v->l->p = v;
        }
        if (v->r) {
            v->cn += v->r->cn;
            v->r->p = v;
        }
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

    int get_cnt(Node* v) {
        return v ? v->cn : 0;
    }

    void split(Node* v, Node*& l, Node*& r, int x) { // <= x elems
        if (!v) {
            l = r = nullptr;
            return;
        }
        if (get_cnt(v->l) + 1 <= x) {
            split(v->r, v->r, r, x - get_cnt(v->l) - 1);
            l = v;
        } else {
            split(v->l, l, v->l, x);
            r = v;
        }
        update(l);
        update(r);
    }

    pair<Node*, int> get_pos(Node* v) {
        if (!v) exit(0);
        int pos = get_cnt(v->l);
        while (v->p) {
            if (v->p->r == v)
                pos += get_cnt(v->p->l) + 1;
            v = v->p;
        }
        return {v, pos};
    }

    int get(Node* root, int pos) {
        if (!root) exit(0);
        if (get_cnt(root->l) == pos)
            return root->x;
        if (get_cnt(root->l) < pos)
            return get(root->r, pos - get_cnt(root->l) - 1);
        else
            return get(root->l, pos);
    }

    input() = default;

    void read() {
        cin >> n >> q;
        p.resize(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> p[i];
        qs.resize(q);
        for (auto& Q : qs)
            cin >> Q.t >> Q.x >> Q.y;
    }

    Node *nl, *nm, *nr;

    void move_to_end(Node* root, int pos) {
        nl = nm = nr = nullptr;
        if (pos < 0 || pos >= get_cnt(root))
            exit(0);
        split(root, nl, nr, pos + 1);
        merge(root, nr, nl);
    }

    void print() {
        cout << n << " " << q << "\n";
        for (int i = 1; i <= n; i++) {
            cout << p[i] << " ";
        }
        cout << "\n";
        for (auto Q : qs) {
            cout << Q.t << " " << Q.x << " " << Q.y << "\n";
        }
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 20;
        n = rnd() % MAXN + 1;
        p.resize(n  + 1);
        iota(p.begin(), p.end(), 0);
        shuffle(p.begin() + 1, p.end(), rnd);
        q = rnd() % (20 * MAXN) + 1;
        qs.resize(q);
        for (auto& Q : qs) {
            Q.t = rnd() % 2 + 1;
            Q.x = rnd() % n + 1;
            if (n == 1) Q.t = 2;
            if (Q.t == 1) {
                while (1) {
                    Q.y = rnd() % n + 1;
                    if (Q.x != Q.y) break;
                }
            } else {
                Q.y = rnd() % n + 1;
            }
        }
    }

    output fast() {
        vector<int> res;
        vector<Node*> nodes(n + 1);
        for (int i = 1; i <= n; i++) {
            nodes[i] = new Node(i);
        }
        vector<int> used(n + 1);
        for (int i = 1; i <= n; i++) {
            if (used[i])
                continue;
            Node* mrg = nullptr;
            for (int j = i; !used[j]; j = p[j]) {
                used[j] = 1;
                merge(mrg, mrg, nodes[j]);
            }
        }
        for (auto Q : qs) {
            if (Q.t == 1) {

                pair<Node*, int> info_x = get_pos(nodes[Q.x]);
                pair<Node*, int> info_y = get_pos(nodes[Q.y]);

                if (info_x.first == info_y.first) {
                    move_to_end(info_x.first, info_x.second);
                    info_y = get_pos(nodes[Q.y]);
                    nl = nr = nullptr;
                    split(info_y.first, nl, nr, info_y.second + 1);
                } else {
                    move_to_end(info_x.first, info_x.second);
                    move_to_end(info_y.first, info_y.second);
                    info_x = get_pos(nodes[Q.x]);
                    info_y = get_pos(nodes[Q.y]);
                    nm = nullptr;
                    merge(nm, info_x.first, info_y.first);
                }

                swap(p[Q.x], p[Q.y]);
            } else {
                pair<Node*, int> info_x = get_pos(nodes[Q.x]);
                int sz = get_cnt(info_x.first);
                if (sz <= 0)
                    exit(0);
                int pos = (info_x.second + Q.y) % sz;
                res.push_back(get(info_x.first, pos));
            }
        }

        return output{res};
    }

    output slow() {
        vector<int> res;
        for (auto Q : qs) {
            if (Q.t == 1) {
                swap(p[Q.x], p[Q.y]);
            } else {
                int x = Q.x;
                for (int it = 0; it < Q.y; it++)
                    x = p[x];
                res.push_back(x);
            }
        }
        return output{res};
    }
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

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();
//    test();

    return 0;
}