#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>
#include <functional>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;

using namespace std;

#ifndef LOCAL
#define cerr _cer
struct _cert
{
    template <typename T> _cert& operator << (T) { return *this; }
};
_cert _cer;
#endif

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}
const int MAXN = 110000;

ll sm[MAXN * 4][11];
ll dd[MAXN * 4][11];
ll a[MAXN][11];
int n, q;

void build(int v, int tl, int tr) {
    for (int j = 0; j < 10; ++j) {
        dd[v][j] = j;
    }
    if (tl + 1 == tr) {
        for (int j = 0; j < 10; ++j)
            sm[v][j] = a[tl][j];
        return;
    }
    int m = (tl + tr) >> 1;
    build(v * 2 + 1, tl, m);
    build(v * 2 + 2, m, tr);
    for (int j = 0; j < 10; ++j)
        sm[v][j] = sm[v * 2 + 1][j] + sm[v * 2 + 2][j];
}

ll tmp[11];
void push(int v) {
    for (int x = 2 * v + 1; x <= 2 * v + 2; ++x) {
        fill(tmp, tmp + 10, 0);
        for (int j = 0; j < 10; ++j)
            dd[x][j] = dd[v][dd[x][j]];
        for (int j = 0; j < 10; ++j)
            tmp[dd[v][j]] += sm[x][j];
        for (int j = 0; j < 10; ++j)
            sm[x][j] = tmp[j];
    }
    for (int j = 0; j < 10; ++j)
        dd[v][j] = j;
}

void add(int v, int tl, int tr, int l, int r, int x, int y) {
    if (r <= tl || tr <= l)
        return;
    if (l <= tl && tr <= r) {
        sm[v][y] += sm[v][x];
        sm[v][x] = 0;
        for (int j = 0; j < 10; ++j)
            if (dd[v][j] == x)
                dd[v][j] = y;
        return;
    }
    int m = (tl + tr) >> 1;
    push(v);
    add(v * 2 + 1, tl, m, l, r, x, y);
    add(v * 2 + 2, m, tr, l, r, x, y);
    for (int j = 0; j < 10; ++j)
        sm[v][j] = sm[v * 2 + 1][j] + sm[v * 2 + 2][j];
}

struct st {
    ll a[11];
    st() {
        memset(a, 0, sizeof(a));
    }
};


st get(int v, int tl, int tr, int l, int r) {
    if (r <= tl || tr <= l)
        return st();
    if (l <= tl && tr <= r) {
        st x;
        for (int j = 0; j < 10; ++j)
            x.a[j] = sm[v][j];
        return x;
    }
    push(v);
    int m = (tl + tr) >> 1;
    st x = get(v * 2 + 1, tl, m, l, r);
    st y = get(v * 2 + 2, m, tr, l, r);
    for (int j = 0; j < 10; ++j)
        x.a[j] += y.a[j];
    return x;
}


int main() {
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++i) {
        ll x;
        scanf("%lld", &x);
        ll now = 1;
        while (x) {
            int y = x % 10;
            a[i][y] += now;
            x /= 10;
            now *= 10;
        }
    }
    build(0, 0, n);
    for (int i = 0; i < q; ++i) {
        int t;
        int l, r, x, y;
        scanf("%d%d%d", &t, &l, &r);
        --l;
        if (t == 1) {
            scanf("%d%d", &x, &y);
            if (x != y)
                add(0, 0, n, l, r, x, y);
        }
        else {
            st ans = get(0, 0, n, l, r);
            ll sum = 0;
            for (int j = 0; j < 10; ++j)
                sum += ans.a[j] * j;
            printf("%lld\n", sum);
        }
    }
    return 0;
}