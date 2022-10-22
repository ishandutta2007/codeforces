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

const int N = 1e5 + 5;

int xmax, ymax, zmax, n, m, k;

enum TYPE {XZ, OPEN, CLOSED, UNKNOWN};

vec< pii > add[N];
vec< pair< pair< pii, pii >, int > > op[N], cl[N];

vec< int > fen[4 * N];
vec< int > lin_ar[N];
vec< int > ar[4 * N];

void merge(int v) {
    for(int i = 0, j = 0;i < (int)ar[v << 1].size() || j < (int)ar[v << 1 | 1].size();) {
        if(j == (int)ar[v << 1 | 1].size() || (i < (int)ar[v << 1].size() && ar[v << 1][i] < ar[v << 1 | 1][j])) {
            if(ar[v].empty() || ar[v << 1][i] > ar[v].back()) {
                ar[v].push_back(ar[v << 1][i]);
            }
            i++;
        }else {
            if(ar[v].empty() || ar[v << 1 | 1][j] > ar[v].back()) {
                ar[v].push_back(ar[v << 1 | 1][j]);
            }
            j++;
        }
    }
}

void build(int v, int tl, int tr) {
    if(tl == tr) {
        ar[v] = lin_ar[tl];
        sort(ALL(ar[v]));
        ar[v].resize(unique(ALL(ar[v])) - ar[v].begin());
    }else {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
        merge(v);
    }
    fen[v].resize(ar[v].size());
}

void change(int v, int tl, int tr, int px, int py) {
    int pos = lower_bound(ALL(ar[v]), py) - ar[v].begin();
    for(int cur = pos;cur < (int)fen[v].size();cur |= (cur + 1)) fen[v][cur]++;
    if(tl < tr) {
        int tm = (tl + tr) >> 1;
        if(px <= tm) {
            change(v << 1, tl, tm, px, py);
        }else {
            change(v << 1 | 1, tm + 1, tr, px, py);
        }
    }
}

int get(int v, int tl, int tr, int lx, int rx, int ly, int ry) {
    if(lx <= tl && tr <= rx) {
        int res = 0;
        int pr = upper_bound(ALL(ar[v]), ry) - ar[v].begin() - 1;
        int pl = lower_bound(ALL(ar[v]), ly) - ar[v].begin();
        if(pl <= pr) {
            for(int cur = pr;cur >= 0;cur = (cur & (cur + 1)) - 1) res += fen[v][cur];
            for(int cur = pl - 1;cur >= 0;cur = (cur & (cur + 1)) - 1) res -= fen[v][cur];
        }
        return res;
    }else {
        int tm = (tl + tr) >> 1;
        int res = 0;
        if(lx <= tm) {
            res += get(v << 1, tl, tm, lx, rx, ly, ry);
        }
        if(rx > tm) {
            res += get(v << 1 | 1, tm + 1, tr, lx, rx, ly, ry);
        }
        return res;
    }
}

TYPE res[N];
int cnt[N];
int lx, rx, ly, ry, lz, rz;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d %d", &xmax, &ymax, &zmax);

    lx = ly = lz = inf;
    rx = ry = rz = -inf;

    scanf("%d %d %d", &n, &m, &k);

    for(int i = 0;i < n;i++) {
        int xi, yi, zi;
        scanf("%d %d %d", &xi, &yi, &zi);
        lx = min(lx, xi);
        rx = max(rx, xi);
        ly = min(ly, yi);
        ry = max(ry, yi);
        lz = min(lz, zi);
        rz = max(rz, zi);
    }

    if(lx > rx || ly > ry || lz > rz) {
        puts("INCORRECT");
        return 0;
    }

    for(int i = 0;i < m;i++) {
        int xi, yi, zi;
        scanf("%d %d %d", &xi, &yi, &zi);
        if(lx <= xi && xi <= rx && ly <= yi && yi <= ry && lz <= zi && zi <= rz) {
            puts("INCORRECT");
            return 0;
        }
        add[xi].push_back({yi, zi});
        lin_ar[yi].push_back(zi);
    }

    build(1, 1, ymax);

    puts("CORRECT");

    for(int iter = 0;iter < k;iter++) {
        int xi, yi, zi;
        scanf("%d %d %d", &xi, &yi, &zi);
        if(lx <= xi && xi <= rx && ly <= yi && yi <= ry && lz <= zi && zi <= rz) {
            res[iter] = OPEN;
            continue;
        }

        int LX = min(lx, xi);
        int RX = max(rx, xi);
        int LY = min(ly, yi);
        int RY = max(ry, yi);
        int LZ = min(lz, zi);
        int RZ = max(rz, zi);

        op[LX].push_back({{{LY, RY}, {LZ, RZ}}, iter});
        cl[RX].push_back({{{LY, RY}, {LZ, RZ}}, iter});
    }

    for(int x = 1;x <= xmax;x++) {
        for(auto hlp : op[x]) {
            int lx, rx, ly, ry, id;
            tie(lx, rx) = hlp.first.first;
            tie(ly, ry) = hlp.first.second;
            id = hlp.second;
            int tmp = get(1, 1, ymax, lx, rx, ly, ry);
            cnt[id] -= tmp;
        }
        for(pii pt : add[x]) {
            int x0, y0;
            tie(x0, y0) = pt;
            change(1, 1, ymax, x0, y0);
        }
        for(auto hlp : cl[x]) {
            int lx, rx, ly, ry, id;
            tie(lx, rx) = hlp.first.first;
            tie(ly, ry) = hlp.first.second;
            id = hlp.second;
            int tmp = get(1, 1, ymax, lx, rx, ly, ry);
            cnt[id] += tmp;
        }
    }

    for(int iter = 0;iter < k;iter++) {
        if(res[iter] == XZ) {
            res[iter] = cnt[iter] > 0 ? CLOSED : UNKNOWN;
        }
        if(res[iter] == OPEN) {
            puts("OPEN");
        }else if(res[iter] == CLOSED) {
            puts("CLOSED");
        }else {
            puts("UNKNOWN");
        }
    }

    return 0;
}