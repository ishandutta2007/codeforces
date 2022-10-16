// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define int long long

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 2e5 + 5, Q = 1e6 + 5;

// 

int n, q, a[N], pos[N];


struct BIT{
    LL c[N];
    void inline init() {
        for (int i = 1; i <= n; i++) {
            c[i] = 0;
        }
    }
    void inline add(int x, LL k) {
        for (; x <= n; x += x & -x) c[x] += k;
    }
    LL inline ask(int x) {
        LL res = 0;
        for (; x; x -= x & -x) res += c[x];
        return res;
    }
} ;

//  
struct exBIT{
    BIT t1, t2;
    void inline init() {
        t1.init();
        t2.init();
    }
    void inline add(int l, int r, LL c) {
        t1.add(l, c), t1.add(r + 1, -c);
        t2.add(l, c * l), t2.add(r + 1, -c * (r + 1));
    }
    LL inline ask(int x) {
        return (x + 1) * t1.ask(x) - t2.ask(x);
    }
    LL inline ask(int x, int y) { return ask(y) - ask(x - 1); }
} t0, t1;


LL ans[Q];

vector<PII> e[N];

vector<int> d[N];

void inline pr(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) d[j].pb(i);
    }
}


int s[N], top;

PII w[N];

void inline clr() {
    t0.init();
    t1.init();
    for (int i = 1; i <= n; i++) e[i].clear(), pos[i] = 0;
    top = 0;
}

void inline Chg(int l, int r, int k, int i) {
   // cout << l << " " << r << "?" << k << " mdzz" << i << endl;
    t0.add(l, r, k);
    t1.add(l, r, k * i);
}

LL inline Query(int l, int r, int i) {
    //cout << t0.ask(l, r) << " " << (i + 1) << " fk" << t1.ask(l, r) << endl;
    return t0.ask(l, r) * (i + 1) - t1.ask(l, r);
}

vector<PII> hp[N];

int loc[N];

void inline work() {
    for (int i = 1; i <= n; i++) {
        while (top && a[s[top]] < a[i]) {
            if (w[top].fi != -1) {
                Chg(w[top].fi, w[top].se, -1, i);
            }
            w[top].fi = w[top].se = -1;
            loc[s[top]] = 0;
            top--;
        }
        int nL = s[top] + 1;
        int R = 0;
        for (int v: d[a[i]]) {
            int A = v;
            int B = a[i] / v;
            if (A == B) continue;
            int val = min(pos[A], pos[B]);
            if (pos[A] < nL || pos[B] < nL) continue;
            if (pos[A] <= i && pos[B] <= i) {
                chkMax(R, val);
            } else {
                int nt = max(pos[A], pos[B]);
                hp[nt].pb(mp(i, min(val, i)));
            }
        }

        s[++top] = i;
        loc[i] = top;
        if (nL <= R) {
            w[top] = mp(nL, R);
           Chg(w[top].fi, w[top].se, 1, i);
        } else w[top] = mp(-1, -1);

        for (PII ut: hp[i]) {
            int u = ut.fi, ba = ut.se;
            if (!loc[u]) continue;
            int p = loc[u];
            int lt = s[p - 1] + 1, rt = u;
            if (w[p].se == u) continue;
            if (w[p].fi != -1) Chg(w[p].fi, w[p].se, -1, i);
            w[p].fi = lt, chkMax(w[p].se, ba);
            Chg(w[p].fi, w[p].se, 1, i);
        }

        for (PII o: e[i]) {
            ans[o.se] = Query(o.fi, i, i);
         //   puts("ov");
        }

    }
}

signed main() {
    read(n), read(q); pr(2e5);
    for (int i = 1; i <= n; i++) read(a[i]), pos[a[i]] = i;
    for (int i = 1; i <= q; i++) {
        int l, r; read(l), read(r);
        e[r].pb(mp(l, i));
    }
    work();
    for (int i = 1; i <= q; i++) printf("%lld\n", ans[i]);
    return 0;
}