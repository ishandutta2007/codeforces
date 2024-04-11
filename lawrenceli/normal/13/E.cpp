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

const int MAXN = 100100;

int n, m, ar[MAXN];
int c[MAXN][2], p[MAXN];
int s[MAXN];

bool d(int x) { return x == c[p[x]][1]; }
bool isroot(int x) { return !p[x] || x != c[p[x]][d(x)]; }
int sze(int x) { return x ? s[x] : 0; }

void update(int x) {
    s[x] = s[c[x][0]]+s[c[x][1]]+1;
}

void join(int x, int y, bool b) {
    p[x] = y;
    c[y][b] = x;
}

void rotate(int x) {
    bool b = d(x);
    int pa = p[x];
    int gp = p[p[x]];
    int ch = c[x][!b];
    if (!isroot(pa)) join(x, gp, d(pa));
    else p[x] = gp;
    join(pa, x, !b);
    join(ch, pa, b);
    update(pa), update(x);
}

void splay(int x) {
    while (!isroot(x)) {
        if (!isroot(p[x])) {
            if (d(x) == d(p[x])) rotate(p[x]);
            else rotate(x);
        }
        rotate(x);
    }
}

void access(int x) {
    int last = 0;
    for (int y=x; y; y=p[y]) {
        splay(y);
        c[y][1] = last;
        last = y;
        update(y);
    }
    splay(x);
}

void link(int x, int y) {
    access(x);
    assert(isroot(x));
    p[x] = y;
}

void cut(int x, int y) {
    access(x);
    access(y);
    assert(p[x] == y);
    p[x] = 0;
}

pii query(int x) {
    access(x);
    pii ret = pii(0, sze(c[x][0])+1);
    while (c[x][0]) x = c[x][0];
    ret.fi = x;
    return ret;
}

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; i++) {
        scanf("%d", &ar[i]);
        s[i] = 1;
    }
    for (int i=1; i<=n; i++)
        if (i+ar[i] <= n)
            link(i, i+ar[i]);

    rep(i, m) {
        /*
        cout << i << endl;
        for (int j=1; j<=n; j++) cout << p[j] << ' ';
        cout << endl;
        for (int j=1; j<=n; j++) cout << c[j][0] << ' ';
        cout << endl;
        for (int j=1; j<=n; j++) cout << c[j][1] << ' ';
        cout << endl;
        */

        int t; scanf("%d", &t);
        if (t == 0) {
            int a, b;
            scanf("%d %d", &a, &b);
            if (a+ar[a] <= n) cut(a, a+ar[a]);
            ar[a] = b;
            if (a+ar[a] <= n) link(a, a+ar[a]);
        } else {
            int a;
            scanf("%d", &a);
            pii ans = query(a);
            printf("%d %d\n", ans.fi, ans.se);
        }
    }
    return 0;
}