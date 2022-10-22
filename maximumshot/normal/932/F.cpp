#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

struct line {
    ll k, b;

    line():
        k(inf64), b(inf64)
    { }

    line(ll _k, ll _b):
        k(_k), b(_b)
    { }

    ll get(ll x) {
        return k == inf64 ? inf64 : k * x + b;
    }
};

struct LiChaoTree {

    ll get_mid(ll lx, ll rx) {
        ll mx = lx + rx;
        return mx >= 0 ? mx / 2 : mx / 2 - 1;
    }

    struct Node {
        ll lx, rx;
        line best;
        Node* l;
        Node* r;

        Node():
            lx(-inf), rx(+inf), best(), l(0), r(0)
        { }

        Node(ll _lx, ll _rx):
            lx(_lx), rx(_rx), best(), l(0), r(0)
        { }

        ~Node() {
            if(l) {
                delete l;
            }
            if(r) {
                delete r;
            }
        }
    };

    Node* get_left(Node* v) {
        if(!v->l) {
            v->l = new Node(v->lx, get_mid(v->lx, v->rx));
        }
        return v->l;
    }

    Node* get_right(Node* v) {
        if(!v->r) {
            v->r = new Node(get_mid(v->lx, v->rx) + 1, v->rx);
        }
        return v->r;
    }

    Node* root;
    vec< line > add_list;

    LiChaoTree(): root(new Node())
    { }

    void update(Node* v, line add) {
        ll mx = get_mid(v->lx, v->rx);
        if(add.get(mx) < v->best.get(mx)) {
            std::swap(v->best, add);
        }
        if(v->lx == v->rx) {
            return;
        }
        if(add.get(mx) == v->best.get(mx)) {
            if(add.get(v->lx) < v->best.get(v->lx)) {
                update(get_left(v), add);
            }else {
                update(get_right(v), add);
            }
        }else if(add.get(v->lx) < v->best.get(v->lx)) {
            update(get_left(v), add);
        }else {
            update(get_right(v), add);
        }
    }

    void add_line(line add) {
        add_list.push_back(add);
        update(root, add);
    }

    ll query(Node* v, ll x) {
        if(!v) return inf64;
        ll res = v->best.get(x);
        if(v->lx == v->rx) {
            return res;
        }
        ll mx = get_mid(v->lx, v->rx);
        if(x <= mx) {
            res = min(res, query(v->l, x));
        }else {
            res = min(res, query(v->r, x));
        }
        return res;
    }

    ll query(ll x) {
        return query(root, x);
    }

    ~LiChaoTree() {
        delete root;
    }

    void swap(LiChaoTree& o) {
        std::swap(root, o.root);
        std::swap(add_list, o.add_list);
    }

    int size() const {
        return (int)add_list.size();
    }
};

void merge(LiChaoTree& a, LiChaoTree& b) {
    if(a.size() < b.size()) {
        a.swap(b);
    }
    for(line l : b.add_list) {
        a.add_line(l);
    }
}

const int N = 1e5 + 5;

int n;
int a[N];
int b[N];
vec< int > g[N];
LiChaoTree t[N];
ll dp[N];

void dfs(int v, int par = -1) {
    for(int to : g[v]) {
        if(to == par) continue;
        dfs(to, v);
        merge(t[v], t[to]);
    }
    dp[v] = t[v].query(a[v]);
    if(dp[v] == inf64) dp[v] = 0;
    t[v].add_line(line(b[v], dp[v]));
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
        dp[i] = inf64;
    }

    for(int i = 1;i <= n;i++) {
        scanf("%d", &b[i]);
    }

    for(int u, v, i = 1;i < n;i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);

    for(int v = 1;v <= n;v++) {
#ifdef debug
        printf("%lld ", dp[v]);
#else
        printf("%I64d ", dp[v]);
#endif
    }

    puts("");

    return 0;
}