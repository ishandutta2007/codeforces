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

const int N = 2e6 + 5;
const int mod = inf + 7;

int n, k;
int a[N];
pii t[4 * N];
int res = 0;

void build(int v, int tl, int tr) {
    if(tl == tr) {
        t[v] = make_pair(a[tl], -tl);
    }else {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
        t[v] = max(t[v << 1] , t[v << 1 | 1]);
    }
}

pii get(int v, int tl, int tr, int l, int r) {
    if(l <= tl && tr <= r) {
        return t[v];
    }else {
        pii res = make_pair(-inf, -inf);
        int tm = (tl + tr) >> 1;
        if(l <= tm) res = max(res, get(v << 1, tl, tm, l, r));
        if(r > tm) res = max(res, get(v << 1 | 1, tm + 1, tr, l, r));
        return res;
    }
}

void solve(int L, int R) {
    if(R - L + 1 < k) return;
    int p = -get(1, 1, n, L, R).second;
    if(p - L + 1 <= R - p + 1) {
        for(int l = L;l <= p;l++) {
            if(l + k - 1 > R) continue;
            int lt = 1;
            int rt = (R - l - k + 1) / (k - 1) + 1;
            if(l + k - 1 < p) {
                lt = max(lt, (p + 1 - l - k + k - 1 - 1) / (k - 1) + 1);
            }
            if(lt <= rt) {
                res += (1ll * a[p] * (rt - lt + 1)) % mod;
                if(res >= mod) res -= mod;
            }
        }
    }else {
        for(int r = p;r <= R;r++) {
            if(r - k + 1 < L) continue;
            int lt = 1;
            int rt = (r - L - k + 1) / (k - 1) + 1;
            if(r - k + 1 > p) {
                lt = max(lt, (r - p - k + 1 + k - 1 - 1) / (k - 1) + 1);
            }
            if(lt <= rt) {
                res += (1ll * a[p] * (rt - lt + 1)) % mod;
                if(res >= mod) res -= mod;
            }
        }
    }
    if(L < p) solve(L, p - 1);
    if(p < R) solve(p + 1, R);
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &k);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }

    build(1, 1, n);

    solve(1, n);

    printf("%d\n", res);

    return 0;
}