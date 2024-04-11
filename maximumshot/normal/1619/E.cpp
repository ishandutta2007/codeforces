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
    vector<ll> res;

    void print() {
        for (auto x : res)
            cout << x << " ";
        cout << "\n";
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
        int prior = GEN();
        ll sm = 0;
        ll mn = 0;
        ll x = 0;
        int cn = 0;
        ll pu = 0;

        Node(int value) {
            sm = value;
            mn = value;
            x = value;
            cn = 1;
        }
    };

    void update(Node* v) {
        if (!v)
            return;
        v->sm = v->mn = v->x;
        v->cn = 1;
        if (v->l) {
            v->sm += v->l->sm;
            v->mn = min(v->mn, v->l->mn);
            v->cn += v->l->cn;
        }
        if (v->r) {
            v->sm += v->r->sm;
            v->mn = min(v->mn, v->r->mn);
            v->cn += v->r->cn;
        }
    }

    void inc(Node* v, int dx) {
        if (!v)
            return;
        v->sm += 1ll * v->cn * dx;
        v->mn += dx;
        v->pu += dx;
        v->x += dx;
    }

    void push(Node* v) {
        if (!v)
            return;
        inc(v->l, v->pu);
        inc(v->r, v->pu);
        v->pu = 0;
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

    int get_cnt(Node* v) {
        return v ? v->cn : 0;
    }

    void split(Node* v, Node*& l, Node*& r, int x) { // <= x elems
        if (!v) {
            l = r = nullptr;
            return;
        }
        push(v);
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

    Node* root = nullptr;
    Node *nl, *nm, *nr;

    Treap() = default;

    Treap(const vector<int>& d) {
        for (auto x : d)
            merge(root, root, new Node(x));
    }

    int erase(int j) {
        nl = nm = nr = nullptr;
        split(root, nl, nr, j + 1);
        split(nl, nl, nm, j);
        merge(root, nl, nr);
        return nm->x;
    }

    ll get_sum() {
        return root ? root->sm : 0;
    }

    int get_size() {
        return root ? root->cn : 0;
    }

    void update(int j, int dx) {
        nl = nm = nr = 0;
        split(root, nl, nr, j);
        inc(nr, dx);
        merge(root, nl, nr);
    }

    int descent(Node* v) {
        if (!v || v->cn == 1)
            return 0;
        int res = 0;
        push(v);
        if (v->r && v->r->mn == 0) {
            res = get_cnt(v->l) + 1 + descent(v->r);
        } else if (v->x == 0) {
            res = get_cnt(v->l);
        } else {
            res = descent(v->l);
        }
        update(v);
        return res;
    }

    int get_right_zero() {
        return descent(root);
    }
};

struct input {
    int n;
    vector<int> a;

    input() = default;

    void read() {
        cin >> n;
        a.resize(n);
        for (auto& x : a)
            cin >> x;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    bool check(int mex) {
        mex--;
        int ptr = 0;
        while (ptr < n && a[ptr] <= mex) ptr++;
        ptr--;
        while (mex >= 0) {
            while (ptr >= 0 && a[ptr] > mex) ptr--;
            if (ptr < 0)
                return false;
            ptr--;
            mex--;
        }
        return true;
    }

    output fast() {
        sort(a.begin(), a.end());
        int bl = 0, br = n + 2, bm;
        while (br - bl > 1) {
            bm = (bl + br) >> 1;
            if (check(bm)) bl = bm;
            else br = bm;
        }
        int max_mex = bl;
        vector<ll> res(n + 1, 0);
        for (int i = max_mex + 1; i <= n; i++)
            res[i] = -1;
        vector<int> ar, cnt(n + 1);
        for (auto x : a) cnt[x]++;
        int ptr = 0;
        int mex = max_mex;
        while (ptr < n && a[ptr] < max_mex) ptr++; ptr--;
        while (max_mex > 0) {
            while (ptr >= 0 && a[ptr] > max_mex - 1) ptr--;
            ar.push_back(a[ptr]);
            ptr--;
            max_mex--;
        }
        max_mex = mex;
        reverse(ar.begin(), ar.end());
        ll cost = 0;
        for (int i = 0; i < (int) ar.size(); i++) {
            assert(ar[i] <= i);
            cost += i - ar[i];
        }
        vector<int> d(ar.size());
        for (int i = 0; i < (int) ar.size(); i++)
            d[i] = i - ar[i];
        Treap treap(d);
        for (int i = max_mex; i >= 0; i--) {
            res[i] = cost + cnt[i];
            if (i > 0) {
                int j = treap.get_right_zero();
                cost -= treap.erase(j);
                cost -= treap.get_size() - j;
                treap.update(j, -1);
//                int j = (int) d.size() - 1;
//                while (j > 0 && d[j]) j--, cost--;
//                cost -= d[j];
//                for (int q = j; q + 1 < (int) d.size(); q++)
//                    d[q] = d[q + 1];
//                d.pop_back();
//                while (j < (int) d.size())
//                    d[j]--, j++;
            }
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