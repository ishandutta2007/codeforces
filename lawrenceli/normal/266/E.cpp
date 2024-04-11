#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;

const int MAXN = 1<<17;
const int MOD = 1e9 + 7;

int n, m, ar[MAXN];
ll pre[MAXN][10], tree[2*MAXN][10], lazy[2*MAXN], C[10][10];

ll pow(ll b, ll e) {
    ll ret = 1;
    for (int i=0; i<e; i++) ret = ret*b%MOD;
    return ret;
}

void init(int cur, int lt, int rt) {
    if (lt + 1 == rt) {
        for (int k=0; k<=5; k++)
            tree[cur][k] = ar[lt]*pow(lt+1, k)%MOD;
    } else {
        int mid = (lt + rt) / 2;
        init(2*cur, lt, mid);
        init(2*cur+1, mid, rt);
        for (int k=0; k<=5; k++)
            tree[cur][k] = (tree[2*cur][k] + tree[2*cur+1][k])%MOD;
    }
}

void down(int cur, int lt, int rt) {
    if (lazy[cur] >= 0) {
        for (int k=0; k<=5; k++)
            tree[cur][k] = lazy[cur]*((pre[rt][k]-pre[lt][k]+MOD)%MOD)%MOD;
        if (lt + 1 != rt) {
            lazy[2*cur] = lazy[cur];
            lazy[2*cur+1] = lazy[cur];
        }
        lazy[cur] = -1;
    }
}

void update(int cur, int lt, int rt, int ql, int qr, int x) {
    down(cur, lt, rt);
    if (rt <= ql || lt >= qr) return;
    if (lt >= ql && rt <= qr) {
        lazy[cur] = x;
        down(cur, lt, rt);
    } else {
        int mid = (lt + rt) / 2;
        update(2*cur, lt, mid, ql, qr, x);
        update(2*cur+1, mid, rt, ql, qr, x);
        for (int k=0; k<=5; k++)
            tree[cur][k] = (tree[2*cur][k]+tree[2*cur+1][k])%MOD;
    }
}

ll query(int cur, int lt, int rt, int ql, int qr, int k) {
    if (rt <= ql || lt >= qr) return 0;
    down(cur, lt, rt);
    if (lt >= ql && rt <= qr) return tree[cur][k];
    else {
        int mid = (lt + rt) / 2;
        return (query(2*cur, lt, mid, ql, qr, k)+query(2*cur+1, mid, rt, ql, qr, k))%MOD;
    }
}

int sgn[2] = {1, -1};

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++) scanf("%d", &ar[i]);
    for (int k=0; k<=5; k++)
        for (int i=1; i<=n; i++)
            pre[i][k] = pre[i-1][k] + pow(i, k);
    C[0][0] = 1;
    for (int i=1; i<10; i++) {
        C[i][0] = 1;
        for (int j=1; j<10; j++)
            C[i][j] = (C[i-1][j-1]+C[i-1][j])%MOD;
    }

    init(1, 0, n);
    memset(lazy, -1, sizeof(lazy));
    scanf("\n");

    for (int i=0; i<m; i++) {
        char type;
        int l, r, x;
        scanf("%c %d %d %d\n", &type, &l, &r, &x);
        l--;
        if (type == '=') {
            update(1, 0, n, l, r, x);
        } else {
            ll ans = 0;
            for (int j=0; j<=x; j++)
                ans = (ans+C[x][j]*query(1, 0, n, l, r, j)%MOD*((sgn[(x-j)&1]+MOD)%MOD)%MOD*pow(l, x-j)%MOD)%MOD;
            printf("%I64d\n", ans);
        }
    }
    return 0;
}