/*
    author:  Maksim1744
    created: 04.09.2022 17:35:28
*/

#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             vector<T>& operator--            (vector<T> &v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T> &v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define SHOW_COLORS
#include "/mnt/c/Libs/tools/print.cpp"
#else
#define show(...) void(0)
#define debugf(fun)   fun
#define debugv(var)   var
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#define OSTREAM(...)    ;
#define OSTREAM0(...)   ;
#endif

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd (ll l, ll r) { return (ll)(rng() % (r - l + 1)) + l; }
ll rnd (ll r)       { return rng() % r; }
ll rnd ()           { return rng(); }
ld rndf()           { return (ld)rng() / (ld)ULLONG_MAX; }
ld rndf(ld l, ld r) { return rndf() * (r - l) + l; }

struct Node {
    Node* l = nullptr;
    Node* r = nullptr;
    Node* p = nullptr;

    bool is_set = false;
    int val = 0;
    int sz = 1;

    Node(int x) : val(x), sz(1) {}

    void push() {
        if (!is_set) return;
        if (l) l->set(val);
        if (r) r->set(val);
        is_set = false;
    }

    void set(int x) {
        is_set = true;
        val = x;
    }

    void update() {
        sz = 1;
        if (l) sz += l->sz;
        if (r) sz += r->sz;
        if (l) l->p = this;
        if (r) r->p = this;
    }
};

Node* merge(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;
    a->push();
    b->push();
    if (rng() % (a->sz + b->sz) < a->sz) {
        a->r = merge(a->r, b);
        a->update();
        return a;
    } else {
        b->l = merge(a, b->l);
        b->update();
        return b;
    }
}

pair<Node*, Node*> split(Node* node, int k) {
    if (!node) return {nullptr, nullptr};
    node->push();
    if (node->val <= k) {
        auto [a, b] = split(node->r, k);
        node->r = a;
        node->update();
        if (b)
            b->p = nullptr;
        return {node, b};
    } else {
        auto [a, b] = split(node->l, k);
        node->l = b;
        node->update();
        if (a)
            a->p = nullptr;
        return {a, node};
    }
}

pair<Node*, Node*> split2(Node* node, int k) {
    if (!node) return {nullptr, nullptr};
    node->push();
    int lefts = 0;
    if (node->l) lefts += node->l->sz;
    if (k >= lefts + 1) {
        auto [a, b] = split2(node->r, k - lefts - 1);
        node->r = a;
        node->update();
        if (b)
            b->p = nullptr;
        return {node, b};
    } else {
        auto [a, b] = split2(node->l, k);
        node->l = b;
        node->update();
        if (a)
            a->p = nullptr;
        return {a, node};
    }
}

int getpos(Node* n) {
    int res = 0;
    if (n->l) res += n->l->sz;
    while (n->p != nullptr) {
        if (n == n->p->r) {
            res++;
            if (n->p->l) res += n->p->l->sz;
        }
        n = n->p;
    }
    return res;
}

void pushto(Node* n) {
    if (!n) return;
    pushto(n->p);
    n->push();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    Node* root = nullptr;
    vector<Node*> nodes(n);
    {
        vector<pair<int, int>> v;
        for (int i = 0; i < n; ++i) {
            v.eb(a[i], i);
        }
        sort(v.begin(), v.end());
        for (auto [x, i] : v) {
            nodes[i] = new Node(x);
            root = merge(root, nodes[i]);
        }
        for (int i = 0; i < n; ++i) {
            assert(getpos(nodes[v[i].second]) == i);
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int k, w;
            cin >> k >> w;
            --k;
            int ind = getpos(nodes[k]);
            auto [L, MR] = split2(root, ind);
            auto [M, R] = split2(MR, 1);
            M->val = w;
            root = merge(L, R);
            tie(L, R) = split(root, w);
            root = merge(merge(L, M), R);
        } else if (t == 2) {
            int k;
            cin >> k;
            --k;
            pushto(nodes[k]);
            cout << nodes[k]->val << '\n';
        } else {
            assert(t == 3);
            int l, r;
            cin >> l >> r;
            int m = (l + r) / 2;
            auto [L, R] = split(root, m);
            auto [L1, L2] = split(L, l - 1);
            auto [R1, R2] = split(R, r);
            if (L2)
                L2->set(l - 1);
            if (R1)
                R1->set(r + 1);
            root = merge(merge(L1, L2), merge(R1, R2));
        }
    }

    return 0;
}