#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 1e5 + 5;

int A, B, h, w, n;
int a[N];

ll gcd(ll x, ll y) {
    return x == 0 ? y : gcd(y % x, x);
}

bool check(int x) {
    set< ll > tot, nxt;
    tot.insert(1);
    for(int i = 1;i <= x;i++) {
        nxt = tot;
        for(ll val : tot) {
            if(val > A) continue;
            nxt.insert(val * a[i]);
        }
        tot = nxt;
    }
    ll mn = -1;
    for(ll val : tot) {
        if(val * (ll)h >= (ll)A) {
            mn = val;
            break;
        }
    }
    if(mn == -1) return false;
    ll cur = w;
    for(int i = 1;i <= x && cur < B;i++) {
        ll val = a[i];
        ll tmpg = gcd(val, mn);
        mn /= tmpg;
        val /= tmpg;
        cur *= val;
    }
    return cur >= B;
}

int solve() {
    int bl = 1;
    int br = min(n, 40);
    int bm;

    while(br - bl > 1) {
        bm = (bl + br) / 2;
        if(check(bm)) {
            br = bm;
        }else {
            bl = bm + 1;
        }
    }

    if(bl < br && check(bl)) {
        return bl;
    }else if(check(br)) {
        return br;
    }else {
        return inf;
    }
}

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d %d %d %d", &A, &B, &h, &w, &n);

    if(h >= A && w >= B || h >= B && w >= A) {
        puts("0");
        return 0;
    }

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }

    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);

    int res = solve();

    swap(h, w);

    res = min(res, solve());

    if(res == inf) {
        puts("-1");
    }else {
        printf("%d\n", res);
    }

    return 0;
}