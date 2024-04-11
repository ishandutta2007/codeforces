#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 1<<18;
const int MAXLG = 18;

int n, p[MAXN], l[MAXN], tree[2*MAXN];
pii jump[MAXN][MAXLG];

void update(int cur, int lt, int rt, int p, int v) {
    if (lt + 1 == rt) tree[cur] = v;
    else {
        int mid = (lt + rt) / 2;
        if (p < mid) update(2*cur, lt, mid, p, v);
        else update(2*cur+1, mid, rt, p, v);
        tree[cur] = max(tree[2*cur], tree[2*cur+1]);
    }
}

int query(int cur, int lt, int rt, int ql, int qr) {
    if (rt <= ql || lt >= qr) return 0;
    else if (lt >= ql && rt <= qr) return tree[cur];
    else {
        int mid = (lt + rt) / 2;
        return max(query(2*cur, lt, mid, ql, qr), query(2*cur+1, mid, rt, ql, qr));
    }
}

void init() {
    for (int i=n-1; i>=0; i--) {
        int x = p[i]+l[i];
        int ind = upper_bound(p, p+n, x)-p;
        jump[i][0] = pii(max(x, query(1, 0, n, i+1, ind)), 0);
        update(1, 0, n, i, jump[i][0].first);
    }

    for (int k=0; k<MAXLG-1; k++)
        for (int i=0; i<n; i++) {
            int x = jump[i][k].first;
            int ind = upper_bound(p, p+n, x)-p;
            if (ind == n) jump[i][k+1] = jump[i][k];
            else jump[i][k+1] = pii(jump[ind][k].first, jump[i][k].second+jump[ind][k].second+p[ind]-x);
        }
}

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n; i++) cin >> p[i] >> l[i];
    init();

    int q; cin >> q;
    for (int i=0; i<q; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        int ans = 0;
        for (int k=MAXLG-1; k>=0; k--)
            if (jump[x][k].first < p[y]) {
                int d = jump[x][k].first;
                int ind = upper_bound(p, p+n, d)-p;
                ans += jump[x][k].second+p[ind]-d;
                x = ind;
            }
        cout << ans << '\n';
    }
    return 0;
}