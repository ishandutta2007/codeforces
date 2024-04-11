#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector
#define deb(x) cerr << #x << " = " << x << '\n';

typedef unsigned long long ull;
typedef long double LD;
typedef long long LL;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf + 7;
const LL MOD = inf + 9;
const double pi = acos(-1.0);

using namespace std;

template<typename T, typename P>
const ostream & operator << (ostream & os, const pair<T, P> & a) {
    os.precision(10);
    os << fixed;
    os << a.first;
    os << ' ';
    os << a.second;
    os << ' ';
    return os;
}


vec<int> a;

vec< vec<int> > t;
vec<int> delt;

const int LOG = 60;

void merge(int v) {
    for(int i(0);i < LOG;i++) t[v][i] = t[v << 1][i] + t[v << 1 | 1][i];
    delt[v] = 0;
}

void build(int v, int tl, int tr) {
    if(tl == tr) {
        for(int j(0);j < LOG;j++) {
            if((1ll << j) & (LL)a[tl]) {
                t[v][j]++;
            }
        }
        delt[v] = 0;
    }else {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
        merge(v);
    }
}

void push(int v, int tl, int tr) {
    if(delt[v]) {
        int tm = (tl + tr) >> 1;
        delt[v << 1] ^= delt[v];
        delt[v << 1 | 1] ^= delt[v];
        for(int i(0);i < LOG;i++) {
            if((1ll << i) & (LL)delt[v]) {
                t[v << 1][i] = tm - tl + 1 - t[v << 1][i];
                t[v << 1 | 1][i] = tr - tm - t[v << 1 | 1][i];
            }
        }
        delt[v] = 0;
    }
}

LL sum(int v, int tl, int tr, int l, int r) {
    if(l <= tl && tr <= r) {
        LL ans = 0;
        for(int i(0);i < LOG;i++) {
            LL x = (1ll << i);
            ans += x * (LL)t[v][i];
        }
        return ans;
    }else {
        int tm = (tl + tr) >> 1;
        push(v, tl, tr);
        LL L, R;
        L = R = 0;
        if(l <= tm) L = sum(v << 1, tl, tm, l, r);
        if(r > tm) R = sum(v << 1 | 1, tm + 1, tr, l, r);
        merge(v);
        return (L + R);
    }
}

void update(int v, int tl, int tr, int l, int r, int x) {
    if(l <= tl && tr <= r) {
        delt[v] ^= x;
        for(int i(0);i < LOG;i++) {
            if((1ll << i) & (LL)x) {
                t[v][i] = tr - tl + 1 - t[v][i];
            }
        }
    }else {
        int tm = (tl + tr) >> 1;
        push(v, tl, tr);
        if(l <= tm) update(v << 1, tl, tm, l, r, x);
        if(r > tm) update(v << 1 | 1, tm + 1, tr, l, r, x);
        merge(v);
    }
}

bool solve()
{
    int n, m;
    scanf("%d", &n);

    a.resize(n + 1);
    for(int i(1);i <= n;i++) {
        scanf("%d", &a[i]);
    }

    t.resize(4 * n, vec<int>(LOG, 0));
    delt.resize(4 * n, 0);

    build(1, 1, n);

    int type, l, r, x;

    scanf("%d", &m);

    for(int i(0);i < m;i++) {
        scanf("%d %d %d", &type, &l, &r);
        if(type == 1) {
            printf("%I64d\n", sum(1, 1, n, l, r));
        }else {
            scanf("%d", &x);
            update(1, 1, n, l, r, x);
        }
    }

    return true;
}   

int main() 
{
    //while(solve());
    solve();
    
    return 0;
}