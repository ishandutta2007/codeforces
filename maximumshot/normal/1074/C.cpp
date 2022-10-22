#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1e18;

struct pt {
    int x, y;
};

const int N = 3e5 + 5;

int n;
pt p[N];

ll dist(pt p1, pt p2) {
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

int max_x = -1;
int min_x = -1;
int max_y = -1;
int min_y = -1;

ll solve() {

    auto nxt = [&](int i) -> int {
        return i < n ? i + 1 : 1;
    };

    auto calc = [&](int i, int j, int k) -> ll {
        return dist(p[i], p[j]) + dist(p[j], p[k]) + dist(p[k], p[i]);
    };

    auto NXT = [&](int i, int d) -> int {
        return (i - 1 + d) % n + 1;
    };

    auto get = [&](int i, int j) -> ll {
        int bl = 0;
        int br = j <= i ? i - j : n - j + i;
        int bm1, bm2;

        while(br - bl > 2) {
            bm1 = bl + (br - bl) / 3;
            bm2 = br - (br - bl) / 3;
            if(calc(i, j, NXT(j, bm1)) < calc(i, j, NXT(j, bm2))) {
                bl = bm1;
            }else {
                br = bm2;
            }
        }

        ll res = LLONG_MIN;

        for(int k = bl;k <= br;k++) {
            res = max(res, calc(i, j, NXT(j, k)));
        }

        return res;
    };

    ll res = LLONG_MIN;

    for(int i = 1;i <= n;i++) {

        if(p[min_x].x < p[i].x && p[i].x < p[max_x].x &&
                p[min_y].y < p[i].y && p[i].y < p[max_y].y) {
            continue;
        }

        int bl = 0;
        int br = n;
        int bm1, bm2;

        while(br - bl > 2) {
            bm1 = bl + (br - bl) / 3;
            bm2 = br - (br - bl) / 3;
            int j1 = NXT(i, bm1);
            int j2 = NXT(i, bm2);
            if(get(i, j1) < get(i, j2)) {
                bl = bm1;
            }else {
                br = bm2;
            }
        }

        for(int dj = bl;dj <= br;dj++) {
            int j = NXT(i, dj);
            res = max(res, get(i, j));
        }
    }

    return res;
}

void print(pt q) {
    cout << "(" << q.x << ", " << q.y << ")\n";
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        scanf("%d %d", &p[i].x, &p[i].y);

        if(max_x == -1 || p[max_x].x < p[i].x) max_x = i;
        if(max_y == -1 || p[max_y].y < p[i].y) max_y = i;
        if(min_x == -1 || p[min_x].x > p[i].x) min_x = i;
        if(min_y == -1 || p[min_y].y > p[i].y) min_y = i;
    }

    printf("%lld ", solve());

    ll res = 0;

    res += dist(p[max_x], p[min_y]);
    res += dist(p[min_y], p[min_x]);
    res += dist(p[min_x], p[max_y]);
    res += dist(p[max_y], p[max_x]);

//    print(p[min_x]);
//    print(p[max_x]);
//    print(p[min_y]);
//    print(p[max_y]);

    for(int i = 4;i <= n;i++) {
        printf("%lld ", res);
    }

    printf("\n");

    return 0;
}