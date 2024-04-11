#include<bits/stdc++.h>
using namespace std;
int const nax = 5e5 + 10;
const int mod = 998244353;
void plusle (int &a, int b) {
    if (( a += b) >= mod ) a -= mod ;
}
void minun (int &a, int b) {
    if ((a -= b) < 0) a += mod ;
}
int add (int a, int b) {
    return (( a += b ) >= mod ) ? a - mod  : a;
}
int sub (int a, int b) {
    return (( a -= b) < 0) ? a + mod : a;
}
int mul (int a, int b) {
    return 1LL * a * b % mod;
}
int power (int a, int b) {
    int res = 1;
    for (; b > 0 ; b >>= 1 , a = mul(a, a))
        if (b & 1) res = mul(res, a);
    return res ;
}

struct node_t {
    int all;
    int ex_first;
    int ex_last;
    int ex_both;
    int first;
    int last;

    node_t (int dig = 1) {
        all = dig + 1;
        ex_first = ex_last = 1;
        ex_both = 0;
        first = last = dig;
    }
};

int memo[50];

int get (int b) {
    if (b > 19 || b < 10) return 0;
    if (memo[b]) return memo[b];
    int res = 0;
    for (int a = 0 ; a <= 9 ; ++ a) {
        if (b - a < 10) ++ res;
    }

    return memo[b] = res;
}

inline node_t operator + (const node_t &x, const node_t &y) {
    node_t res;
    res.first = x.first;
    res.last = y.last;
    res.all = res.ex_first = res.ex_last = res.ex_both = 0;
    plusle(res.all, mul(x.all, y.all));
    plusle(res.all, mul(x.ex_last, mul(y.ex_first, get(x.last * 10 + y.first))));
    plusle(res.ex_first, mul(x.ex_first, y.all));
    plusle(res.ex_first, mul(x.ex_both, mul(y.ex_first, get(x.last * 10 + y.first))));
    plusle(res.ex_last, mul(x.all, y.ex_last));
    plusle(res.ex_last, mul(x.ex_last, mul(y.ex_both, get(x.last * 10 + y.first))));
    plusle(res.ex_both, mul(x.ex_first, y.ex_last));
    plusle(res.ex_both, mul(x.ex_both, mul(y.ex_both, get(x.last * 10 + y.first))));
    return res;
}

node_t sg[nax * 4];

inline void update (int v, int x, int y, int pos, int dig) {
    if (x == y) {
        sg[v] = node_t(dig);
    } else {
        int mid = x + y >> 1;
        if (pos <= mid) update(v << 1, x, mid, pos, dig);
        else update(v << 1 | 1, mid + 1, y, pos, dig);
        sg[v] = sg[v << 1] + sg[v << 1 | 1];
    }
}

int n, q;
char s[nax];
int a[nax];

int main () {
    scanf("%d %d", &n, &q);
    scanf("%s", s + 1);

    for (int i = 1 ; i <= n; ++ i) {
        a[i] = s[i] - '0';
        update(1, 1, n, i, a[i]);
    }

    for (int i = 1 ; i <= q ; ++ i) {
        int from, to;
        scanf("%d %d", &from, &to);
        a[from] = to;
        update(1, 1, n, from, to);
        printf("%d\n", sg[1].all);
    }
}
/*
    Rorona is not childish.
*/