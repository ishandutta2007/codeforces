#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 2e5 + 5;

int n, L;
ll a[3 * N], b[3 * N];

bool check(int d) {
    int tl = 1, tr = 3 * n;
    for(int i = n + 1;i <= n + n;i++) {
        int bl = lower_bound(a + 1, a + 3 * n, b[i] - d) - a;
        int br = upper_bound(a + 1, a + 3 * n, b[i] + d) - a - 1;
        bl -= (i - n - 1);
        br -= (i - n - 1);
        if(bl > tl) tl = bl;
        if(br < tr) tr = br;
    }
    return tl <= tr;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &L);

    for(int x, i = 1;i <= n;i++) {
        scanf("%d", &x);
        a[i] = x;
    }

    for(int x, i = 1;i <= n;i++) {
        scanf("%d", &x);
        b[i] = x;
    }

    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);

    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= 2;j++) {
            a[i + n * j] = a[i] + 1ll * L * j;
            b[i + n * j] = b[i] + 1ll * L * j;
        }
    }

    int bl = -1;
    int br = L;
    int bm;

    while(br - bl > 1) {
        bm = (bl + br) >> 1;
        check(bm) ? br = bm : bl = bm;
    }

    printf("%d\n", br);

    return 0;
}