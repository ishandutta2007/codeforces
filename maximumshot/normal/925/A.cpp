#include <bits/stdc++.h>

using namespace std;

#define ALL(x) begin(x), end(x)
#define vec vector

typedef long long ll;
typedef unsigned int ui;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = ll(1e18);

const int N = 1e5 + 5;

int n, m, cl, ce, v;
vec< int > a, b;

int get(int x1, int y1, int x2, int y2) {
    int res = inf;

    if(x1 == x2) {
        return abs(y1 - y2);
    }

    {
        int j = lower_bound(ALL(a), y1) - a.begin();
        int lj = max(0, j - 20);
        int rj = min(cl - 1, j + 20);
        for(j = lj;j <= rj;j++) {
            int y0 = a[j];
            res = min(res, abs(y0 - y1) + abs(x1 - x2) + abs(y0 - y2));
        }
    }

    {
        int j = lower_bound(ALL(b), y1) - b.begin();
        int lj = max(0, j - 20);
        int rj = min(ce - 1, j + 20);
        for(j = lj;j <= rj;j++) {
            int y0 = b[j];
            int tmp = 0;
            tmp += abs(y1 - y0);
            tmp += abs(y0 - y2);
            tmp += (abs(x1 - x2) + v - 1) / v;
            res = min(res, tmp);
        }
    }

    return res;
}

void query() {
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    int res = min(
        get(x1, y1, x2, y2),
        get(x2, y2, x1, y1)
    );
    printf("%d\n", res);
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d %d %d %d", &n, &m, &cl, &ce, &v);

    for(int x, i = 0;i < cl;i++) {
        scanf("%d", &x);
        a.push_back(x);
    }

    for(int x, i = 0;i < ce;i++) {
        scanf("%d", &x);
        b.push_back(x);
    }

    int q;

    scanf("%d", &q);

    for(int iter = 0;iter < q;iter++) {
        query();
    }

    return 0;
}