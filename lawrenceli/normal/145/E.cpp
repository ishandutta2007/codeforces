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

const int MAXN = 1<<20;

int n, m, ar[MAXN];
char str[MAXN];

struct data {
    int ma[2][2];
} tree[2*MAXN];
int lazy[2*MAXN];

void down(int cur, int lt, int rt) {
    if (lazy[cur]) {
        swap(tree[cur].ma[0][0], tree[cur].ma[1][1]);
        swap(tree[cur].ma[0][1], tree[cur].ma[1][0]);
        if (lt + 1 != rt)
            lazy[2*cur] ^= 1, lazy[2*cur+1] ^= 1;
        lazy[cur] = 0;
    }
}

data prop(data d1, data d2) {
    data d = data();

    for (int i1=0; i1<2; i1++)
        for (int j1=i1; j1<2; j1++)
            for (int i2=j1; i2<2; i2++)
                for (int j2=i2; j2<2; j2++)
                    d.ma[i1][j2] = max(d.ma[i1][j2], d1.ma[i1][j1]+d2.ma[i2][j2]);
    for (int i1=0; i1<2; i1++)
        for (int j1=0; j1<=i1; j1++)
            for (int i2=0; i2<=j1; i2++)
                for (int j2=0; j2<=i2; j2++)
                    d.ma[i1][j2] = max(d.ma[i1][j2], d1.ma[i1][j1]+d2.ma[i2][j2]);

    return d;
}

void init(int cur, int lt, int rt) {
    if (lt + 1 == rt) {
        tree[cur].ma[ar[lt]][ar[lt]] = 1;
    } else {
        int mid = (lt + rt) / 2;
        init(2*cur, lt, mid);
        init(2*cur+1, mid, rt);
        tree[cur] = prop(tree[2*cur], tree[2*cur+1]);
    }
}

void update(int cur, int lt, int rt, int ql, int qr) {
    down(cur, lt, rt);
    if (rt <= ql || lt >= qr) return;
    if (lt >= ql && rt <= qr) {
        lazy[cur] = 1;
        down(cur, lt, rt);
    } else {
        int mid = (lt + rt) / 2;
        update(2*cur, lt, mid, ql, qr);
        update(2*cur+1, mid, rt, ql, qr);
        tree[cur] = prop(tree[2*cur], tree[2*cur+1]);
    }
}

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    scanf("%d %d\n", &n, &m);
    gets(str);
    for (int i=0; i<n; i++) {
        if (str[i] == '4') ar[i] = 0;
        else ar[i] = 1;
    }

    init(1, 0, n);
    for (int i=0; i<m; i++) {
        char type[10];
        scanf("%s", &type);
        if (type[0] == 's') {
            int l, r;
            scanf("%d %d\n", &l, &r);
            l--;
            update(1, 0, n, l, r);
        } else {
            scanf("\n");
            int ans = 0;
            printf("%d\n", max(max(tree[1].ma[0][0], tree[1].ma[1][1]), tree[1].ma[0][1]));
        }
    }
    return 0;
}