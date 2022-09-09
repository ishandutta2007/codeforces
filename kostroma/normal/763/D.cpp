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

#define int li

//const int mod = 1000000007;

const int C = 100500;
int pr[2] = {234211, 23423541};
int mods[2] = {1000000007, 1000000009};
int powers[2][C];

class Treap {
public:
    typedef struct _node {
        int key;
        int cnt;
        int prior;
        int val[2];
        _node* l;
        _node* r;
        _node(int key) :key(key), l(nullptr), r(nullptr), cnt(1) { prior = (rand() << 16) | rand(); val[0] = (key + 1); val[1] = (key + 1); }

        void push() {

        }

        void recalc() {
            cnt = 1 + Cnt(l) + Cnt(r);
            for (int w = 0; w < 2; ++w) {
                val[w] = powers[w][Cnt(r)] * (key + 1) % mods[w];
                if (l) {
                    val[w] += powers[w][Cnt(r) + 1] * l->val[w];
                }
                if (r) {
                    val[w] += r->val[w];
                }
                val[w] %= mods[w];
            }
        }

        li get_hash() {
            return (val[0] * 1LL << 32) | val[1];
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
        int lef = Cnt(v->l) + 1;
        if (key >= lef) {
            l = v;
            splitCnt(l->r, key - lef, l->r, r);
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

    void insert(int key) { //insert at the idx - position
        node l = nullptr, r = nullptr;
        split(root, key, l, r);
        ++Size;
        root = merge(merge(l, new _node(key)), r);
    }

    void erase(int key) {
        node l, m, r;
        split(root, key, l, m);
        splitCnt(m, 1, m, r);
        root = merge(l, r);
        --Size;
    }

    li get_hash() {
        if (!root) {
            return 0;
        }
        return root->get_hash();
    }

};

typedef Treap::node Node;

vector<vector<int>> g;

int best_ans = 0;
int best_v = -1;

map<li, int> trees;

map<li, int> cnt;

vector<int> down;

vector<int> subtree;

int dfs1(int v, int p) {
    subtree[v] = 1;
    Treap children;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        int child = dfs1(to, v);
        children.insert(child);
        subtree[v] += subtree[to];
    }
    li cur = children.get_hash() ^ subtree[v];
    if (!trees.count(cur)) {
        int id = (int)trees.size();
        trees[cur] = id;
    }
    cur = trees[cur];
    ++cnt[cur];
    down[v] = cur;
    //cout << v + 1 << " " << down[v] << "\n";
    return cur;
}

vector<vector<li>> hashes;

void dec(int cur) {
    --cnt[cur];
    if (cnt[cur] == 0) {
        cnt.erase(cur);
    }
}

void inc(int cur) {
    ++cnt[cur];
}

int n;

void dfs2(int v, int p, int up) {
    int cand = (int)cnt.size() + 1;
    //cout << v + 1 << " " << cand << "\n";
    if (best_ans < cand || best_ans == cand && v < best_v) {
        best_ans = cand;
        best_v = v;
    }
    Treap cur;
    if (up != -1) {
        cur.insert(up);
    }
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        cur.insert(down[to]);
    }
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        dec(down[to]);
        cur.erase(down[to]);
        int now = cur.get_hash() ^ (n - subtree[to]);
        int id;
        if (!trees.count(now)) {
            id = (int)trees.size();
            trees[now] = id;
        }
        else {
            id = trees[now];
        }
        inc(id);
        dfs2(to, v, id);
        cur.insert(down[to]);
        inc(down[to]);
        dec(id);
    }
}

void solve(bool read) {
    for (int w = 0; w < 2; ++w) {
        powers[w][0] = 1;
        for (int i = 1; i < C; ++i) {
            powers[w][i] = powers[w][i - 1] * pr[w] % mods[w];
        }
    }

    cin >> n;
    g.resize(n);
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    down.resize(n);
    subtree.resize(n);
    dfs1(0, 0);
    hashes.resize(n);

    dec(down[0]);
    dfs2(0, 0, -1);

    cout << best_v + 1 << "\n";
}