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

const int inf = 1000000000ll;
const LL inf64 = 1ll * inf * inf;
const LL base = inf + 7;
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

int n;
vec< vec<int> > t;
vec< vec< pair<int, int> > > f;

void pushUp(int v) {
    t[v].clear();
    f[v].clear();
    int l = 0, r = 0;
    int ls = (int)t[v << 1].size(), rs = (int)t[v << 1 | 1].size();
    while(l < ls && r < rs) {
        if(t[v << 1][l] <= t[v << 1 | 1][r]) {
            t[v].push_back(t[v << 1][l]);
            f[v].push_back(mp(l, r - 1));
            l++;
        }else {
            t[v].push_back(t[v << 1 | 1][r]);
            f[v].push_back(mp(l - 1, r));
            r++;
        }
    }

    while(l < ls) {
        t[v].push_back(t[v << 1][l]);
        f[v].push_back(mp(l, r - 1));
        l++;
    }

    while(r < rs) {
        t[v].push_back(t[v << 1 | 1][r]);
        f[v].push_back(mp(l - 1, r));
        r++;
    }
}

void build(const vec<int> & a, int v, int tl, int tr) {
    if(tl == tr) {
        t[v].push_back(a[tl]);
    }else {
        int tm = (tl + tr) >> 1;
        build(a, v << 1, tl, tm);
        build(a, v << 1 | 1, tm + 1, tr);
        pushUp(v);
    }
}

void buildTree(const vec<int> & a) {
    n = (int)a.size() - 1;
    t.resize(4 * n);
    f.resize(4 * n);
    build(a, 1, 1, n);
}

int get(int v, int tl, int tr, int l, int r, int pos) {
    if(l <= tl && tr <= r) {
        return max(0, pos + 1);
    }else {
        int tm = (tl + tr) >> 1;
        int L = 0, R = 0;
        if(l <= tm) {
            int newpos = f[v][pos].first;
            if(newpos >= 0 && newpos < (int)t[v << 1].size()) {
                L = get(v << 1, tl, tm, l, r, newpos);
            }else if(newpos < 0) L = 0;
            else L = tm - tl + 1;
        }

        if(r > tm) {
            int newpos = f[v][pos].second;
            if(newpos >= 0 && newpos < (int)t[v << 1 | 1].size()) {
                R = get(v << 1 | 1, tm + 1, tr, l, r, newpos);
            }else if(newpos < 0) R = 0;
            else R = tr - tm;
        }
        return (L + R);
    }
}

int getCnt(int value, int l, int r) { // ? a[i] : (l <= i <= r && a[i] <= value)
    int bl, br, bm, bp;
    bl = 0, br = (int)t[1].size() - 1;
    while(br - bl > 1) {
        bm = (bl + br) >> 1;
        if(t[1][bm] <= value) bl = bm;
        else br = bm - 1;
    }

    if(t[1][br] <= value) bp = br;
    else if(t[1][bl] <= value) bp = bl;
    else return 0;

    return get(1, 1, n, l, r, bp);
}

int getCntBetweenVal(int valueL, int valueR, int l, int r) {
    return getCnt(valueR, l, r) - getCnt(valueL - 1, l, r);
}

bool solve() 
{
    int n;
    scanf("%d", &n);

    vec<int> a(n + 1);

    for(int i(1);i <= n;i++) {
        scanf("%d", &a[i]);
    }

    buildTree(a);

    for(int i(1);i <= n - 1;i++) {
        int ans = 0;
        for(int p(1), j(2);j <= n;j += i, p++) {
            int l = j, r = min(n, j + i - 1);
            ans += getCnt(a[p] - 1, l, r);
        }
        printf("%d ", ans);
    }
    
    puts("");

    return true;
}   

int main()  
{
    //while(solve());
    solve();

    return 0;
}