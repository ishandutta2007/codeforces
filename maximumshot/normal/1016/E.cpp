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

int sy, a, b;
int n;
pii seg[N];
int pref[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d %d", &sy, &a, &b);
    scanf("%d", &n);

    for(int i = 0;i < n;i++) {
        scanf("%d %d", &seg[i].first, &seg[i].second);
    }

    sort(seg, seg + n);

    for(int acc = 0, i = 0;i < n;i++) {
        acc += seg[i].second - seg[i].first;
        pref[i] = acc;
    }

    int q;

    scanf("%d", &q);

    for(int iter = 0;iter < q;iter++) {
        int x, y;

        scanf("%d %d", &x, &y);

        int bl, br, bm, le, ri;

        bl = -1;
        br = n - 1;

        while(br - bl > 1) {
            bm = (bl + br) >> 1;
            if(1ll * seg[bm].first * (y - sy) >= 1ll * x * (y - sy) + 1ll * (a - x) * y) {
                br = bm;
            }else {
                bl = bm;
            }
        }

        le = br + 1;

        bl = 0;
        br = n;

        while(br - bl > 1) {
            bm = (bl + br) >> 1;
            if(1ll * seg[bm].second * (y - sy) <= 1ll * x * (y - sy) + 1ll * (b - x) * y) {
                bl = bm;
            }else {
                br = bm;
            }
        }

        ri = bl - 1;

        le = max(le, 0);
        ri = min(ri, n - 1);

        ld len = 0;

        if(le <= ri) len = pref[ri] - (le > 0 ? pref[le - 1] : 0);

        set< int > ids = {le - 1, le - 2, ri + 1, ri + 2};

        double ax = x + 1.0 * (a - x) * y / (-sy + y);
        double bx = x + 1.0 * (b - x) * y / (-sy + y);

        for(int i : ids) {
            if(i < 0 || i >= n) continue;
            double LX = max(ax, 1.0 * seg[i].first);
            double RX = min(bx, 1.0 * seg[i].second);
            if(LX <= RX) {
                len += RX - LX;
            }
        }

        printf("%.10lf\n", double(len * (y - sy) / y));
    }

    return 0;
}