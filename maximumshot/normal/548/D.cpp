#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple 

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;
const ld pi = acos(-1.0);

const int LOG = 21;

struct SparseTable {
    int n;
    vec< int > _log, rmq[LOG];
    SparseTable() {
        n = 0;
    }
    SparseTable(const vec< int > & a) {
        n = (int)a.size();
        int q = 0;
        while((1 << q) <= n) q++; 
        _log.resize(n + 1);
        for(int i = n;i >= 1;i--) {
            if((1 << q) > i) q--;
            _log[i] = q;
        }
        for(int i = 0;i < LOG;i++) rmq[i].resize(n, inf + 10);
        rmq[0] = a;
        for(int k = 1;k < LOG;k++) {
            for(int i = 0;i + (1 << (k - 1)) < n;i++) {
                rmq[k][i] = min(
                    rmq[k - 1][i], 
                    rmq[k - 1][i + (1 << (k - 1))]
                );
            }
        }
    }
    int ask(int l, int r) {
        return min(
            rmq[_log[r - l + 1]][l],
            rmq[_log[r - l + 1]][r - (1 << _log[r - l + 1]) + 1]
        );
    }
};

struct SegmentTree {
    int n;
    vec< int > best;
    SegmentTree() {
        n = 0;
    }
    SegmentTree(int _n) {
        n = _n;
        best.resize(4 * n, -1);
    }
    void push(int v) {
        if(best[v] != -1) {
            best[v << 1] = max(best[v << 1], best[v]);
            best[v << 1 | 1] = max(best[v << 1 | 1], best[v]);
            best[v] = -1;
        }
    }
    void upd(int v, int tl, int tr, int l, int r, int value) {
        if(l <= tl && tr <= r) {
            best[v] = max(best[v], value);
        }else {
            int tm = (tl + tr) >> 1;
            push(v);
            if(l <= tm) upd(v << 1, tl, tm, l, r, value);
            if(r > tm) upd(v << 1 | 1, tm + 1, tr, l, r, value);
        }
    }
    void upd(int l, int r, int value) {
        upd(1, 1, n, l, r, value);
    }
    void pr(int v, int tl, int tr) {
        if(tl == tr) cout << best[v] << ' ';
        else {
            int tm = (tl + tr) >> 1;
            push(v);
            pr(v << 1, tl, tm);
            pr(v << 1 | 1, tm + 1, tr);
        }
    }
    void show() {
        pr(1, 1, n);
    }
};

bool solve()
{
    int n;

    cin >> n;

    vec< int > a(n);

    for(int i = 0;i < n;i++) cin >> a[i];

    SparseTable st(a);
    SegmentTree t(n);

    for(int i = 0;i < n;i++) {
        int bl, br, bm, ql, qr;

        bl = 0, br = i;

        while(br - bl > 1) {
            bm = (bl + br) >> 1;
            if(st.ask(bm, i) < a[i]) bl = bm + 1;
            else br = bm;
        }

        ql = (st.ask(bl, i) >= a[i]?bl : br);

        bl = i, br = n - 1;

        while(br - bl > 1) {
            bm = (bl + br) >> 1;
            if(st.ask(i, bm) < a[i]) br = bm - 1;
            else bl = bm;
        }

        qr = (st.ask(i, br) >= a[i]?br : bl);

        // [1 .. qr - ql + 1]

        t.upd(1, qr - ql + 1, a[i]);
    }

    t.show();

    cout << '\n';

    return true;
} 

int main() {
    
    //while(solve());
    solve();    

    return 0;
}