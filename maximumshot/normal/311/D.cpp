#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int , int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const mod = 95542721;

inline int sum(ll a, ll b) { return (a % mod + mod + b % mod + mod) % mod; }
inline int raz(ll a, ll b) { return (a % mod - b % mod + mod) % mod; }
inline int mul(ll a, ll b) { return (a % mod) * (b % mod) % mod; }

int f(int n) {
    int nn = n;
    int tot = 0;
    while(!tot || (n != nn)) {
        tot++;
        n = mul(n, mul(n, n));
    }
    return tot;
}

int lcm(int x, int y) {
    return (x / __gcd(x, y)) * y;
}

int n, L;
vec< int > a, delt;
vec< vec< int > > t;

void up(int v) {
    for(int i = 0;i < L;i++) {
        t[v][i] = sum(t[v << 1][(i + delt[v << 1]) % L], t[v << 1 | 1][(i + delt[v << 1 | 1]) % L]);
    }
}

void push(int v) {
    if(delt[v]) {
        delt[v << 1] += delt[v];
        delt[v << 1 | 1] += delt[v];
        delt[v] = 0;
    }
}

void build(int v, int tl, int tr) {
    if(tl == tr) {
        delt[v] = 0;
        t[v][0] = a[tl];
        for(int i = 1;i < L;i++) {
            t[v][i] = mul(t[v][i - 1], mul(t[v][i - 1], t[v][i - 1]));
        }
    }else {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
        up(v);
    }
}

void upd(int v, int tl, int tr, int l, int r) {
    if(l <= tl && tr <= r) {
        delt[v]++;
    }else {
        int tm = (tl + tr) >> 1;
        push(v);
        if(l <= tm) upd(v << 1, tl, tm, l, r);
        if(r > tm) upd(v << 1 | 1, tm + 1, tr, l, r);
        up(v);
    }
}

int get(int v, int tl, int tr, int l, int r) {
    if(l <= tl && tr <= r) {
        return t[v][delt[v] % L];
    }else {
        int tm = (tl + tr) >> 1, res = 0;
        push(v);
        if(l <= tm) res = sum(res, get(v << 1, tl, tm, l, r));
        if(r > tm) res = sum(res, get(v << 1 | 1, tm + 1, tr, l, r));
        up(v);
        return res;
    }
}

bool solve() {

    scanf("%d", &n);

    L = 1;

    a.resize(n + 1);
    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
        a[i] %= mod;
    }

    L = 48;

    t.resize(4 * n, vec< int >(L));
    delt.resize(4 * n);

    build(1, 1, n);

    int q;

    scanf("%d", &q);

    for(int ty, l, r, i = 0;i < q;i++) {
        scanf("%d %d %d", &ty, &l, &r);
        if(ty == 1) printf("%d\n", get(1, 1, n, l, r));
        else upd(1, 1, n, l, r);
    }

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}