#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define px real()
#define py imag()
#define rep(i, n) for (int i=0, _##i=(n); i<_##i; ++i)
#define repi(i, n) for (__typeof((n).begin()) i=(n).begin(), _##i=n.end(); i != _##i; ++i)
#define sz(x) int((x).size())
#define print(x) cerr << #x << ": " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> pnt;

const int MAXN = 1<<17;

int n, q, a[MAXN], b[MAXN], ans[MAXN];

struct data {
    int l, r, t, i;
    bool operator<(const data& d) const {
        return t < d.t;
    }
} qar[MAXN];

struct line {
    int a, b, i;
    line() {}
    line(int _a, int _b, int _i) : a(_a), b(_b), i(_i) {}
    ll val(int t) { return a+ll(b)*t; }
};

deque<line> tree[2*MAXN];

bool cmp(line l1, line l2) {
    return l1.b < l2.b;
}

void init(int cur, int lt, int rt) {
    vector<line> v (rt-lt);
    rep(i, sz(v)) v[i] = line(a[lt+i], b[lt+i], lt+i+1);
    sort(v.begin(), v.end(), cmp);
    rep(i, sz(v)) {
        line l = v[i];
        while (sz(tree[cur]) >= 2) {
            line l1 = tree[cur][sz(tree[cur])-2], l2 = tree[cur][sz(tree[cur])-1];
            if (ll(l1.a-l.a)*(l2.b-l1.b) <= ll(l1.a-l2.a)*(l.b-l1.b))
                tree[cur].pop_back();
            else break;
        }
        tree[cur].push_back(l);
    }

    if (lt + 1 != rt) {
        int mid = (lt + rt) / 2;
        init(2*cur, lt, mid);
        init(2*cur+1, mid, rt);
    }
}

pll query(int cur, int lt, int rt, int ql, int qr, int t) {
    if (rt <= ql || lt >= qr) return pll(0, 0);
    if (lt >= ql && rt <= qr) {
        while (sz(tree[cur]) >= 2) {
            if (tree[cur][0].val(t) <= tree[cur][1].val(t))
                tree[cur].pop_front();
            else break;
        }
        return pll(tree[cur][0].i, tree[cur][0].val(t));
    } else {
        int mid = (lt + rt) / 2;
        pll p1 = query(2*cur, lt, mid, ql, qr, t);
        pll p2 = query(2*cur+1, mid, rt, ql, qr, t);
        return p1.se > p2.se ? p1 : p2;
    }
}

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> q;
    rep(i, n) cin >> a[i] >> b[i];
    init(1, 0, n);
    rep(i, q) {
        cin >> qar[i].l >> qar[i].r >> qar[i].t;
        qar[i].l--;
        qar[i].i = i;
    }
    sort(qar, qar+q);
    rep(i, q)
        ans[qar[i].i] = query(1, 0, n, qar[i].l, qar[i].r, qar[i].t).fi;

    rep(i, q)
        cout << ans[i] << '\n';
    return 0;
}