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
    ll res;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

mt19937 GEN(42);

struct Treap {
//    vector<int> a;

    struct Node {
        Node* l = nullptr;
        Node* r = nullptr;
        int prior = GEN();
        int cnt = 1;
        int mask = 0;
        int mn = inf;
        int x;

        Node(int xx) {
            x = xx;
            mn = xx;
            mask = 1 << xx;
        }
    };

    void update(Node* v) {
        if (!v)
            return;
        v->cnt = 1;
        v->mask = 1 << v->x;
        v->mn = v->x;
        if (v->l) {
            v->cnt += v->l->cnt;
            v->mask |= v->l->mask;
            v->mn = min(v->mn, v->l->mn);
        }
        if (v->r) {
            v->cnt += v->r->cnt;
            v->mask |= v->r->mask;
            v->mn = min(v->mn, v->r->mn);
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
        return v ? v->cnt : 0;
    }

    void split_by_cnt(Node* v, Node*& l, Node*& r, int x) {
        if (!v) {
            l = r = nullptr;
            return;
        }
        if (get_cnt(v->l) + 1 <= x) {
            split_by_cnt(v->r, v->r, r, x - get_cnt(v->l) - 1);
            l = v;
        }  else {
            split_by_cnt(v->l, l, v->l, x);
            r = v;
        }
        update(l);
        update(r);
    }

    Node* root = nullptr, *nl, *nm, *nr;

    Treap() = default;

    Treap(string s) {
//        for (char c : s)
//            a.push_back(c);
        for (char c : s)
            merge(root, root, new Node(c));
    }

    int get_left_lt(int x) {
//        int pos = 0;
//        while (pos < (int) a.size() && a[pos] >= x)
//            pos++;
//        return pos;
        int res = 0;
        Node* v = root;
        while (v) {
            if (v->l && v->l->mn < x) {
                v = v->l;
            } else if (v->x < x) {
                res += get_cnt(v->l);
                break;
            } else {
                res += get_cnt(v->l) + 1;
                v = v->r;
            }
        }
        return res;
    }

    int get_left_eq(int x) {
//        int pos = 0;
//        while (pos < (int) a.size() && a[pos] != x)
//            pos++;
//        return pos;
        int res = 0;
        Node* v = root;
        while (v) {
            if (v->l && ((1 << x) & v->l->mask)) {
                v = v->l;
            } else if (v->x == x) {
                res += get_cnt(v->l);
                break;
            } else {
                res += get_cnt(v->l) + 1;
                v = v->r;
            }
        }
        return res;
    }

    void erase(int pos) {
//        a.erase(a.begin() + pos);
        nl = nm = nr = nullptr;
        split_by_cnt(root, nl, nr, pos + 1);
        split_by_cnt(nl, nl, nm, pos);
        merge(root, nl, nr);
    }

    int size() {
//        return (int) a.size();
        return get_cnt(root);
    }
};

struct input {
    int n;
    string s, t;

    input() = default;

    void read() {
        cin >> n >> s >> t;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    output fast() {
        if (s < t)
            return output{0};
        {
            string mins = s;
            sort(mins.begin(), mins.end());
            if (mins >= t)
                return output{-1};
        }
        if (s == t)
            return output{1};
        Treap treap(s);
        ll res = inf64, cur = 0;
        for (int lcp = 0; lcp < n; lcp++) {
            int pos = treap.get_left_lt(t[lcp]);
            if (pos < treap.size()) {
                res = min(res, cur + pos);
            }
            pos = treap.get_left_eq(t[lcp]);
            if (pos == treap.size())
                break;
            cur += pos;
            treap.erase(pos);
        }
        return output{res};
    }

    output slow() {
        return output();
    }
};

void test_case() {
    input in;
    in.read();
    output res = in.fast();
    res.print();
}

void work() {
    int t;
    cin >> t;
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