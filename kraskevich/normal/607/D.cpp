#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const ll MOD = 1000 * 1000 * 1000 + 7;

ll madd(ll a, ll b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}

ll msub(ll a, ll b) {
    a -= b;
    if (a < 0)
        a += MOD;
    return a;
}

ll mmul(ll a, ll b) {
    return a * b % MOD;
}

ll bin_pow(ll x, ll n) {
    ll res = 1;
    for (; n > 0; n /= 2) {
        if (n & 1)
            res = mmul(res, x);
        x = mmul(x, x);
    }
    return res;
}

ll inv(ll x) {
    ll res = bin_pow(x, MOD - 2);
    assert (mmul(res, x) == 1);
    return res;
}

ll mdiv(ll a, ll b) {
    return mmul(a, inv(b));
}

typedef pair<ll, ll> pll;

struct Tree {
    vector<pll> t;
    vector<ll> add;
    int size;

    Tree(int n): t(4 * n + 10), add(4 * n + 10, 1), size(n) {}

    void push(int i) {
        t[i].first = mmul(t[i].first, add[i]);
        t[i].second = mmul(t[i].second, add[i]);
        if (2 * i + 2 < (int)t.size()) {
            add[2 * i + 1] = mmul(add[2 * i + 1], add[i]);
            add[2 * i + 2] = mmul(add[2 * i + 2], add[i]);
        }
        add[i] = 1;
    }

    void put(int i, int tl, int tr, int pos, pll val) {
        push(i);
        if (tl == tr) {
            t[i] = val;
            return;
        }
        int m = (tl + tr) / 2;
        if (pos <= m)
            put(2 * i + 1, tl, m, pos, val);
        else
            put(2 * i + 2, m + 1, tr, pos, val);
        push(2 * i + 1);
        push(2 * i + 2);
        t[i].first = madd(t[2 * i + 1].first, t[2 * i + 2].first);
        t[i].second = madd(t[2 * i + 1].second, t[2 * i + 2].second);
    }

    void put(int pos, pll val) {
        put(0, 0, size - 1, pos, val);
    }

    pll get(int i, int tl, int tr, int l, int r) {
        push(i);
        if (l == tl && r == tr)
            return t[i];
        int m = (tl + tr) / 2;
        pll sl;
        pll sr;
        if (l <= m)
            sl = get(2 * i + 1, tl, m, l, min(r, m));
        if (r > m)
            sr = get(2 * i + 2, m + 1, tr, max(m + 1, l), r);
        return pll(madd(sl.first, sr.first), madd(sl.second, sr.second));
    }

    pll get(int l, int r) {
        return get(0, 0, size - 1, l, r);
    }

    void upd(int l, int r, ll mul) {
        upd(0, 0, size - 1, l, r, mul);
    }

    void upd(int i, int tl, int tr, int l, int r, ll mul) {
        push(i);
        if (l == tl && r == tr) {
            add[i] = mul;
            return;
        }
        int m = (tl + tr) / 2;
        if (l <= m)
            upd(2 * i + 1, tl, m, l, min(r, m), mul);
        if (r > m)
            upd(2 * i + 2, m + 1, tr, max(m + 1, l), r, mul);
        push(2 * i + 1);
        push(2 * i + 2);
        t[i].first = madd(t[2 * i + 1].first, t[2 * i + 2].first);
        t[i].second = madd(t[2 * i + 1].second, t[2 * i + 2].second); 
    }
};

const int N = 200 * 1000 + 10;

vector<int> g[N];
ll val[N];
int tp[N];
int p[N];
int v[N];
int tin[N];
int tout[N];
int deg[N];
int parent[N];
int timer;

void dfs(int v) {
    tin[v] = timer++;
    for (int to : g[v])
        dfs(to);
    tout[v] = timer++;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int last = 1;
    cin >> val[0];
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> tp[i];
        if (tp[i] == 1) {
            cin >> p[i] >> v[i];
            p[i]--;
            val[last] = v[i];
            g[p[i]].push_back(last);
            parent[last] = p[i];
            p[i] = last;
            last++;
        } else {
            cin >> p[i];
            p[i]--;
        }
    }
    fill(deg, deg + last, 1);
    dfs(0);
    Tree tree(timer);
    tree.put(tin[0], pll(val[0], 1));
    for (int i = 0; i < q; i++) {
        if (tp[i] == 2) {
            ll sum = tree.get(tin[p[i]], tout[p[i]]).first;
            ll path = tree.get(tin[p[i]], tin[p[i]]).second;
            cout << mmul(mdiv(sum, path), deg[p[i]]) << "\n";
        } else {
            int pp = parent[p[i]];
            ll curd = tree.get(tin[pp], tin[pp]).second;
            tree.put(tin[p[i]], pll(mmul(curd, val[p[i]]), curd));
            tree.upd(tin[pp], tout[pp], mdiv(deg[pp] + 1, deg[pp]));
            deg[pp]++;
        }
    }
}