#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 1000005;

int n, k;
int fen[N];
//
void add(int pos) {
    for(int cur = pos;cur <= n;cur |= (cur + 1)) {
        fen[cur]++;
    }
}

int get(int pos) {
    int res = 0;
    for(int cur = pos;cur > 0;cur = (cur & (cur + 1)) - 1) {
        res += fen[cur];
    }
    return res;
}

int get(int l, int r) {
    l = max(l, 1);
    r = min(r, n);
    if(l > r) return 0;
    return get(r) - get(l - 1);
}

int main() {

    scanf("%d %d", &n, &k);

    if(2 * k > n) {
        k = n - k;
    }

    ll res = 1;

    for(int l, r, cnt, v = 1, iter = 1;iter <= n;iter++) {
        // v + 1 .. v + k - 1
        l = v + 1;
        r = v + k - 1;
        if(r <= n) {
            cnt = get(l, r);
        }else {
            cnt = get(l, n) + get(1, r - n);
        }
        res += cnt + 1;
        printf("%I64d ", res);
        int nxt = v + k <= n ? v + k : v + k - n;
        add(v);
        add(nxt);
        v = nxt;
    }

    printf("\n");

    return 0;
}