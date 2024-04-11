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

const int MAXN = 5005;

int n, a[MAXN], tree[4*MAXN], dp[MAXN][MAXN];

int getmin(int x, int y) { return x == -1 ? y : y == -1 ? x : a[x]<a[y] ? x : y; }

void init(int cur, int lt, int rt) {
    if (lt + 1 == rt) tree[cur] = lt;
    else {
        int mid = (lt + rt) / 2;
        init(2*cur, lt, mid);
        init(2*cur+1, mid, rt);
        tree[cur] = getmin(tree[2*cur], tree[2*cur+1]);
    }
}

int query(int ql, int qr, int cur=1, int lt=0, int rt=n) {
    if (rt <= ql || lt >= qr) return -1;
    if (lt >= ql && rt <= qr) return tree[cur];
    else {
        int mid = (lt + rt) / 2;
        return getmin(query(ql, qr, 2*cur, lt, mid),
                      query(ql, qr, 2*cur+1, mid, rt));
    }
}

int calc(int l, int r, int k=0) {
    if (l >= r) return 0;
    int& ret = dp[l][r];
    if (ret != -1) return ret;
    int x = query(l, r);
    return ret = min(r-l, calc(l, x, a[x])+calc(x+1, r, a[x])+a[x]-k);
}

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    rep(i, n) cin >> a[i];
    memset(dp, -1, sizeof(dp));
    init(1, 0, n);
    cout << calc(0, n) << '\n';
    return 0;
}