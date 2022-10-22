#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const mod = inf + 7;

inline int sum(int a, int b) { return (a + b) % mod; }
inline int raz(int a, int b) { return ((a - b) % mod + mod) % mod; }
inline int mul(int a, int b) { return (1ll * a * b) % mod; }

pii get_fib(ll x) {
    if(x == 0) return {0, 0};
    else if(x <= 2) return {1, 1};
    else if(x % 2) {
        pii q = get_fib(x - 1);
        return {q.second, sum(q.first, q.second)};
    }else {
        pii q = get_fib(x / 2);
        return {
                sum(mul(q.first, q.first), mul(q.second, q.second)),
                sum(mul(q.first, q.second), mul(q.second, sum(q.first, q.second)))
        };
    }
}

int const N = 100005;

int sum1[4 * N];
int sum2[4 * N];
int fib1[4 * N];
int fib2[4 * N];
int arr[N];

void up(int v) {
    sum1[v] = sum(sum1[v << 1], sum1[v << 1 | 1]);
    sum2[v] = sum(sum2[v << 1], sum2[v << 1 | 1]);
    fib1[v] = 1;
    fib2[v] = 0;
}

void build(int v, int tl, int tr) {
    if(tl == tr) {
        sum1[v] = get_fib(arr[tl]).second;
        sum2[v] = get_fib(arr[tl] + 1).second;
        fib1[v] = 1;
        fib2[v] = 0;
    }else {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
        up(v);
    }
}

inline void get_next_fib(int & F1, int & F2, int f1, int f2) {
    int res1, res2;
    res1 = sum(mul(F1, f1), mul(F2, f2));
    res2 = sum(mul(F1, f2), mul(F2, f1 + f2));
    F1 = res1;
    F2 = res2;
}

void push(int v) {
    if(!(fib1[v] == 1 & fib2[v] == 0)) {
        get_next_fib(fib1[v << 1], fib2[v << 1], fib1[v], fib2[v]);
        get_next_fib(sum1[v << 1], sum2[v << 1], fib1[v], fib2[v]);
        get_next_fib(fib1[v << 1 | 1], fib2[v << 1 | 1], fib1[v], fib2[v]);
        get_next_fib(sum1[v << 1 | 1], sum2[v << 1 | 1], fib1[v], fib2[v]);
        fib1[v] = 1;
        fib2[v] = 0;
    }
}

void inc(int v, int tl, int tr, int l, int r, int _fib1, int _fib2) {
    if(l <= tl && tr <= r) {
        get_next_fib(fib1[v], fib2[v], _fib1, _fib2);
        get_next_fib(sum1[v], sum2[v], _fib1, _fib2);
    }else {
        int tm = (tl + tr) >> 1;
        push(v);
        if(l <= tm) inc(v << 1, tl, tm, l, r, _fib1, _fib2);
        if(r > tm) inc(v << 1 | 1, tm + 1, tr, l, r, _fib1, _fib2);
        up(v);
    }
}

int get_sum(int v, int tl, int tr, int l, int r) {
    if(l <= tl && tr <= r) {
        return sum1[v];
    }else {
        int tm = (tl + tr) >> 1, res = 0;
        push(v);
        if(l <= tm) res = sum(res, get_sum(v << 1, tl, tm, l, r));
        if(r > tm) res = sum(res, get_sum(v << 1 | 1, tm + 1, tr, l, r));
        up(v);
        return res;
    }
}

bool solve() {

    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &arr[i]);
    }

    build(1, 1, n);

    for(int type, l, r, x, iter = 0;iter < m;iter++) {
        scanf("%d %d %d", &type, &l, &r);
        if(type == 1) {
            scanf("%d", &x);
            inc(1, 1, n, l, r, get_fib(x - 1).second, get_fib(x).second);
        }else {
            printf("%d\n", get_sum(1, 1, n, l, r));
        }
    }

    return true;
}

int main() {

#ifdef MY
    while(solve());
#else
    solve();
#endif

    return 0;
}