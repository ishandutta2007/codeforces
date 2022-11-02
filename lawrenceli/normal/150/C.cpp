#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

struct data {
    double a, b, c, d; //a - best, b - right, c - left, d - sum
    data() {}
    data(double a, double b, double c, double d) : a(a), b(b), c(c), d(d) {}
};

data prop(data d1, data d2) {
    return data(max(max(d1.a, d2.a), d1.b + d2.c),
                max(d2.b, d2.d + d1.b),
                max(d1.c, d1.d + d2.c),
                d1.d + d2.d);
}

const int MAXN = 1<<18;
const double INF = 1e15;

int n, m, c, x[MAXN], p[MAXN];
double stuff[MAXN];
data tree[2*MAXN];

void init(int cur, int lt, int rt) {
    if (lt + 1 == rt) {
        double d = max(stuff[lt], 0.);
        tree[cur] = data(d, d, d, stuff[lt]);
    } else {
        int mid = (lt + rt) / 2;
        init(2*cur, lt, mid);
        init(2*cur + 1, mid, rt);
        tree[cur] = prop(tree[2*cur], tree[2*cur + 1]);
    }
}

data query(int cur, int lt, int rt, int ql, int qr) {
    if (rt <= ql || lt >= qr) return data(-INF, -INF, -INF, 0);
    else if (lt >= ql && rt <= qr) return tree[cur];
    else {
        int mid = (lt + rt) / 2;
        return prop(query(2*cur, lt, mid, ql, qr), query(2*cur + 1, mid, rt, ql, qr));
    }
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d %d %d", &n, &m, &c);
    for (int i=0; i<n; i++) scanf("%d", &x[i]);
    for (int i=0; i<n-1; i++) scanf("%d", &p[i]);
    for (int i=0; i<n-1; i++) stuff[i] = double(x[i+1] - x[i]) / 2 - double(c) * p[i] / 100;
    init(1, 0, n-1);
    double ans = 0;
    for (int i=0; i<m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        ans += query(1, 0, n-1, a-1, b-1).a;
    }
    printf("%lf\n", ans);
    return 0;
}