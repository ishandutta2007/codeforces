#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define px real()
#define py imag()
#define repi(i, n) for (__typeof((n).begin()) i=(n).begin(), _##i=n.end(); i != _##i; ++i)
#define sz(x) int((x).size())
#define print(x) cerr << #x << ": " << x << endl

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> pnt;

const int MAXN = 1<<18;
const int INF = 1e9;

int n;
char str[10];
int type[MAXN], x[MAXN], y[MAXN];
pii sx[MAXN], sy[MAXN];
int cntx, cnty;
int revx[MAXN], revy[MAXN];
set<pii> bit[MAXN];

void add(int qx, int qy) {
    pii p = pii(qx, qy);
    for (int i=qy+1; i<MAXN; i+=i&-i)
        bit[i].insert(p);
}

void remove(int qx, int qy) {
    pii p = pii(qx, qy);
    for (int i=qy+1; i<MAXN; i+=i&-i)
        bit[i].erase(p);
}

pii max(pii a, pii b) { return a > b ? a : b; }

pii find(int qx, int qy) {
    pii ret = pii(-INF, -INF);
    typeof(bit[0].begin()) it;
    for (int i=qy+1; i>0; i-=i&-i) {
        it = bit[i].upper_bound(pii(qx, qy));
        if (it != bit[i].begin()) {
            it--;
            ret = max(ret, *it);
        }
    }
    return ret;
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    }

    scanf("%d\n", &n);
    for (int i=0; i<n; i++) {
        scanf("%s %d %d\n", str, &x[i], &y[i]);
        if (str[0] == 'a') type[i] = 0;
        else if (str[0] == 'r') type[i] = 1;
        else type[i] = 2;
        x[i] *= -1, y[i] *= -1;
        sx[i] = pii(x[i], i);
        sy[i] = pii(y[i], i);
    }

    sort(sx, sx+n);
    sort(sy, sy+n);
    for (int i=0, j; i<n; i=j) {
        for (j=i; j<n && sx[j].fi == sx[i].fi; j++)
            x[sx[j].se] = cntx;
        revx[cntx] = sx[i].fi;
        cntx++;
    }
    for (int i=0, j; i<n; i=j) {
        for (j=i; j<n && sy[j].fi == sy[i].fi; j++)
            y[sy[j].se] = cnty;
        revy[cnty] = sy[i].fi;
        cnty++;
    }

    for (int i=0; i<n; i++)
        if (type[i] == 0) add(x[i], y[i]);
        else if (type[i] == 1) remove(x[i], y[i]);
        else {
            pii res = find(x[i]-1, y[i]-1);
            if (res.fi == -INF) printf("-1\n");
            else printf("%d %d\n", -revx[res.fi], -revy[res.se]);
        }
    return 0;
}