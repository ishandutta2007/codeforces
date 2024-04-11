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
typedef pair<pii, int> piii;

const int MAXN = 1<<18;
const ll INF = 1e18;

int n, m, a[MAXN];
ll p[MAXN], tree[2*MAXN], lazy[2*MAXN], ans;
piii ar[MAXN];

void init(int cur, int lt, int rt) {
    if (lt + 1 == rt) tree[cur] = p[lt];
    else {
        int mid = (lt + rt) / 2;
        init(2*cur, lt, mid);
        init(2*cur+1, mid, rt);
        tree[cur] = max(tree[2*cur], tree[2*cur+1]);
    }
}

void down(int cur, int lt, int rt) {
    if (lazy[cur] != 0) {
        tree[cur] += lazy[cur];
        if (lt + 1 != rt) lazy[2*cur] += lazy[cur], lazy[2*cur+1] += lazy[cur];
        lazy[cur] = 0;
    }
}

void update(int cur, int lt, int rt, int ql, int qr, ll v) {
    down(cur, lt, rt);
    if (rt <= ql || lt >= qr) return;
    if (lt >= ql && rt <= qr) {
        lazy[cur] = v;
        down(cur, lt, rt);
    } else {
        int mid = (lt + rt) / 2;
        update(2*cur, lt, mid, ql, qr, v);
        update(2*cur+1, mid, rt, ql, qr, v);
        tree[cur] = max(tree[2*cur], tree[2*cur+1]);
    }
}

ll query(int cur, int lt, int rt, int ql, int qr) {
    down(cur, lt, rt);
    if (rt <= ql || lt >= qr) return -INF;
    if (lt >= ql && rt <= qr) return tree[cur];
    else {
        int mid = (lt + rt) / 2;
        return max(query(2*cur, lt, mid, ql, qr),
                   query(2*cur+1, mid, rt, ql, qr));
    }
}

bool cmp(piii p1, piii p2) {
    return p1.fi.se < p2.fi.se;
}

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    rep(i, n) {
        cin >> a[i];
        p[i+1] = p[i] + a[i];
    }
    init(1, 0, ++n);

    rep(i, m) cin >> ar[i].fi.fi >> ar[i].fi.se >> ar[i].se;
    sort(ar, ar+m, cmp);

    rep(i, m) {
        int l = ar[i].fi.fi-1, r = ar[i].fi.se, c = ar[i].se;
        if (i == 0) {
            update(1, 0, n, l+1, r+1, -p[r]);
            update(1, 0, n, 0, l+1, -p[r]+c);
        } else {
            int r2 = ar[i-1].fi.se;
            ll ma = query(1, 0, n, 0, r2+1);
            if (l < r2) {
                update(1, 0, n, r2+1, r+1, -p[r]+ma);
                update(1, 0, n, l+1, r2+1, -p[r]+p[r2]);
                update(1, 0, n, 0, l+1, -p[r]+p[r2]+c);
            } else {
                update(1, 0, n, l+1, r+1, -p[r]+ma);
                update(1, 0, n, r2+1, l+1, -p[r]+c+ma);
                update(1, 0, n, 0, r2+1, -p[r]+p[r2]+c);
            }
        }
        ans = max(ans, query(1, 0, n, 0, r+1));
    }

    cout << ans << '\n';
    return 0;
}