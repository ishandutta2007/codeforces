#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const ll X = 1e11;

struct RangeTree {
    struct Node {
        Node* l = nullptr;
        Node* r = nullptr;
        ll s = 0;
        ll pu = 0;
        ll len = 0;
    };

    ll get_sum(Node* v) {
        return v ? v->s : 0;
    }

    Node* get_left(Node* v) {
        return v ? v->l : nullptr;
    }

    Node* get_right(Node* v) {
        return v ? v->r : nullptr;
    }

    void inc(Node* v, ll x) {
        if (!v)
            return;
        v->s += x * v->len;
        v->pu += x;
    }

    void push(Node* v) {
        if (!v || !v->pu)
            return;
        if (!v->l) {
            v->l = new Node();
            v->l->len = (v->len + 1) / 2;
        }
        if (!v->r) {
            v->r = new Node();
            v->r->len = v->len / 2;
        }
        inc(v->l, v->pu);
        inc(v->r, v->pu);
        v->pu = 0;
    }

    void merge(Node* v) {
        if (v)
            v->s = get_sum(v->l) + get_sum(v->r);
    }

    void update(Node*& v, ll tl, ll tr, ll l, ll r, ll x) {
        if (!v) {
            v = new Node();
            v->len = tr - tl + 1;
        }
        if (l <= tl && tr <= r) {
            inc(v, x);
        } else {
            ll tm = (tl + tr) >> 1;
            push(v);
            if (l <= tm)
                update(v->l, tl, tm, l, r, x);
            if (r > tm)
                update(v->r, tm + 1, tr, l, r, x);
            merge(v);
        }
    }

    void update(ll l, ll r, ll x) {
//        cout << "[" << l << " .. " << r << "] " << x << "\n";
        update(root, 0, X, l, r, x);
    }

    Node* root = nullptr;

    ll get_kth(Node* v, ll tl, ll tr, ll k) {
        if (get_sum(v) < k)
            return X + 1;
        if (tl == tr) {
            return tl;
        } else {
            ll tm = (tl + tr) >> 1;
            push(v);
            ll left_sum = get_sum(v->l);
            ll res;
            if (left_sum >= k)
                res = get_kth(v->l, tl, tm, k);
            else
                res = get_kth(v->r, tm + 1, tr, k - left_sum);
            merge(v);
            return res;
        }
    }

    ll get_kth(ll k) {
        ll res = get_kth(root, 0, X, k);
//        cout << "? " << k << " = " << res << "\n";
        return res;
    }
};

ll fast(int n, int k, vector<int> L) {
    RangeTree rt;
    sort(L.rbegin(), L.rend() - 1);
    rt.update(0, 0, +1);
    ll res = X + 1;
    for (int i = 1; i <= n; i++) {
        res = min(res, rt.get_kth(k));
        ll d = rt.get_kth(1);
        rt.update(d, d, -1);
        ll t = L[i] / 2;
        if (L[i] % 2) {
            rt.update(d + 2, d + 2 + t - 1, +1);
            rt.update(d + 2, d + 2 + t - 1, +1);
        } else {
            rt.update(d + 2, d + 2 + t - 2, +1);
            rt.update(d + 2, d + 2 + t - 1, +1);
        }
    }
    res = min(res, rt.get_kth(k));
    if (res == X + 1)
        res = -1;
    return res;
}

void work() {
    int n, k;
    vector<int> l;

    cin >> n >> k;
    l.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> l[i];

    ll fs = fast(n, k, l);

    cout << fs << "\n";
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();

    return 0;
}