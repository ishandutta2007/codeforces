#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define px real()
#define py imag()
#define repi(i, n) for (__typeof((n).begin()) i=(n).begin(), _##i=n.end(); i != _##i; ++i)
#define sz(x) int((x).size())
#define print(x) cerr << #x << ": " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> pnt;

const int MAXN = 1<<19;
const int MOD = 1e9 + 9;

int a = 276601605, b[2] = {691504013, 308495997};
int n, m, ar[MAXN], pre[MAXN], pw[2][MAXN], pw2[2][MAXN], tree[2][2*MAXN], lazy[2][2*MAXN];

void down(int c, int cur, int lt, int rt) {
    int mid = (lt + rt) / 2;
    if (lazy[c][cur]) {
        tree[c][cur] = (tree[c][cur]+ll(pw2[c][rt-lt])*lazy[c][cur]%MOD)%MOD;
        if (lt + 1 != rt) {
            lazy[c][2*cur] = (lazy[c][2*cur]+lazy[c][cur])%MOD;
            lazy[c][2*cur+1] = (lazy[c][2*cur+1]+ll(lazy[c][cur])*pw[c][mid-lt]%MOD)%MOD;
        }
        lazy[c][cur] = 0;
    }
}

void update(int c, int cur, int lt, int rt, int ql, int qr) {
    down(c, cur, lt, rt);
    if (rt <= ql || lt >= qr) return;
    if (lt >= ql && rt <= qr) {
        lazy[c][cur] = pw[c][lt-ql+1];
        down(c, cur, lt, rt);
    } else {
        int mid = (lt + rt) / 2;
        update(c, 2*cur, lt, mid, ql, qr);
        update(c, 2*cur+1, mid, rt, ql, qr);
        tree[c][cur] = (tree[c][2*cur]+tree[c][2*cur+1])%MOD;
    }
}

int query(int c, int cur, int lt, int rt, int ql, int qr) {
    down(c, cur, lt, rt);
    if (rt <= ql || lt >= qr) return 0;
    if (lt >= ql && rt <= qr) return tree[c][cur];
    else {
        int mid = (lt + rt) / 2;
        return (query(c, 2*cur, lt, mid, ql, qr)+query(c, 2*cur+1, mid, rt, ql, qr))%MOD;
    }
}

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> ar[i];
        pre[i+1] = (pre[i]+ar[i])%MOD;
    }
    for (int i=0; i<2; i++) {
        pw[i][0] = pw2[i][1] = 1;
        for (int j=1; j<MAXN-1; j++) {
            pw[i][j] = ll(pw[i][j-1])*b[i]%MOD;
            pw2[i][j+1] = (pw2[i][j]+pw[i][j])%MOD;
        }
    }

    for (int i=0; i<m; i++) {
        int t, l, r;
        cin >> t >> l >> r;
        l--;
        if (t == 1) {
            update(0, 1, 0, n, l, r);
            update(1, 1, 0, n, l, r);
        } else {
            int ans = (pre[r]-pre[l]+MOD)%MOD;
            ans = (ans+ll(a)*query(0, 1, 0, n, l, r)%MOD)%MOD;
            ans = (ans-ll(a)*query(1, 1, 0, n, l, r)%MOD+MOD)%MOD;
            cout << ans << '\n';
        }
    }
    return 0;
}