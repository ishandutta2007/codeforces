#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1<<18;
const ll INF = 1e18;

int n, m, d[MAXN], h[MAXN];
ll p[MAXN];
pii t[2][2*MAXN];

ll calc(int i, int k) {
    if (i == -1) return -INF;
    if (k == 0) return 2*h[i]+p[i];
    else return 2*h[i]-p[i];
}

pll getp(int i, int k) {
    return pll(calc(i, k), i);
}

pll ar[5];

pii merge(pii p1, pii p2, int k) {
    ar[3] = getp(p1.fi, k);
    ar[1] = getp(p1.se, k);
    ar[2] = getp(p2.fi, k);
    ar[0] = getp(p2.se, k);
    sort(ar, ar+4);
    return pii(ar[3].se, ar[2].se);
}

void init(int cur, int lt, int rt) {
    if (lt + 1 == rt) {
        t[0][cur] = t[1][cur] = pii(lt, -1);
    } else {
        int mid = (lt + rt) / 2;
        init(2*cur, lt, mid);
        init(2*cur+1, mid, rt);
        for (int k=0; k<2; k++)
            t[k][cur] = merge(t[k][2*cur], t[k][2*cur+1], k);
    }
}

pii qry(int cur, int lt, int rt, int ql, int qr, int k) {
    if (rt <= ql || lt >= qr) return pii(-1, -1);
    else if (lt >= ql && rt <= qr) return t[k][cur];
    else {
        int mid = (lt + rt) / 2;
        return merge(qry(2*cur, lt, mid, ql, qr, k),
                     qry(2*cur+1, mid, rt, ql, qr, k), k);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> d[i];
    for (int i=0; i<n; i++) cin >> h[i];
    for (int i=0; i<n; i++) d[i+n] = d[i];
    for (int i=0; i<n; i++) h[i+n] = h[i];
    for (int i=0; i<2*n; i++) p[i+1] = p[i] + d[i];

    init(1, 0, 2*n);
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        pii p1, p2;
        if (a <= b) {
            p1 = qry(1, 0, 2*n, b+1, a+n, 0);
            p2 = qry(1, 0, 2*n, b+1, a+n, 1);
        } else {
            p1 = qry(1, 0, 2*n, b+1, a, 0);
            p2 = qry(1, 0, 2*n, b+1, a, 1);
        }

        if (p1.fi != p2.fi)
            cout << calc(p1.fi, 0) + calc(p2.fi, 1) << '\n';
        else
            cout << max(calc(p1.fi, 0) + calc(p2.se, 1),
                        calc(p1.se, 0) + calc(p2.fi, 1)) << '\n';
    }
}