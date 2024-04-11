#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 2e5 + 5;

int n, q;
int a[N];
ll pref[N];

ll delt[4 * N];
ll mx[4 * N];

void merge(int v) {
    mx[v] = max(mx[v << 1], mx[v << 1 | 1]);
}

void push(int v) {
    if(delt[v]) {
        delt[v << 1] += delt[v];
        delt[v << 1 | 1] += delt[v];
        mx[v << 1] += delt[v];
        mx[v << 1 | 1] += delt[v];
        delt[v] = 0;
    }
}

void build(int v, int tl, int tr) {
    if(tl == tr) {
        mx[v] = a[tl] - pref[tl - 1];
    }else {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
        merge(v);
    }
}

ll mem;

int get_next(int v, int tl, int tr, int pos) {
    if(pos > n) return n + 1;
    if(tl == tr) {
        if(mx[v] >= 0) {
            mem = mx[v];
            return tl;
        }else {
            return n + 1;
        }
    }
    int tm = (tl + tr) >> 1;
    push(v);
    if(pos <= tl) {
        if(mx[v] >= 0) {
            int res = get_next(v << 1, tl, tm, pos);
            if(res > n) res = get_next(v << 1 | 1, tm + 1, tr, pos);
            merge(v);
            return res;
        }else {
            merge(v);
            return n + 1;
        }
    }else {
        int res = n + 1;
        if(pos <= tm) res = get_next(v << 1, tl, tm, pos);
        if(n > tm && res > n) res = get_next(v << 1 | 1, tm + 1, tr, pos);
        merge(v);
        return res;
    }
}

void update(int v, int tl, int tr, int l, int r, ll x) {
    if(l <= tl && tr <= r) {
        delt[v] += x;
        mx[v] += x;
    }else {
        int tm = (tl + tr) >> 1;
        push(v);
        if(l <= tm) update(v << 1, tl, tm, l, r, x);
        if(r > tm) update(v << 1 | 1, tm + 1, tr, l, r, x);
        merge(v);
    }
}

void pu(int v, int tl, int tr) {
    if(tl < tr) {
        int tm = (tl + tr) >> 1;
        push(v);
        pu(v << 1, tl, tm);
        pu(v << 1 | 1, tm + 1, tr);
        merge(v);
    }else {
        cout << mx[v] << " ";
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &q);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
        pref[i] = pref[i - 1] + a[i];
    }

    build(1, 1, n);

    for(int pos, val, iter = 0;iter < q;iter++) {
        scanf("%d %d", &pos, &val);
        ll dx = val - a[pos];
        a[pos] = val;
        update(1, 1, n, pos, pos, dx);
        if(pos < n) update(1, 1, n, pos + 1, n, -dx);
        if(!a[1]) {
            printf("1\n");
            continue;
        }
        int i = 1;
        while(i <= n) {
            mem = 1;
            i = get_next(1, 1, n, i + 1);
            if(!mem) break;
        }
        if(i <= n) {
            printf("%d\n", i);
        }else {
            puts("-1");
        }
    }

    return 0;
}