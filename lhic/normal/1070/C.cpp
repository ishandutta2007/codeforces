#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
using ull = uint64_t;

using namespace std;

const ll INF = 1e18;

struct Node {
    int sm;
    pair<ll, int> mv;

    Node()
        : sm(0)
        , mv(INF, -1)
    {
    }
};

Node merge(const Node& l, const Node& r) {
    Node a;
    a.sm = l.sm + r.sm;
    a.mv = min(l.mv, r.mv);
    return a;
}

const int MX = 1000 * 1000 + 7;

Node t[4 * MX];
ll mod[4 * MX];

Node getv(int v) {
    Node ans = t[v];
    ans.mv.first += mod[v];
    return ans;
}

void pop(int v) {
    t[v] = merge(getv(v + v), getv(v + v + 1));
}

void build(int v, int tl, int tr, int k) {
    if (tl == tr) {
        t[v].sm = 1;
        t[v].mv = make_pair(k, tl);
    } else {
        int tm = (tl + tr) >> 1;
        build(v + v, tl, tm, k);
        build(v + v + 1, tm + 1, tr, k);
        pop(v);
    }
}

void push(int v) {
    mod[v + v] += mod[v];
    mod[v + v + 1] += mod[v];
    mod[v] = 0;
}

void add(int v, int tl, int tr, int l, int r, ll x) {
    if (r < tl || l > tr) {
        return;
    } else if (tl >= l && tr <= r) {
        mod[v] += x;
    } else {
        push(v);
        int tm = (tl + tr) >> 1;
        add(v + v, tl, tm, l, r, x);
        add(v + v + 1, tm + 1, tr, l, r, x);
        pop(v);
    }
}

void off(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        t[v].sm = 0;
        t[v].mv = make_pair(INF, -1);
    } else {
        int tm = (tl + tr) >> 1;
        push(v);
        if (pos <= tm) {
            off(v + v, tl, tm, pos);
        } else {
            off(v + v + 1, tm + 1, tr, pos);
        }
        pop(v);
    }
}

Node get(int v, int tl, int tr, int l, int r) {
    if (r < tl || l > tr) {
        return Node();
    } else if (tl >= l && tr <= r) {
        return getv(v);
    } else {
        push(v);
        int tm = (tl + tr) >> 1;
        Node ans = merge(get(v + v, tl, tm, l, r), get(v + v + 1, tm + 1, tr, l, r));
        pop(v);
        return ans;
    }
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
    int n, k, m;
    cin >> n >> k >> m;
    build(1, 1, n, k);
    vector<tuple<int, int, int, int> > a;
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        int l, r, c, p;
        cin >> l >> r >> c >> p;
        a.emplace_back(p, l, r, c);
    }
    sort(a.begin(), a.end());
    for (const auto& v : a) {
        int l, r, p, c;
        tie(p, l, r, c) = v;
        while (true) {
            Node x = get(1, 1, n, l, r);
            if (x.mv.first <= c) {
                ans += 1ll * p * x.mv.first;
                off(1, 1, n, x.mv.second);
            } else {
                ans += 1ll * p * c * x.sm;
                add(1, 1, n, l, r, -c);
                break;
            }
        }
    }
    cout << ans << "\n";
	return 0;
}