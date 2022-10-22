#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 1e5 + 5;

struct Fen {
    int f[N];
    Fen() {
        for(int i = 0;i < N;i++) {
            f[i] = 0;
        }
    }
    void add(int pos, int val) {
        for(int cur = pos;cur < N;cur |= (cur + 1)) {
            f[cur] += val;
        }
    }
    int get(int pos) {
        int res = 0;
        for(int cur = pos;cur >= 0;cur = (cur & (cur + 1)) - 1) {
            res += f[cur];
        }
        return res;
    }
    int get(int l, int r) {
        if(l > r) return 0;
        return get(r) - get(l - 1);
    }
};

struct pt {
    int x, y;
    pt() : x(0), y(0) { }
    void read() {
        scanf("%d %d", &x, &y);
    }
    pt & operator = (pt const & other) {
        if(this == &other) return *this;
        x = other.x;
        y = other.y;
        return *this;
    }
};

int d, n, m;
pt p1[N], p2[N];

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &d);
    scanf("%d %d", &n, &m);

    for(int i = 1;i <= d;i++) {
        p1[i].read();
        p2[i].read();
        if(p1[i].x > p2[i].x || p1[i].y > p2[i].y) {
            swap(p1[i], p2[i]);
        }
    }

    int cl, cr, cu, cd;

    scanf("%d %d %d %d", &cl, &cr, &cu, &cd);

    Fen xl, xr, yl, yr;

    for(int i = 1;i <= d;i++) {
        xl.add(p1[i].x, 1);
        xr.add(p2[i].x, 1);
        yl.add(p1[i].y, 1);
        yr.add(p2[i].y, 1);
    }

    for(int i = 1;i <= d;i++) {

        xl.add(p1[i].x, -1);
        xr.add(p2[i].x, -1);
        yl.add(p1[i].y, -1);
        yr.add(p2[i].y, -1);

        int tl = xl.get(1, p2[i].x - 1);
        int tr = xr.get(p1[i].x + 1, n);
        int tu = yl.get(1, p2[i].y - 1);
        int td = yr.get(p1[i].y + 1, m);

        if(cl == tl && cr == tr && cu == tu && cd == td) {
            printf("%d\n", i);
            return 0;
        }

        xl.add(p1[i].x, 1);
        xr.add(p2[i].x, 1);
        yl.add(p1[i].y, 1);
        yr.add(p2[i].y, 1);
    }

    puts("-1");

    return 0;
}