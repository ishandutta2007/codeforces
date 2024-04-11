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

const int N = 2e5 + 5;

int n, k;
int a[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &k);

    k = (1 << k) - 1;

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
        a[i] ^= a[i - 1];
    }

    for(int i = 1;i <= n;i++) {
        a[i] = min(a[i], a[i] ^ k);
    }

    unordered_map< int, int > cnt;

    for(int i = 1;i <= n;i++) {
        cnt[a[i]]++;
    }

    ll res = 0;

    for(pii pr : cnt) {
        int c1 = pr.second / 2;
        int c2 = pr.second - c1;
        if(!pr.first) c1++;

        res += 1ll * c1 * (c1 - 1) / 2;
        res += 1ll * c2 * (c2 - 1) / 2;
    }

    res = 1ll * n * (n + 1) / 2 - res;

    printf("%lld\n", res);

    return 0;
}