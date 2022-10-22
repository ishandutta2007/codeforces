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
const LL base = inf * 1000ll + 17;
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
    os << '\n';
    return os;
}

const int LOG = 21;

int n;
vec<int> a, rmq[LOG], lg;
vec<int> t, delt;

void buildRMQ() {
    for(int i(0);i < LOG;i++) {
        rmq[i].resize(n + 1, 2 * inf + 1);
    }

    rmq[0] = a;

    lg.resize(n + 1);
    int q = 0;
    while((1 << q) <= n) q++; q--;
    for(int i(n);i >= 0;i--) {
        if((1 << q) > i) q--;
        lg[i] = q;
    }

    for(int i(1);i < LOG;i++) {
        for(int j(1);j <= n;j++) {
            if(j + (1 << (i - 1)) <= n) {
                rmq[i][j] = min(rmq[i - 1][j], rmq[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
}

int get_min(int l, int r) {
    int LG = lg[r - l + 1];
    int v1 = rmq[LG][l];
    int v2 = rmq[LG][r - (1 << LG) + 1];
    return min(v1, v2);
}

void pushdown(int v) {
    if(delt[v]) {
        delt[v << 1] = max(delt[v << 1], delt[v]);
        delt[v << 1 | 1] = max(delt[v << 1 | 1], delt[v]);
        delt[v] = 0;
    }
}

void update(int v, int tl, int tr, int l, int r, int x) {
    if(l > r) return;
    if(l <= tl && tr <= r) {
        delt[v] = max(delt[v], x);
    }else {
        int tm = (tl + tr) >> 1;
        pushdown(v);
        if(l <= tm) update(v << 1, tl, tm, l, r, x);
        if(r > tm) update(v << 1 | 1, tm + 1, tr, l, r, x);
    }
}

void show(int v, int tl, int tr) {
    if(tl == tr) {
        printf("%d ", delt[v]);
    }else {
        int tm = (tl + tr) >> 1;
        pushdown(v);
        show(v << 1, tl, tm);
        show(v << 1 | 1, tm + 1, tr);
    }
}

bool solve()
{
    scanf("%d", &n);

    a.resize(n + 1, 2 * inf + 1);
    for(int i(1);i <= n;i++) {
        scanf("%d", &a[i]);
    }

    t.resize(4 * n, -2 * inf - 1);
    delt.resize(4 * n, 0);

    //puts("ok");

    buildRMQ();

    //puts("ok");

    for(int i(1);i <= n;i++) {
        //cout << i << '\n';
        int value = a[i], left, right;

        int bl, br, bm;
        bl = i, br = n;

        while(br - bl > 1) {
            bm = (bl + br) >> 1;
            if(get_min(i, bm) == value) bl = bm;
            else br = bm - 1;
        }

        if(get_min(i, br) == value) right = br;
        else right = bl;

        bl = 1, br = i;

        while(br - bl > 1) {
            bm = (bl + br) >> 1;
            if(get_min(bm, i) == value) br = bm;
            else bl = bm + 1;
        }

        if(get_min(bl, i) == value) left = bl;
        else left = br;

        update(1, 1, n, 1, right - left + 1, value);
    }

    show(1, 1, n);

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}